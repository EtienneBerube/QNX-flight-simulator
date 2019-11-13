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

class AirplaneDB{
public:
	AirplaneDB(std::vector<Flight>*);
	std::vector<FLight>* getPlanes();
private:
	std::vector<Flight>* flights;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
};



#endif /* SRC_AIRPLANEDB_H_ */
