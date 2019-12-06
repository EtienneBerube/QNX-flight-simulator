/*
 * AirplaneDB.h
 *
 *  Created on: Nov 13, 2019
 *      Author: etienne
 */

#ifndef SRC_AIRPLANEDB_H_
#define SRC_AIRPLANEDB_H_

#include <vector>
#include "Flight.h"
#include "TestCase.h"
#include <pthread.h>


class AirplaneDB{
public:
	AirplaneDB();
	~AirplaneDB();
	void init();
	void lockDB();
	void unlockDB();
	void updateFlightsPosition();
	int getIndex(int id);
	std::vector<Flight*>* getPlanes();
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
<<<<<<< HEAD
    void createNumberOfPlanes(int);
=======

>>>>>>> Operator_kevyn
private:
	std::vector<Flight*> flights;
	void sortThePlanes();


};



#endif /* SRC_AIRPLANEDB_H_ */
