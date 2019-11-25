//
// Created by kbelebinda on 11/18/2019.
//

#include <utility>
#include <vector>
#include <queue>
#include "Operator.h"
#include "Flight.h"
#include "AirplaneDB.h"


void Operator::executeCommand(CommandCode, const vector <string> &args, AirplaneDB &airplaneDb) {

    flightId = args[0];
    firstArgument = args[1];
    secondArgument = args[2];
    thirdArgument = args[3];

//    Flight info additional args:
    fourthArgument = args[4];
    fifthArgument = args[5];
    sixthArgument = args[6];
    seventhArgument = args[7];

    int flightIndex = airplaneDb.getFlightIndex(int(flightId));

    Flight &flight = airplaneDb.getPlanes()[flightIndex];

    switch (commandCode) {
        case changeAltitude:
            flight.changeFlightElevation(firstArgument);

            cout << "Aircraft #" << flightId << " elevation changed to " << firstArgument << endl;
            return;
        case increaseSpeed:
            flight.increaseSpeedBy(firstArgument);

            cout << "Aircraft #" << flightId << " increased speed by " << to_string(firstArgument) << endl;
            return;
        case decreaseSpeed:
            flight.decreaseSpeedBy(firstArgument);

            cout << "Aircraft #" << flightId << " decreased speed by " << to_string(firstArgument) << endl;
            return;
        case changeDirection:
            flight.changeDirection();

            cout << "Aircraft #" << flightId << " changed direction." << endl;
            return;
        case enterHoldingPattern:
            flight.enterHoldingPattern();

            cout << "Aircraft #" << flightId << " entered holding pattern." << endl;
            return;
        case leaveHoldingPattern:
            flight.leaveHoldingPattern();

            cout << "Aircraft #" << flightId << " left holding pattern." << endl;
            return;
        case reportCurrentPositionVelocity:
            int currentPositionX = flight.getPositionX();
            int currentPositionY = flight.getPositionY();
            int currentPositionZ = flight.getPositionZ();

            float currentVelocityX = flight.getSpeedX();
            float currentVelocityY = flight.getSpeedY();
            float currentVelocityZ = flight.getSpeedZ();


            cout << "Aircraft #" << flightId << ":" << endl;
            cout << "Current position (X, Y, Z):" << endl;
            cout << "X: " << currentPositionX << endl;
            cout << "Y: " << currentPositionY << endl;
            cout << "Z: " << currentPositionZ << endl;

            cout << endl;

            cout << "Current velocity (X, Y, Z):" << endl;
            cout << "X: " << currentVelocityX << endl;
            cout << "Y: " << currentVelocityY << endl;
            cout << "Z: " << currentVelocityZ << endl;
            return;
        case addAircraft:
            int id = int(flightId);
            int speedInX = int(firstArgument);
            int speedInY = int(secondArgument);
            int speedInZ = int(thirdArgument);
            int positionInX = int(fourthArgument);
            int positionInY = int(fifthArgument);
            int positionInZ = int(sixthArgument);
            int startTime = int(seventhArgument);

            Flight &newFlight = new Flight(id, speedInX, speedInY, speedInZ, positionInX, positionInY, positionInZ,
                                           startTime);

            airplaneDb.getPlanes().push_back(newFlight);

            cout << "New Aircraft #" << flightId << " created." << endl;

            return;
        case deleteAircraft:
            flights.erase(flightIndex);

            cout << "Aircraft #" << flightId << " DESTROYED!!!" << endl;

            return;
        case setPosition:
            flight.changeFlightPosition(firstArgument, secondArgument);

            cout << "Position (X,Y) set for Aircraft #" << flightId << endl;
            cout << "Position X: " << firstArgument << endl;
            cout << "Position Y: " << secondArgument << endl;
            return;
        case setElevation:
            flight.changeFlightElevation(firstArgument);

            cout << "Elevation set for Aircraft #" << flightId << endl;
            cout << "Elevation set to: " << to_string(firstArgument) << endl;
            return;
        case setVelocity:

            flight.setSpeedX(firstArgument);
            flight.setSpeedY(secondArgument);
            flight.setSpeedZ(thirdArgument);

            cout << "Velocity set for Aircraft #" << flightId << endl;
            cout << "Velocity in X: " << to_string(firstArgument) << endl;
            cout << "Velocity in Y: " << to_string(secondArgument) << endl;
            cout << "Velocity in Z: " << to_string(thirdArgument) << endl;

            return;
        case reportAircraftIdentification:

            for (auto &flight : airplaneDb.getPlanes()) {
                cout << "Aircraft Identification: " << flight.getIdString() << endl;
            }
            return;
    }
}

CommandCode Operator::parseCommand(string userInput) {
    string userInputCopy;
    userInputCopy = std::move(userInput);
    string delimiter = "|";

    size_t pos = userInputCopy.find(delimiter);

    string commands;
    vector <string> args;

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

void Operator::addCommandToQueue(CommandCode command, const vector <string> &args) {
    map <CommandCode, vector<string>> commandArgumentsPair;

    commandArgumentsPair.insert(pair < CommandCode, vector < string >> (command, args));

    commandQueue.push(commandArgumentsPair);
}

queue <map<CommandCode, vector < string>>>

Operator::getCommandQueue() {
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
