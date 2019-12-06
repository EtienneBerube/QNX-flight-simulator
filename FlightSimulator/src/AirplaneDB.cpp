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

std::vector<Flight*>* AirplaneDB::getPlanes(){
	return &flights;
}

void AirplaneDB::lockDB(){
	pthread_mutex_lock( &mutex);
}

int AirplaneDB::getIndex(int id){
	for(unsigned int i = 0 ; i < flights.size(); i++){
		if(flights[i]->getId() == id){
			return i;
		}
	}

	return -1;
}

void AirplaneDB::unlockDB(){
	pthread_mutex_unlock( &mutex);
}

/*
 * Function which reads the information of planes from the TestCase file
 * and converts it into a list of flights
 * for easier manipulations initializes the database of flights
 *
 */
void AirplaneDB::init(){

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

void AirplaneDB::createNumberOfPlanes(int numberOfPlanes){
    this->flights.clear();
    
    for (int index = 0; index < numberOfPlanes; index++){
        this->flights.push_back (new Flight(index +1, 100, 100, 100, 1000, 1000, 1000, 0));
    }
}
