#include <iostream>
#include "Operator.h"

void printCommandArgsPair(CommandCode commandCode, vector<string> args);

string getCommandString(CommandCode commandCode);

using namespace std;

//int main() {
//    auto* anOperator = new Operator();
//    queue<map<CommandCode, vector<string>>> commandQueue;
//    map<CommandCode, vector<string>>::iterator itr;
//
//    string commandString = "change altitude|24 434 34";
//
//    CommandCode commandCode = anOperator->parseCommand(commandString);
//
//    commandQueue = anOperator->getCommandQueue();
//
//    map<CommandCode, vector<string>> item = commandQueue.front();
//
//    vector<string> args;
//
//    for (itr = item.begin(); itr != item.end(); ++itr) {
//        printCommandArgsPair(itr->first, itr->second);
//    }
//    cout << endl;
//
//    return 0;
//}

void printCommandArgsPair(CommandCode commandCode, vector<string> args){
    string command = getCommandString(commandCode);
    string pair = "Command issued: ";

    pair += command;
    pair += "\n";
    pair += "List of arguments: ";

    for (const string& arg : args) {
        pair += arg;
        pair += " ";
    }

    cout << pair << endl;
}

string getCommandString(CommandCode commandCode) {
    switch (commandCode) {
        case changeAltitude:
            return "change altitude";
        case increaseSpeed:
            return "increase speed";
        case decreaseSpeed:
            return "decrease speed";
        case changeDirection:
            return "change direction";
        case enterHoldingPattern:
            return "enter holding pattern";
        case leaveHoldingPattern:
            return "leave holding pattern";
        case reportCurrentPositionVelocity:
            return "report current position velocity";
        case addAircraft:
            return "add aircraft";
        case deleteAircraft:
            return "delete aircraft";
        case setPosition:
            return "set position";
        case setElevation:
            return "set elevation";
        case setVelocity:
            return "set velocity";
        case reportAircraftIdentification:
            return "report aircraft identification";
    }
}
