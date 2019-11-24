/*
 * History.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: etienne
 */

#include "History.h"

History::History(Radar *radar) {
    this->radar = radar;
}

/*
 * Function which will write the status of the airfield
 * AKA the status of flights present in the airfield at a specific point in time in a file
 * The file has the name of the current date and time
 *
 */
void History::saveState() {

    std::string logFileName = "Airspace_Log";
    std::ofstream myfile;
    myfile.open(logFileName + ".txt", std::ostream::out | std::ofstream::app);

    if (myfile.is_open()) {
        myfile << "\n\n\n~~~SAVING NEW AIRSPACE STATE~~~" << std::endl;

        if (radar->flightsInAirSpace.size() == 0) {
            myfile << "\nNo Flights in AirSpace ( ͡° ͜ʖ ͡°) ¯\\_(ツ)_/¯" << std::endl;
        } else {
            for (Flight *flight: radar->flightsInAirSpace) {
                myfile << flight->getCurrentFlightStatus() << std::endl;
            }
        }
    } else std::cout << "\n CANNOT OPEN FILE TO WRITE LOG" << std::endl;
    myfile.close();

    std::cout << "***History Generated***" << std::endl;
}



