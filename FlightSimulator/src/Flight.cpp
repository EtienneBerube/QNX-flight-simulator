/*
 * Flight.cpp
 *
 *  Created on: Nov 3, 2019
 *      Author: Deano
 */

#include "Flight.h"
#include "math.h"
#include <string>

Flight::Flight() {

}


// Main Constructor
Flight::Flight(int id, int speedInX, int speedInY, int speedInZ, int positionInX, int positionInY, int positionInZ, int startTime){
	this->id = id;
	this->speed_x = speedInX;
	this->speed_y = speedInY;
	this->speed_z = speedInZ;
	this->position_x = positionInX;
	this->position_y = positionInY;
	this->position_z = positionInZ;
	this->entryTime = startTime;
	this-> nextFlightInTheList = nullptr;
	calculateFlightDistance();
}

//Assigns the next flight in the list
void Flight::setNextFlight(Flight * nextFlight){
	this -> nextFlightInTheList = nextFlight;
}

//Getting the next flight
Flight* Flight::getNextFlight(){
	return this -> nextFlightInTheList;
}

/*
 * This function calculates a linear distance between the plane and the radar
 * The radar is always assumed to be at position (0,0,0)
 * The formula used to calculate distance is sqrt( (x2-x1)^2 + (y2-x1)^2 + (z2-z1)^2)
 *
 */
void Flight::calculateFlightDistance(){
	int subTotal = (position_x * position_x) + (position_y * position_y) + (position_z * position_z);
	distance = (int) sqrt(subTotal);
}


int Flight::getFlightDistance(){
	return distance;
}

/*
 * Function which updates a plane's position at every time interval
 * Assuming that next position is the addition the distance traveled (speed * time) within the time interval
 * When plane should stay in a holding pattern, the plane will follow a circle
 *
 */
void Flight::updateFlightPosition(){

	//TODO Implement inHoldingPattern
	if (inHoldingPattern){

	}else {
		this  -> position_x += this-> timeInterval * this -> speed_x;
		this  -> position_y += this-> timeInterval * this -> speed_y;
		this  -> position_z += this-> timeInterval * this -> speed_z;
	}
}

/*
 * Increases the velocity in every direction by n amount if and only if the speed in the direction is not 0
 * Meaning that if the plane is going in a straight line, it says in the straight line
 * speed_x, speed_y and speed_z will change because speed_z is not just related to the altitude allegedly
 *
 */
void Flight::increaseSpeedBy(int amount){

	if (this -> speed_x != 0){
		this -> speed_x += amount;
	}

	if (this -> speed_y != 0){
		this -> speed_y += amount;
	}

	if (this -> speed_z != 0){
		this -> speed_z += amount;
	}
}

/*
 * Decreases the velocity in every direction by n amount if and only if the speed in the direction is not 0
 * Meaning that if the plane is going in a straight line, it says in the straight line
 * speed_x, speed_y and speed_z will change because speed_z is not just related to the altitude allegedly
 *
 */
void Flight::decreaseSpeedBy(int amount){

	if (this -> speed_x != 0){
		this -> speed_x -= amount;
	}

	if (this -> speed_y != 0){
		this -> speed_y -= amount;
	}

	if (this -> speed_z != 0){
		this -> speed_z -= amount;
	}
}

/*
 * As Required, increases the altitude (position_z) of the plane
 * by an amount times a 1000 feet
 *
 */
void Flight::increaseAltitudeBy(int amount){
	int desiredChangeOfAltitude = amount * 1000;
	position_z += desiredChangeOfAltitude;
}

/*
 * As Required, decreases the altitude (position_z) of the plane
 * by an amount times a 1000 feet
 *
 */
void Flight::decreaseAltitudeBy(int amount){
	int desiredChangeOfAltitude = amount * 1000;
	this -> position_z -= desiredChangeOfAltitude;
}

void Flight::enterHoldingPattern(){
	this -> inHoldingPattern = true;
}

void Flight::leaveHoldingPattern(){
	this -> inHoldingPattern = false;
}

/*
 * Assuming that if a plane wants to turn, it'll turn in the y direction
 * Assuming that the direction of the plane is dictated speed_y
 * Thus changing direction is changing the sign of speed_y
 */
void Flight::changeDirection(){
	const int changeOfDirection = -1;
	speed_y *= changeOfDirection;
}

void Flight::changeFlightPosition(int position_x, int position_y){
	this -> position_x = position_x;
	this -> position_y = position_y;
}

void Flight::changeFlightElevation(int position_z){
	this-> position_z = position_z;
}

/*
 * Operator wants to know the projected of a plane after an amount of time
 * Returning this position in a string in the format (x1, x2, x3)
 *
 */
std::string Flight::projectFlightPosition(int time){
	int projectedPosition_x = this -> position_x + (time * this -> speed_x);
	int projectedPosition_y = this -> position_y + (time * this -> speed_y);
	int projectedPosition_z = this -> position_y + (time * this -> speed_z);

	std::string projectedPosition = "(" + std::to_string(projectedPosition_x) + ", " + std::to_string(projectedPosition_y) + ", " + std::to_string(projectedPosition_z) + ')';

	return projectedPosition;
}

/*
 * Function which will be used to save a log of each airplane
 * It returns a string of the status of the Flight so the string can be easily printed in a file
 *
 */
std::string Flight::getCurrentFlightStatus(){
	std::string record = "Flight ID: " + std::to_string(this->id) + ", ";
	record += "Position (x, y, z): (" + std::to_string(this->position_x) + ", " + std::to_string(this->position_y) + ", " +std::to_string(this->position_z) + ", ";
	record += "Speed (x, y, z): (" + std::to_string(this -> speed_x) + ", "+ std::to_string(this -> speed_y) + ", "+ std::to_string(this -> speed_z) + ", ";
	record += "In Holding Pattern: " + inHoldingPattern ? "Yes" : "No";

	return record;
}


Flight::~Flight() {
	// TODO Auto-generated destructor stub
}
