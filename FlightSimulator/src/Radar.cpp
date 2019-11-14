/*
 * Radar.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */

#include "Radar.h"
//#include "Flight.h"
#include "TestCase.h"


// Assume the Air Space is 10, should probably change that value
void Radar::scanAirZone(std::vector<Flight*> flights){
	std::vector<Flight*> flightsInAirSpace;

	for (Flight* currentFlight : flights){
		if (currentFlight->getFlightDistance() <= Radar::RADAR_AREA){

		}
	}

}

void Radar::getThreadRunnable(void* context){
//	((Radar *)context)->hello(); //Add fuction to run here
}

Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

