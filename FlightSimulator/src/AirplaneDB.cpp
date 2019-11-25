/*
 * AirplaneDB.cpp
 *
 *  Created on: Nov 13, 2019
 *      Author: etienne
 */
#include "AirplaneDB.h"
#include "TestCase.h"
#include <iostream>

AirplaneDB::AirplaneDB(){
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

	pthread_mutex_init(&this->mutex, &attr);
	init();
}

AirplaneDB::~AirplaneDB(){
	for(auto &plane: this->flights){
		delete(plane);
	}
}

std::vector<Flight*> AirplaneDB::getPlanes(){
	return flights;
}

void AirplaneDB::lockDB(){
	std::cout<<"LOCK MUTEX"<<std::endl;
	pthread_mutex_lock( &mutex);
}

void AirplaneDB::unlockDB(){
	std::cout<<"UNLOCK MUTEX"<<std::endl;
	pthread_mutex_unlock( &mutex);
}

/*
 * Function which reads the information of planes from the TestCase file
 * and converts it into a list of flights
 * for easier manipulations initializes the database of flights
 *
 */
void AirplaneDB::init(){

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
				flights.push_back(newFlight);
				}
				break;
			}
	}

	sortThePlanes();
}


/*
 * Function which is used to sort the planes in the database by their entry time
 * a struct is used to deal with the custom objects
 *
 */
void AirplaneDB::sortThePlanes(){

	if (flights.size() <= 1) return;

	struct{
		bool operator ()(Flight* a, Flight* b) const {
			return a->getEntryTime() < b-> getEntryTime();
		}
	} flightSorting;

	std::sort(flights.begin(),flights.end(), flightSorting);
}


/*
 * Function which will run every 2 seconds, to update the position of all the planes.
 */
void AirplaneDB::updateFlightsPosition(){
	//LAMBDA EXPRESSION
	auto updatePlanePosition = [](Flight* n) {n->updateFlightPosition();};
	std::for_each(flights.begin(),flights.end(), updatePlanePosition);
}
