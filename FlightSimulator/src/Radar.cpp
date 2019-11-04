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
/*
 * Function which reads the information of planes from the TestCase file
 * and converts it into an array of flights
 * for easier manipulations
 * */
Radar::getAirplanes(){
	const int totalNumberOfFlights = TestCase::airplane_schedule.size() / 8;
	const int TOTAL_NUMBER_INFO_PER_PLANE = 7;
	int airplaneSchedules[] = TestCase::airplane_schedule;
	const int ID = 0;
	const int SPEED_X = 1;
	const int SPEED_Y = 2;
	const int SPEED_Z = 3;
	const int POSITION_X = 4;
	const int POSITION_Y = 5;
	const int POSITION_Z = 6;
	const int START_TIME = 7;
	int id, speedx, speedy,speedz, positionx,positiony, positionz, enterTime;



	for (int i, flight = 0; i < airplaneSchedule.size(); i++){

		switch (i % TOTAL_NUMBER_INFO_PER_PLANE){
			case ID: id = airplaneSchedule[i]; break;
			case SPEED_X : speedx = airplaneSchedule[i]; break;
			case SPEED_Y : speedy = airplaneSchedule[i]; break;
			case SPEED_Z : speedz = airplaneSchedule[i]; break;
			case POSITION_X : positionx = airplaneSchedule[i]; break;
			case POSITION_Y : positiony = airplaneSchedule[i]; break;
			case POSITION_Z : positionz = airplaneSchedule[i]; break;
			case START_TIME : {
			enterTime = airplaneSchedule[i];
			airplanes[flight++] = new Flight (id, speedx, speedy,speedz,positionx,positiony,positionz,enterTime);
				}break;
			}
		}

	}



Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

