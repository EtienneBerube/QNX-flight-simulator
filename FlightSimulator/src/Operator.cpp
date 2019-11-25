//
// Created by kbelebinda on 11/18/2019.
//

#include <utility>
#include <vector>
#include <queue>
#include "Operator.h"


void Operator::run(AirplaneDB &airplaneDb){
	cout << "Enter Command: " << endl;
	string commandString;

	cin >> commandString;

	CommandCode commandCode = parseCommand(commandString, airplaneDb);

}


void Operator::executeCommand(CommandCode code, const vector <string> &args, AirplaneDB &airplaneDb) {

	airplaneDb.lockDB();

    string flightId = args[0];

    cout << "id:" << args[0] << " arg 1: " << args[1] << endl;


    int flightIndex = airplaneDb.getIndex(std::stoi(flightId));

    Flight *flight = airplaneDb.getPlanes()->data()[flightIndex];

    switch (code) {
        case changeAltitude:
            flight->changeFlightElevation(std::stoi(args[1]));

            cout << "Aircraft #" << flightId << " elevation changed to " << args[1] << endl;
            break;
        case increaseSpeed:
            flight->increaseSpeedBy(std::stoi(args[1]));

            cout << "Aircraft #" << flightId << " increased speed by " << args[1] << endl;
            break;
        case decreaseSpeed:
            flight->decreaseSpeedBy(std::stoi(args[1]));

            cout << "Aircraft #" << flightId << " decreased speed by " << args[1] << endl;
            break;
        case changeDirection:
            flight->changeDirection();

            cout << "Aircraft #" << flightId << " changed direction." << endl;
            break;
        case enterHoldingPattern:
            flight->enterHoldingPattern();

            cout << "Aircraft #" << flightId << " entered holding pattern." << endl;
            break;
        case leaveHoldingPattern:
            flight->leaveHoldingPattern();

            cout << "Aircraft #" << flightId << " left holding pattern." << endl;
            break;
        case reportCurrentPositionVelocity:
        {
            int currentPositionX = flight->getPositionX();
            int currentPositionY = flight->getPositionY();
            int currentPositionZ = flight->getPositionZ();

            float currentVelocityX = flight->getSpeedX();
            float currentVelocityY = flight->getSpeedY();
            float currentVelocityZ = flight->getSpeedZ();


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
        }
            break;
        case addAircraft:
        {
            int id = std::stoi(flightId);
            int speedInX = std::stoi(args[1]);
            int speedInY = std::stoi(args[2]);
            int speedInZ = std::stoi(args[3]);
            int positionInX = std::stoi(args[4]);
            int positionInY = std::stoi(args[5]);
            int positionInZ = std::stoi(args[6]);
            int startTime = std::stoi(args[7]);

            Flight *newFlight = new Flight(id, speedInX, speedInY, speedInZ, positionInX, positionInY, positionInZ,
                                           startTime);

            airplaneDb.getPlanes()->push_back(newFlight);

            cout << "New Aircraft #" << flightId << " created." << endl;
        }
            break;
        case deleteAircraft:{
        	airplaneDb.getPlanes()->erase(airplaneDb.getPlanes()->begin() + flightIndex);

            cout << "Aircraft #" << flightId << " DESTROYED!!!" << endl;
        }
            break;
        case setPosition:{
            flight->changeFlightPosition(std::stoi(args[1]), std::stoi(args[2]));

            cout << "Position (X,Y) set for Aircraft #" << flightId << endl;
            cout << "Position X: " << args[1] << endl;
            cout << "Position Y: " << args[2] << endl;
        }
            break;
        case setElevation:{
            flight->changeFlightElevation(std::stoi(args[1]));

            cout << "Elevation set for Aircraft #" << flightId << endl;
            cout << "Elevation set to: " << args[1] << endl;
        }
            break;
        case setVelocity:{

            flight->setSpeedX(std::stoi(args[1]));
            flight->setSpeedY(std::stoi(args[2]));
            flight->setSpeedZ(std::stoi(args[3]));

            cout << "Velocity set for Aircraft #" << flightId << endl;
            cout << "Velocity in X: " << args[1] << endl;
            cout << "Velocity in Y: " << args[2] << endl;
            cout << "Velocity in Z: " << args[3] << endl;
        }

            break;
        case reportAircraftIdentification:{

            for (auto &flight : *airplaneDb.getPlanes()) {
                cout << "Aircraft Identification: " << flight->getIdString() << endl;
            }
        }
            break;
    }

    airplaneDb.unlockDB();
}

CommandCode Operator::parseCommand(string userInput, AirplaneDB &airplaneDb) {
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

    executeCommand(commandCode, args, airplaneDb);

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
