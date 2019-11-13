/*
 * Radar.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */
#include "Flight.h"

Flight* getAirplanesFromTestFile();
Flight* scanAirZone(Flight); // TODO Implement
void writeLogOfPlanes(); // TODO Implement

class Radar {
public:
	Radar();
	void getAirplanes();
	virtual ~Radar();
	void* getThreadRunnable(void*);
	void executeRadar();

};
