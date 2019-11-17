/*
 * Radar.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */

#include "Radar.h"
#include "TestCase.h"
#include "AirplaneDB.h"


/*
 * Function which scans the AIR FIELD, checks if there are any hits
 * IF not, the air planes are put in a not hit list
 *
 */

Radar::Radar(AirplaneDB *airplaneDB){
	this->airplaneDB = airplaneDB;
}
void Radar::scanAirZone(std::vector<Flight*> flights){
	flightsInAirSpace.clear();
	lostFlights.clear();

	for (Flight* currentFlight : flights){
		if (currentFlight->getFlightDistance() <= Radar::RADAR_AREA) flightsInAirSpace.push_back(currentFlight);
		else lostFlights.push_back(currentFlight);
	}

	//TODO IF lostFlights.size != 0, notify operator!!!!
}


void Radar::executeRadar(){
	//TODO populate
}

Radar::Radar(){
	//Empty
}

/*
 * Function which returns the planes in the airSpace flying lower than the min flying altitude
 */
std::vector<Flight*> Radar::getPlanesFlyingTooLow(){
	std::vector<Flight*> planesFlyingTooLow;

	for (Flight* flight : flightsInAirSpace){
		if(flight->getPositionZ() <= Radar::MIN_FLYING_ALTITUDE){
			planesFlyingTooLow.push_back(flight);
		}
	}

	return planesFlyingTooLow;
}



/*
 * Function which will be used if the operator wants to scan from a particular airspace
 * By airspace, we mean another point in time and space other than (0,0,0)
 *
 */
std::vector<Flight*> Radar::scanFromAPoint (int x, int y, int z, std::vector<Flight*> flights){
	std::vector<Flight*> flightsCloseToAPoint;

	for (Flight* currentFlight: flights){
		if (currentFlight->calculatateFlightDistanceFromAPoint(x,y,z) <= Radar::RADAR_AREA) flightsCloseToAPoint.push_back(currentFlight);
	}
	return flightsCloseToAPoint;
}


/*
 * Function which will write the status of the airfield
 * AKA the status of flights present in the airfield at a specific point in time in a file
 * The file has the name of the current date and time
 *
 */
void Radar::writeLogOfPlaneInAirSpace(){
	std::time_t currentTime = std::time(nullptr);
	std::stringstream currentTimeInString;
	currentTimeInString << currentTime;
	std::string logFileName = currentTimeInString.str();

	std::fstream airSpaceLog;
	airSpaceLog.open(logFileName);

	for (Flight* flight: flightsInAirSpace){
		airSpaceLog << flight->getCurrentFlightStatus();
	}
	airSpaceLog.close();
}


void Radar::getThreadRunnable(void* context){
//	((Radar *)context)->hello(); //Add function to run here
}

Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

