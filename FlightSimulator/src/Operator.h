//
// Created by kbelebinda on 11/18/2019.
//

#ifndef QNX_FLIGHT_SIMULATOR_OPERATOR_H
#define QNX_FLIGHT_SIMULATOR_OPERATOR_H

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::queue;
using std::pair;
using std::to_string;


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

//    Broadcoast
//  Enter/Leave Holding
    reportAircraftIdentification,
};


class Operator {
public:
    CommandCode parseCommand(string);

    static CommandCode hashIt(string const &);

//    Command queue that holds a map of commandCode and its list of arguments
    queue<map<CommandCode, vector<string>>> getCommandQueue();

    void addCommandToQueue(CommandCode, const vector<string>&);

    void executeCommand(CommandCode, const vector<string>&);

private:
    queue<map<CommandCode, vector<string>>> commandQueue;
};


#endif //QNX_FLIGHT_SIMULATOR_OPERATOR_H
