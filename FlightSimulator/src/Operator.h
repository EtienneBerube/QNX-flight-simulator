//
// Created by kbelebinda on 11/18/2019.
//

#ifndef QNX_FLIGHT_SIMULATOR_OPERATOR_H
#define QNX_FLIGHT_SIMULATOR_OPERATOR_H

#include <iostream>
using std::cout;
using std::unordered_map;
using std::string;


class Operator {
public:
    void executeCommand(string);
    string parseCommand(string);
    commandCode hashIt(string const&);

private:
    enum commandCode;
};







#endif //QNX_FLIGHT_SIMULATOR_OPERATOR_H
