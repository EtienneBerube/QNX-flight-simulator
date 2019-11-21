/*
 * Radar.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */

#ifndef SRC_RADAR_H_
#define SRC_RADAR_H_

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
	void scanAirZone(std::vector<Flight*>);
	std::vector<Flight*> scanFromAPoint(int, int, int, std::vector<Flight*>);
	void displayPlanesAboutToCrash();
	void displayPlanesFlyingTooLow();
	void displayPlanesAboutToCrash(std::vector<Flight*>); // TODO : To remove, this was used for debugging purposes only


	std::vector<Flight*> flightsInAirSpace;
	std::vector<Flight*> lostFlights;
	const int static RADAR_WIDTH = 100 * 5280;
	const int static RADAR_LENGTH = 100 * 5280;
	const int static MIN_RADAR_HEIGHT = 15000;
	const int static MAX_RADAR_HEIGHT = 40000;
	const int static MIN_FLYING_ALTITUDE = 15000;
	const int static MIN_HORIZONTAL_DISTANCE_BETWEEN_PLANES = 3 * 5280;
	const int static MIN_VERTICAL_DISTANCE_BETWEEN_PLANES = 1000;

private:
	AirplaneDB* airplaneDB;
};

#endif
