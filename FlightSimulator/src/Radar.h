/*
 * Radar.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Deano
 */

#ifndef RADAR_H_
#define RADAR_H_

class Radar {
public:
	Radar();
	void getAirplanes();
	virtual ~Radar();

private:
	int airplanes[];
};

#endif /* RADAR_H_ */
