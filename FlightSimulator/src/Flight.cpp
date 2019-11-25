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
	calculateFlightDistanceFromOriginPoint();
	this -> id == -1 ? this -> unidentifiedFlight = true : this->unidentifiedFlight = false;
}

int Flight::getEntryTime(){
	return this->entryTime;
}

int Flight::getPositionX(){
	return (inHoldingPattern) ? this->inHoldingPatternPosition.x : this-> position_x;
}

int Flight::getPositionY(){
	return (inHoldingPattern) ? this->inHoldingPatternPosition.y : this-> position_y;
}

int Flight::getPositionZ(){
	return (inHoldingPattern) ? this->inHoldingPatternPosition.z : this-> position_z;
}

int Flight::getSpeedX(){
	return (inHoldingPattern) ? this->inHoldingPatternPosition.x : this->speed_x;
}

int Flight::getSpeedY(){
	return (inHoldingPattern) ? this->inHoldingPatternPosition.y : this->speed_y;
}

int Flight::getSpeedZ(){
	return (inHoldingPattern) ? this->inHoldingPatternPosition.z : this->speed_z;
}

void Flight::setSpeedX(int speedX) {
    speed_x = speedX;
}

void Flight::setSpeedY(int speedY) {
    speed_y = speedY;
}

void Flight::setSpeedX(int speedZ) {
    speed_z = speedZ;
}

int Flight::getId(){
	return this->id;
}


std::string Flight::getIdString(){
	return (this->unidentifiedFlight) ? "UNKNOWN" : std::to_string(this->id);
}

std::string Flight:: getHoldingPatternStatus(){
//	if (inHoldingPattern) return "YES";
//	else return "NO";
	return (inHoldingPattern)? "YES": "NO";
}


/*
 * This function calculates a linear distance between the plane and the radar
 * The radar is always assumed to be at position (0,0,0)
 * The formula used to calculate distance is sqrt( (x2-x1)^2 + (y2-x1)^2 + (z2-z1)^2)
 *
 */
void Flight::calculateFlightDistanceFromOriginPoint(){
	if(inHoldingPattern){
		int subTotal = (this->inHoldingPatternPosition.x * this->inHoldingPatternPosition.x) + (this->inHoldingPatternPosition.y * this->inHoldingPatternPosition.y) + (this->inHoldingPatternPosition.z * this->inHoldingPatternPosition.z);
		this->distance = (int) sqrt(subTotal);
	}else{
		int subTotal = (position_x * position_x) + (position_y * position_y) + (position_z * position_z);
		this->distance = (int) sqrt(subTotal);
	}
}


int Flight::calculateDistanceOnXYPlane(int x, int y){
	int calculatedDistance;

	if (inHoldingPattern){
		int diffInX = x - this->inHoldingPatternPosition.x;
		int diffInY = y - this->inHoldingPatternPosition.y;
		int totalSquared = (diffInX * diffInX) + (diffInY * diffInY);
		calculatedDistance = (int) sqrt(totalSquared);
	}else {
		int diffInX = x - this->position_x;
		int diffInY = y - this->position_y;
		int totalSquared = (diffInX * diffInX) + (diffInY * diffInY);
		calculatedDistance = (int) sqrt(totalSquared);

	}

	return calculatedDistance;
}

int Flight::calculateAltitudeBetweenPlanes(int z){
	if(inHoldingPattern){
		return (z < this->inHoldingPatternPosition.z)? this->inHoldingPatternPosition.z - z: z - this->inHoldingPatternPosition.z;

	}else {
		return (z < this->position_z)? this->position_z  - z: z - this->position_z;
	}
}

/*
 * Function used to calculate how far the aircraft is from a point in time and space
 * It uses the appropriate coordinated depending on whether the aircraft is in holding pattern or not
 *
 */
int Flight::calculatateFlightDistanceFromAPoint(int x, int y, int z){
	if(inHoldingPattern){
		int diff_x = x - this->inHoldingPatternPosition.x;
		int diff_y = y - this->inHoldingPatternPosition.y;
		int diff_z = z - this->inHoldingPatternPosition.z;
		int totalSquared = (diff_x * diff_x) + (diff_y * diff_y) + (diff_z*diff_z);
		return (int) sqrt(totalSquared);
	}else{
		int diff_x = x - this->position_x;
		int diff_y = y - this->position_y;
		int diff_z = z - this->position_z;
		int totalSquared = (diff_x * diff_x) + (diff_y * diff_y) + (diff_z*diff_z);
		return (int) sqrt(totalSquared);
	}
}


int Flight::getFlightDistance(){
	if (!inHoldingPattern) return distance;
	else{
		int subTotal = (this->inHoldingPatternPosition.x * this->inHoldingPatternPosition.x) + (this->inHoldingPatternPosition.y * this->inHoldingPatternPosition.y) + (this->inHoldingPatternPosition.z * this->inHoldingPatternPosition.z);
		return (int) sqrt(subTotal);
	}
}

/*
 * Function which updates a plane's position at every time interval
 * Assuming that next position is the addition the distance traveled (speed * time) within the time interval
 * When plane should stay in a holding pattern, the plane will follow a circle
 *
 */
void Flight::updateFlightPosition(){

	// inHoldingPattern follows this formula (x - h)^2 + (y - k)^2 = r^2
	if (inHoldingPattern){
		int relativeRadiusForward = this->position_x + this->inHoldingPatternPosition.radius;
		int relativeRadiusBackwards = this->position_x - this->inHoldingPatternPosition.radius;

		if(this->inHoldingPatternPosition.goingForward){

			if(this->inHoldingPatternPosition.x + (this->timeInterval* this->speed_x) >= relativeRadiusForward){
				this->inHoldingPatternPosition.goingForward = false;
			}else{
				this->inHoldingPatternPosition.x += this->inHoldingPatternPosition.x + (this->timeInterval* this->speed_x);
				int difference = this->inHoldingPatternPosition.x - this->position_x;
				int sumOfPowers = pow(this->inHoldingPatternPosition.radius,2) + pow(difference,2);
				this->inHoldingPatternPosition.y = sqrt(sumOfPowers) + position_y;
			}

		}else{

			if(this->inHoldingPatternPosition.x - (this->timeInterval* this->speed_x) <= relativeRadiusBackwards){
				this->inHoldingPatternPosition.goingForward = true;
			}else{
				this->inHoldingPatternPosition.x -= this->inHoldingPatternPosition.x - (this->timeInterval* this->speed_x);
				int difference = this->inHoldingPatternPosition.x - this->position_x;
				int sumOfPowers = pow(this->inHoldingPatternPosition.radius,2) + pow(difference,2);
				this->inHoldingPatternPosition.y = sqrt(sumOfPowers) + position_y;
			}

		}

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
	this->inHoldingPatternPosition.x = this->position_x;
	this->inHoldingPatternPosition.y = this->position_y;
	this->inHoldingPatternPosition.z = this->position_z;
	this -> inHoldingPattern = true;
}

void Flight::leaveHoldingPattern(){
	this->position_x = this->inHoldingPatternPosition.x;
	this->position_y = this->inHoldingPatternPosition.y;
	this->position_z = this->inHoldingPatternPosition.z;
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
	if(!inHoldingPattern){
		this -> position_x = position_x;
		this -> position_y = position_y;
	}else {
		this->inHoldingPatternPosition.x = position_x;
		this->inHoldingPatternPosition.y = position_y;
	}
}

void Flight::changeFlightElevation(int position_z){
	if(inHoldingPattern){
		this->inHoldingPatternPosition.z = position_z;
	}else{
		this-> position_z = position_z;
	}
}

/*
 * Operator wants to know the projected of a plane after an amount of time
 * Returning this position in a string in the format (x1, x2, x3)
 *
 */
std::string Flight::projectFlightPosition(int time){
	int projectedPosition_x, projectedPosition_y, projectedPosition_z;

	if(inHoldingPattern){
		projectedPosition_x = this -> inHoldingPatternPosition.x + (time * this -> speed_x);
		projectedPosition_y = this -> inHoldingPatternPosition.y + (time * this -> speed_y);
		projectedPosition_z = this -> inHoldingPatternPosition.z + (time * this -> speed_z);
	}else{
		projectedPosition_x = this -> position_x + (time * this -> speed_x);
		projectedPosition_y = this -> position_y + (time * this -> speed_y);
		projectedPosition_z = this -> position_y + (time * this -> speed_z);
	}

	std::string projectedPosition = "(" + std::to_string(projectedPosition_x) + ", " + std::to_string(projectedPosition_y) + ", " + std::to_string(projectedPosition_z) + ')';

	return projectedPosition;
}

/*
 * Function which will be used to save a log of each airplane
 * It returns a string of the status of the Flight so the string can be easily printed in a file
 *
 */
std::string Flight::getCurrentFlightStatus(){
	std::string record;
	if (inHoldingPattern){
		record = "Flight ID: " + (unidentifiedFlight)? "UNKNOWN" : std::to_string(this->id) + ", ";
		record += "Position (x, y, z): (" + std::to_string(this->inHoldingPatternPosition.x) + ", " + std::to_string(this->inHoldingPatternPosition.y) + ", " +std::to_string(this->inHoldingPatternPosition.z) + ", ";
		record += "Speed (x, y, z): (" + std::to_string(this -> speed_x) + ", "+ std::to_string(this -> speed_y) + ", "+ std::to_string(this -> speed_z) + ", ";
		record += "In Holding Pattern: Yes";

	}else{
		record = "Flight ID: " + (unidentifiedFlight)? "UNKNOWN" : std::to_string(this->id) + ", ";
		record += "Position (x, y, z): (" + std::to_string(this->position_x) + ", " + std::to_string(this->position_y) + ", " +std::to_string(this->position_z) + ", ";
		record += "Speed (x, y, z): (" + std::to_string(this -> speed_x) + ", "+ std::to_string(this -> speed_y) + ", "+ std::to_string(this -> speed_z) + ", ";
		record += "In Holding Pattern: No";
	}

	return record;
}


Flight::~Flight() {
	// TODO Auto-generated destructor stub
}

