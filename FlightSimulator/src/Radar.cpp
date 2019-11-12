/*
 * Radar.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */

#include "Radar.h"
//#include "Flight.h"
#include "TestCase.h"

/*
 * Function which reads the information of planes from the TestCase file
 * and converts it into a list of flights
 * for easier manipulations
 * */
Flight* getAirplanesFromTestFile(){

	const int totalNumberOfData = sizeof(TestCase::airplane_schedule);
	const int TOTAL_NUMBER_INFO_PER_PLANE = 7;
	Flight* currentFlight = nullptr;
	Flight* headOfList = nullptr;
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
			case POSITION_Z : positionz = TestCase::airplane_schedule[i]; break;
			case START_TIME : {

			enterTime = TestCase::airplane_schedule[i];
			Flight* newFlight = new Flight (id, speedx, speedy,speedz,positionx,positiony,positionz,enterTime);

			//First Time
			if (currentFlight == nullptr){
				// assigns the head of List to keep track of it
				headOfList = newFlight;
				currentFlight = newFlight;
			}else {
				//Create the chain in the list
				currentFlight->setNextFlight(newFlight);

				//Moves to the last element
				currentFlight = newFlight;
			}

			}
			break;
			}
		}

	return headOfList;
}

// Assume the Air Space is 10, should probably change that value
Flight* scanAirZone(Flight currentHead){
	const int airFieldDistance = 10;
	Flight* currentFlight = nullptr;
	Flight* headOfPlaneInAirSpace = nullptr;
	Flight* currentFlightInAirSpace = nullptr;


		currentFlight = &currentHead;

		while (currentFlight->getNextFlight() != nullptr){

			if(currentFlight->getFlightDistance() <= airFieldDistance){

				if(headOfPlaneInAirSpace != nullptr){
					//Gets the head of the list
					headOfPlaneInAirSpace = currentFlight;
					currentFlightInAirSpace = currentFlight;
				}
				//Adds the flight in the airspace to the list of Flight in AirSpace
				currentFlightInAirSpace->setNextFlight(currentFlight);
				currentFlightInAirSpace = currentFlight;
			}

			currentFlight = currentFlight->getNextFlight();
		}

return headOfPlaneInAirSpace;
Radar::getThreadRunnable(void* context){
	return ((Radar *)context)->hello();
}

Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

