/*
 * Flight.h
 *
 *  Created on: Nov 3, 2019
 *      Author: Deano
 */
#include <string>

#ifndef SRC_FLIGHT_H_
#define SRC_FLIGHT_H_

class Flight {
public:
	const static int FLIGHT_DIRECTION_RIGHT = 0;
	const static int FLIGHT_DIRECTION_LEFT = 1;

	const int timeInterval = 2;

	Flight();
	Flight(int, int,int,int,int,int,int,int);

	void setNextFlight(Flight *);
	Flight* getNextFlight();

	void updateFlightPosition(); //TODO Implement inHoldingPattern
	void calculateFlightDistance();
	int getFlightDistance();

	void increaseSpeedBy(int);
	void decreaseSpeedBy(int);
	void increaseAltitudeBy(int);
	void decreaseAltitudeBy(int);
	void changeDirection();
	void enterHoldingPattern();
	void leaveHoldingPattern();

	void changeFlightPosition(int, int);
	void changeFlightElevation (int);
	std::string projectFlightPosition (int);
	std::string getCurrentFlightStatus();

	virtual ~Flight();

private:
	Flight* nextFlightInTheList;
	bool inHoldingPattern = false;
	int id, speed_x, speed_y, speed_z, position_x, position_y, position_z, entryTime, distance;
};

#endif /* SRC_FLIGHT_H_ */
