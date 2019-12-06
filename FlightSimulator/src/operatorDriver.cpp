#include <iostream>
#include "Operator.h"

void printCommandArgsPair(CommandCode commandCode, vector<string> args);

string getCommandString(CommandCode commandCode);

using namespace std;


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
