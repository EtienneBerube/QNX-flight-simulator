/*
 * History.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: etienne
 */

#include "History.h"

History::History(Radar* radar){
	this->radar = radar;
}

/*
 * Function which will write the status of the airfield
 * AKA the status of flights present in the airfield at a specific point in time in a file
 * The file has the name of the current date and time
 *
 */
void History::saveState(){
	std::time_t currentTime = std::time(nullptr);
	std::stringstream currentTimeInString;
	currentTimeInString << currentTime;
	std::string logFileName = currentTimeInString.str();

	std::ofstream myfile;
    myfile.open (logFileName + ".txt", std::ostream::out);

	  if (myfile.is_open()){
		for (Flight* flight: radar->flightsInAirSpace){
//			airSpaceLog << flight->getCurrentFlightStatus() << std::endl;
			myfile << flight->getCurrentFlightStatus() << std::endl;
		}
	}else std::cout << "\n CANNOT OPEN FILE TO WRITE LOG" << std::endl;
	myfile.close();

	std::cout << "***History Generated***" << std::endl;
}



