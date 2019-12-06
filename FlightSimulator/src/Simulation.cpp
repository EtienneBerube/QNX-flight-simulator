/*
 * Simulation.cpp
 *
 *  Created on: Nov 24, 2019
 *      Author: etienne
 */

#include "Simulation.h"

Simulation::Simulation(AirplaneDB* airplaneDB){
	this->airplaneDB = airplaneDB;
	init();
}

<<<<<<< HEAD
imulation::Simulation(AirplaneDB* airplaneDB, int numberOfPlanes){
    this->airplaneDB = airplaneDB;
    init(numberOfPlanes);
}


void Simulation::init(int numberOfPlanes){
    for (int index = 0; index < numberOfPlanes; index++){
          this->nextFlights.push_back (new Flight(index +1, 100, 100, 100, 1000, 1000, 1000, 0));
      }
}


=======
>>>>>>> Operator_kevyn
void Simulation::init(){
	const int totalNumberOfData = sizeof(TestCase::airplane_schedule)/sizeof(TestCase::airplane_schedule[0]);
		const int TOTAL_NUMBER_INFO_PER_PLANE = 8;
		const int ID = 0;
		const int SPEED_X = 1;
		const int SPEED_Y = 2;
		const int SPEED_Z = 3;
		const int POSITION_X = 4;
		const int POSITION_Y = 5;
		const int POSITION_Z = 6;
		const int START_TIME = 7;
		int id, speedx, speedy,speedz, positionx,positiony, positionz, enterTime;

		for (int i = 0; i < totalNumberOfData ; i++){

				switch (i % TOTAL_NUMBER_INFO_PER_PLANE){
					case ID: id = TestCase::airplane_schedule[i]; break;
					case SPEED_X : speedx = TestCase::airplane_schedule[i]; break;
					case SPEED_Y : speedy = TestCase::airplane_schedule[i]; break;
					case SPEED_Z : speedz = TestCase::airplane_schedule[i]; break;
					case POSITION_X : positionx = TestCase::airplane_schedule[i]; break;
					case POSITION_Y : positiony = TestCase::airplane_schedule[i]; break;
					case POSITION_Z : positionz = TestCase::airplane_schedule[i]+ 15000; break;
					case START_TIME : {
					enterTime = TestCase::airplane_schedule[i];
					Flight* newFlight = new Flight (id, speedx, speedy,speedz,positionx,positiony,positionz,enterTime);

					nextFlights.push(newFlight);
					}
					break;
				}
		}
}

void Simulation::run(){
	airplaneDB->lockDB();
	counter += 1;

	//Get new planes

	while(nextFlights.size() != 0 && nextFlights.front()->getEntryTime() <= counter){
		std::vector<Flight*>* planes = airplaneDB->getPlanes();
		Flight* next = nextFlights.front();
		planes->push_back(next);
		nextFlights.pop();
	}

<<<<<<< HEAD
=======
	//Update
//	std::cout<<"BEfore adding"<<std::endl;

>>>>>>> Operator_kevyn
	for(Flight* &flight: *(airplaneDB->getPlanes())){
		flight->updateFlightPosition();
	}

	airplaneDB->unlockDB();
<<<<<<< HEAD
=======


>>>>>>> Operator_kevyn
}


