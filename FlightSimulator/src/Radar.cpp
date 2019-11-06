/*
 * Radar.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */

#include "Radar.h"

Radar::Radar() {
	// TODO Auto-generated constructor stub
airplanes = new int [TestCase::airplane_schedule.size()];

}

Radar::getAirplanes(){
	const int totalNumberOfFlights = TestCase::airplane_schedule.size() / 8;
	const int NUMBER_OF_VAR = 7;
	int airplaneSchedules = TestCase::airplane_schedule;

	for (int flight = 0; flight < totalNumberOfFlights; flight++){

		for (int i = 0; i < airplaneSchedule.size(); i++){

		}

	}
}


Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

