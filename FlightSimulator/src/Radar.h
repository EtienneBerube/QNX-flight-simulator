/*
 * Radar.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */
#include "Flight.h"
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>


class Radar {
public:
	Radar();
	virtual ~Radar();
	void getThreadRunnable(void*);
	void executeRadar();
	void scanAirZone(std::vector<Flight*>); // TODO Implement
	std::vector<Flight*> scanFromAPoint(int, int, int, std::vector<Flight*>);
	void writeLogOfPlaneInAirSpace(); // TODO Implement



	std::vector<Flight*> flightsInAirSpace;
	std::vector<Flight*> lostFlights;
	const int static RADAR_AREA = 100000;

};
