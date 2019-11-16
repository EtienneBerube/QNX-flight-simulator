/*
 * Radar.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */
#include "Flight.h"
#include <vector>


class Radar {
public:
	Radar();
	virtual ~Radar();
	void getThreadRunnable(void*);
	void executeRadar();
	void scanAirZone(std::vector<Flight*>); // TODO Implement
	void writeLogOfPlanes(); // TODO Implement
const int static RADAR_AREA = 100000;

};
