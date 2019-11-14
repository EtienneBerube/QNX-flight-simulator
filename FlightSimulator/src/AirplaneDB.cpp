/*
 * AirplaneDB.cpp
 *
 *  Created on: Nov 13, 2019
 *      Author: etienne
 */
#include "AirplaneDB.h"


std::vector<Flight> AirplaneDB::getPlanes(){
	return flights;
}

void AirplaneDB::lockDB(){
	pthread_mutex_lock( &mutex);
}

void AirplaneDB::unlockDB(){
	pthread_mutex_unlock( &mutex);
}

/*
 * Function which reads the information of planes from the TestCase file
 * and converts it into a list of flights
 * for easier manipulations initializes the database of flights
 * */
void AirplaneDB::init(){

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
				flights.push_back(newFlight);
				}
				break;
			}
	}
}
