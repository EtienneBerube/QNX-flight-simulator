/*
 * Simulation.h
 *
 *  Created on: Nov 24, 2019
 *      Author: etienne
 */

#ifndef SRC_SIMULATION_H_
#define SRC_SIMULATION_H_

#include "AirplaneDB.h"
#include <iostream>
#include <queue>

using std::queue;
class Simulation{
public:
	Simulation(AirplaneDB*);
	void init();
	void run();

private:
	std::queue<Flight*> nextFlights;
	long counter = 0;
	AirplaneDB * airplaneDB;
};



#endif /* SRC_SIMULATION_H_ */
