/*
 * Radar.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */
#include "Flight.h"
#include "AirplaneDB.h"
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>


class Radar {
public:
	Radar();
	Radar(AirplaneDB*);
	virtual ~Radar();
	void getThreadRunnable(void*);
	void executeRadar();
	void scanAirZone(std::vector<Flight*>); // TODO Add other features
	std::vector<Flight*> scanFromAPoint(int, int, int, std::vector<Flight*>);
	void writeLogOfPlaneInAirSpace();
	void displayPlanesAboutToCrash();

	std::vector<Flight*> getPlanesFlyingTooLow();



	std::vector<Flight*> flightsInAirSpace;
	std::vector<Flight*> lostFlights;
	const int static RADAR_AREA = 100000;
	const int static MIN_FLYING_ALTITUDE = 15000;
	const int static MIN_HORIZONTAL_DISTANCE_BETWEEN_PLANES = 3;
	const int static MIN_VERTICAL_DISTANCE_BETWEEN_PLANES = 1000;

private:
	AirplaneDB* airplaneDB;
};
