/*
 * Flight.h
 *
 *  Created on: Nov 3, 2019
 *      Author: Deano
 */

#ifndef SRC_FLIGHT_H_
#define SRC_FLIGHT_H_

class Flight {
public:
	Flight();
	virtual ~Flight();

private:
	int id;
	int speed_x;
	int speed_y;
	int speed_z;
	int position_x;
	int position_y;
	int position_z;
	int entryTime;
};

#endif /* SRC_FLIGHT_H_ */
