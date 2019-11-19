/*
 * History.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: etienne
 */

#include "History.h"

History::History(AirplaneDB* db){
	this->airplaneDB = db;
}

void History::saveState(){
	std::time_t currentTime = std::time(nullptr);
	std::stringstream currentTimeInString;
	currentTimeInString << currentTime;
	std::string logFileName = uri + currentTimeInString.str();

	std::fstream airSpaceLog;
	airSpaceLog.open(logFileName);

	for (Flight* flight: flightsInAirSpace){
		airSpaceLog << flight->getCurrentFlightStatus() << std::endl;
	}
	airSpaceLog.close();

	std::cout << "***History Generated***" << std::endl;
}


