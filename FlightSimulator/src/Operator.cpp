//
// Created by kbelebinda on 11/18/2019.
//

#include <utility>
#include <vector>
#include <queue>
#include "Operator.h"
<<<<<<< HEAD
#include <chrono>
=======
>>>>>>> Operator_kevyn

using namespace std::chrono;

<<<<<<< HEAD

void Operator::run(AirplaneDB &airplaneDb){
	while(true){
		cout << "Enter Command: " << endl;
		string commandString;

		cin >> commandString;

		milliseconds start = duration_cast< milliseconds >(
		    system_clock::now().time_since_epoch()
		);
		CommandCode commandCode = parseCommand(commandString, airplaneDb);


		milliseconds end = duration_cast< milliseconds >(
		    system_clock::now().time_since_epoch()
		);

		cout<< "Command took: " << std::to_string(end.count() - start.count()) <<" ms" << endl;
	}

=======
void Operator::run(AirplaneDB &airplaneDb){
	cout << "Enter Command: " << endl;
	string commandString;

	cin >> commandString;

	CommandCode commandCode = parseCommand(commandString, airplaneDb);

>>>>>>> Operator_kevyn
}


void Operator::executeCommand(CommandCode code, const vector <string> &args, AirplaneDB &airplaneDb) {

	airplaneDb.lockDB();

<<<<<<< HEAD
	string flightId;
	int flightIndex;
	Flight *flight;

	if ((code != reportAircraftIdentification) && (code != addAircraft) && (code != nuke)){
		flightId = args[0];
		flightIndex = airplaneDb.getIndex(std::stoi(flightId));
		flight = airplaneDb.getPlanes()->data()[flightIndex];
	}

    cout.flush();
=======
    string flightId = args[0];

    cout << "id:" << args[0] << " arg 1: " << args[1] << endl;


    int flightIndex = airplaneDb.getIndex(std::stoi(flightId));

    Flight *flight = airplaneDb.getPlanes()->data()[flightIndex];
>>>>>>> Operator_kevyn

    switch (code) {
        case changeAltitude:
            flight->changeFlightElevation(std::stoi(args[1]));
<<<<<<< HEAD

=======
>>>>>>> Operator_kevyn

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
<<<<<<< HEAD
            int id = std::stoi(args[0]);
=======
            int id = std::stoi(flightId);
>>>>>>> Operator_kevyn
            int speedInX = std::stoi(args[1]);
            int speedInY = std::stoi(args[2]);
            int speedInZ = std::stoi(args[3]);
            int positionInX = std::stoi(args[4]);
            int positionInY = std::stoi(args[5]);
            int positionInZ = std::stoi(args[6]);
            int startTime = std::stoi(args[7]);

            Flight *newFlight = new Flight(id, speedInX, speedInY, speedInZ, positionInX, positionInY, positionInZ,
                                           startTime);

<<<<<<< HEAD
            cout << "Aircraft created." << endl;

=======
>>>>>>> Operator_kevyn
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
<<<<<<< HEAD
            	if(flight->getId() == -1){
            		flight->generateId();
            	}
=======
>>>>>>> Operator_kevyn
                cout << "Aircraft Identification: " << flight->getIdString() << endl;
            }
        }
            break;
<<<<<<< HEAD

        case nuke:{
        	airplaneDb.getPlanes()->clear();
        	string one = "            _ ._  _ , _ ._\n";
        	string two = "          (_ ' ( `  )_  .__)\n";
        	string three = "        ( (  (    )   `)  ) _)\n";
        	string four = "       (__ (_   (_ . _) _) ,__)\n";
        	string five = "           `~~`\\ ' . /`~~`\n";
        	string six = "                ;   ;\n";
        	string seven = "                /   \\\n";
        	string eight = "  _____________/_ __ \\_____________";

        	cout << one << two << three << four << five << six << seven << eight << endl;
        }
        break;
    }

    cout.flush();
=======
    }

>>>>>>> Operator_kevyn
    airplaneDb.unlockDB();
}

CommandCode Operator::parseCommand(string userInput, AirplaneDB &airplaneDb) {
    string userInputCopy;

    cout<<userInput << endl;

    userInputCopy = std::move(userInput);
    string delimiter = "|";

    size_t pos = userInputCopy.find(delimiter);

    string commands;
    vector <string> args;

    commands = userInputCopy.substr(0, pos);

    userInputCopy.erase(0, pos + delimiter.length());

    string delimiter_args = ",";
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

<<<<<<< HEAD
queue <map<CommandCode, vector < string>>> Operator::getCommandQueue() {
=======
queue <map<CommandCode, vector < string>>>

Operator::getCommandQueue() {
>>>>>>> Operator_kevyn
    return commandQueue;
}

CommandCode Operator::hashIt(const string &command) {
//    TODO: Lower command string before the comparison
    if (command == "change_altitude") {
        return changeAltitude;
    } else if (command == "increase_speed") {
        return increaseSpeed;
    } else if (command == "decrease_speed") {
        return decreaseSpeed;
    } else if (command == "change_direction") {
        return changeDirection;
    } else if (command == "enter_holding_pattern") {
        return enterHoldingPattern;
    } else if (command == "leave_holding_pattern") {
        return leaveHoldingPattern;
    } else if (command == "report_current_position_velocity") {
        return reportCurrentPositionVelocity;
    } else if (command == "add_aircraft") {
        return addAircraft;
    } else if (command == "delete_aircraft") {
        return deleteAircraft;
    } else if (command == "set_position") {
        return setPosition;
    } else if (command == "set_elevation") {
        return setElevation;
    } else if (command == "set_velocity") {
        return setVelocity;
    } else if (command == "report_aircraft_identification") {
        return reportAircraftIdentification;
    } else if  (command == "nuke"){
    	return nuke;
    }
}
