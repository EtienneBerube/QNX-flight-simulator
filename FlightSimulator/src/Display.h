/*
 * Display.h
 *
 *  Created on: Nov 12, 2019
 *      Author: etienne
 */

#ifndef SRC_DISPLAY_H_
#define SRC_DISPLAY_H_

#include "AirplaneDB.h"

class Display{
public:

	Display(AirplaneDB*); 

	void displayCurrentState();
private:
	AirplaneDB *planeDB;
};




#endif /* SRC_DISPLAY_H_ */
