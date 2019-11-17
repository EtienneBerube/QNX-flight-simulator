/*
 * Display.cpp
 *
 *  Created on: Nov 3, 2019
 *      Author: etienne
 */

#include"Display.h"
#include "TextTable.h"

Display::Display(AirplaneDB* head){
	//ADD DB in Dependency injection
}

void Display::getThreadRunnable(void* context){
	((Display *) context)->displayCurrentState();
}

void Display::displayCurrentState(){
	 TextTable t( '-', '|', '+' );

	 t.add("id");
	 t.add("X");
	 t.add("Y");
	 t.add("Z");
	 t.add("Velo. X");
	 t.add("Velo. Y");
	 t.add("Velo. Z");
	 t.add("Holding pattern");
	 t.add("Entry time");
	 t.endOfRow();

	 for (auto& plane : planeDB->getPlanes()){
		 t.add(plane->getIdString());
		 t.add(std::to_string(plane->getPositionX()));
		 t.add(std::to_string(plane->getPositionY()));
		 t.add(std::to_string(plane->getPositionZ()));
		 t.add(std::to_string(plane->getSpeedX()));
		 t.add(std::to_string(plane->getSpeedY()));
		 t.add(std::to_string(plane->getSpeedZ()));
		 t.add(plane->getHoldingPatternStatus());
		 t.add(std::to_string(plane->getEntryTime()));
		 t.endOfRow();
	 }

	 t.setAlignment( 2, TextTable::Alignment::RIGHT );
	 std::cout << t;
}



