/*
 * AirplaneDB.cpp
 *
 *  Created on: Nov 13, 2019
 *      Author: etienne
 */
#include "AirplaneDB.h"

AirplaneDB::getPlanes(){
		return flights;
}

AirplaneDB::lockDB(){
	pthread_mutex_lock( &mutex);
}

AirplaneDB::unlockDB(){
	pthread_mutex_unlock( &mutex);
}
