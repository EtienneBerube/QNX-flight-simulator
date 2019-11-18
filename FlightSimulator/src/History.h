/*
 * History.h
 *
 *  Created on: Nov 18, 2019
 *      Author: etienne
 */

#ifndef SRC_HISTORY_H_
#define SRC_HISTORY_H_

#include "AirplaneDB.h"

#include <iostream>
#include <fstream>


class History{
	public:
		History(AirplaneDB*);
		void saveState();
	private:
		string uri = "logs/";
		AirplaneDB* airplaneDB;
};

#endif /* SRC_HISTORY_H_ */
