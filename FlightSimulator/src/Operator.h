//
// Created by kbelebinda on 11/18/2019.
//

#ifndef QNX_FLIGHT_SIMULATOR_OPERATOR_H
#define QNX_FLIGHT_SIMULATOR_OPERATOR_H

#include "Flight.h"
#include "AirplaneDB.h"

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::queue;
using std::pair;
using std::to_string;
using std::cin;


enum CommandCode {
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
	nuke,

//    Broadcoast
//  Enter/Leave Holding
    reportAircraftIdentification,
};


class Operator {
public:
    CommandCode parseCommand(string, AirplaneDB &airplaneDb);

    void executeCommand(CommandCode, const vector <string> &args, AirplaneDB &airplaneDb);

    static CommandCode hashIt(string const &);

//    Command queue that holds a map of commandCode and its list of arguments
    queue<map<CommandCode, vector<string>>> getCommandQueue();

    void addCommandToQueue(CommandCode, const vector<string>&);

    void executeCommand(CommandCode, const vector<string>&);

    void run(AirplaneDB &);

private:
    queue<map<CommandCode, vector<string>>> commandQueue;
};


#endif //QNX_FLIGHT_SIMULATOR_OPERATOR_H
