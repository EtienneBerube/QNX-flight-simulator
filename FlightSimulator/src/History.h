/*
 * History.h
 *
 *  Created on: Nov 18, 2019
 *      Author: etienne
 */

#ifndef SRC_HISTORY_H_
#define SRC_HISTORY_H_

#include "AirplaneDB.h"
#include "Radar.h"
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


class History{
	public:
		History(Radar*);
		void saveState();
	private:
		std::string uri = "logs/";
		Radar* radar;
};

#endif /* SRC_HISTORY_H_ */
