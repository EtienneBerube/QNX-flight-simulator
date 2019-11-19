//
// Created by kbelebinda on 11/18/2019.
//

#include <utility>
#include <vector>
#include <queue>
#include "Operator.h"

CommandCode Operator::parseCommand(string userInput) {
    string userInputCopy;
    userInputCopy = std::move(userInput);
    string delimiter = "|";

    size_t pos = userInputCopy.find(delimiter);

    string commands;
    vector<string> args;

    commands = userInputCopy.substr(0, pos);

    userInputCopy.erase(0, pos + delimiter.length());

    string delimiter_args = " ";
    string substring;

    while ((pos = userInputCopy.find(delimiter_args)) != string::npos) {
        substring = userInputCopy.substr(0, pos);

        args.push_back(substring);

        userInputCopy.erase(0, pos + delimiter.length());
    }

    args.push_back(userInputCopy);

    CommandCode commandCode = hashIt(commands);

    addCommandToQueue(commandCode, args);

    return commandCode;
}

void Operator::addCommandToQueue(CommandCode command, const vector<string>& args) {
    map<CommandCode, vector<string>> commandArgumentsPair;

    commandArgumentsPair.insert(pair<CommandCode, vector<string >>(command, args));

    commandQueue.push(commandArgumentsPair);
}

queue<map<CommandCode, vector<string>>> Operator::getCommandQueue() {
    return commandQueue;
}

CommandCode Operator::hashIt(const string &command) {
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
