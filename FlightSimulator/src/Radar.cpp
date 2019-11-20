/*
 * Radar.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */

#include "Radar.h"
#include "TestCase.h"
#include "AirplaneDB.h"
#include <iostream>


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
		if (currentFlight->getPositionX() <= Radar::RADAR_WIDTH && currentFlight->getPositionY() <= Radar::RADAR_LENGTH && currentFlight->getPositionZ() >= Radar::MIN_RADAR_HEIGHT && currentFlight->getPositionZ() <= Radar::MAX_RADAR_HEIGHT) {
			flightsInAirSpace.push_back(currentFlight);

		}		else lostFlights.push_back(currentFlight);
	}

	//TODO IF lostFlights.size != 0, notify operator!!!!
}


void Radar::executeRadar(){
	std::cout << "***Executing radar***" << std::endl;
	std::cout << &this->airplaneDB->mutex << std::endl;


	this->airplaneDB->lockDB();

	this->scanAirZone(this->airplaneDB->getPlanes());

	this->airplaneDB->unlockDB();

	this->displayPlanesAboutToCrash();
	this->displayPlanesFlyingTooLow();

}

Radar::Radar(){
	//Empty
}

/*
 * Function which displays the planes in the airSpace flying lower than the min flying altitude
 */
void Radar::displayPlanesFlyingTooLow(){
	std::vector<Flight*> planesFlyingTooLow;

	for (Flight* flight : flightsInAirSpace){
		if(flight->getPositionZ() <= Radar::MIN_FLYING_ALTITUDE){
			std::cout << "Plane with ID: " << flight->getIdString() << " is flying too low."<< std::endl;
		}
	}

}



/*
 * Function which will be used if the operator wants to scan from a particular airspace
 * By airspace, we mean another point in time and space other than (0,0,0)
 *
 */
std::vector<Flight*> Radar::scanFromAPoint (int x, int y, int z, std::vector<Flight*> flights){
	std::vector<Flight*> flightsCloseToAPoint;

	for (Flight* currentFlight: flights){
		if (currentFlight->scanFlightFromAPoint(x,y,z)) flightsCloseToAPoint.push_back(currentFlight);
	}
	return flightsCloseToAPoint;
}



void Radar::displayPlanesAboutToCrash(){

	for (Flight* firstFlight : flightsInAirSpace){
		int xPositionFirstFlight = firstFlight->getPositionX();
		int yPositionFirstFlight = firstFlight->getPositionY();
		int altitudeFirstFlight = firstFlight->getPositionZ();

		for (Flight* secondFlight: flightsInAirSpace){
			if(firstFlight == secondFlight) continue;
			else if(secondFlight->calculateDistanceOnXYPlane(xPositionFirstFlight, yPositionFirstFlight) <= Radar::MIN_HORIZONTAL_DISTANCE_BETWEEN_PLANES){
				if(secondFlight->calculateAltitudeBetweenPlanes(altitudeFirstFlight) <= Radar::MIN_VERTICAL_DISTANCE_BETWEEN_PLANES ){
					std::cout << "\nPlane with id " << firstFlight->getIdString() << " will crash with plane id "<< secondFlight->getIdString() << std::endl;
				}
			}

		}
 }
}




Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

