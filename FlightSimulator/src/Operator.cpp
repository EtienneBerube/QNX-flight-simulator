//
// Created by kbelebinda on 11/18/2019.
//

#include "Operator.h"


void Operator::executeCommand(commandCode command, string[] args) {

    switch (command) {
        case changeAltitude:
            break;
        case increaseSpeed:
            break;
        case decreaseSpeed:
            break;
        case changeDirection:
            break;
        case enterHoldingPattern:
            break;
        case leaveHoldingPattern:
            break;
        case reportCurrentPositionVelocity:
            break;

        case addAircraft:
            break;
        case deleteAircraft:
            break;
        case setPosition:
            break;
        case setElevation:
            break;
        case setVelocity:
            break;

//        TODO: Broadcast-specific enums?
        case reportAircraftIdentification:
            break;
    }


}

string Operator::parseCommand(string) {
    string command = "";
    string[] args = new string[]
}


enum command_code {
//    Aircraft specific command
    changeAltitude,
    increaseSpeed,
    decreaseSpeed,
    changeDirection,
    enterHoldingPattern,
    leaveHoldingPattern,
    reportCurrentPositionVelocity,
//    Internal system
    addAircraft,
    deleteAircraft,
    setPosition,
    setElevation,
    setVelocity,

//    Broadcoast
//  Enter/Leave Holding
    reportAircraftIdentification,
};


command_code Operator::hashIt(const string &command) {
//    TODO: Lower command string before the comparison
    if (command == "change altitude") {
        return changeAltitude;
    } else if (command == "increase speed") {
        return increaseSpeed;
    } else if (command == "decrease speed") {
        return decreaseSpeed;
    } else if (command == "change direction") {
        return changeDirection;
    } else if (command == "enter holding pattern") {
        return enterHoldingPattern;
    } else if (command == "leave holding pattern") {
        return leaveHoldingPattern;
    } else if (command == "report current position velocity") {
        return reportCurrentPositionVelocity;
    } else if (command == "add aircraft") {
        return addAircraft;
    } else if (command == "delete aircraft") {
        return deleteAircraft;
    } else if (command == "set position") {
        return setPosition;
    } else if (command == "set elevation") {
        return setElevation;
    } else if (command == "set velocity") {
        return setVelocity;
    } else if (command == "report aircraft identification") {
        return reportAircraftIdentification;
    }

}
