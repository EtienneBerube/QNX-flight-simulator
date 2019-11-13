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

	 for (auto& plane : planeDB.getPlanes()){
		 t.add(plane->id);
		 t.add(plane->position_x);
		 t.add(plane->position_y);
		 t.add(plane->position_z);
		 t.add(plane->speed_x);
		 t.add(plane->speed_y);
		 t.add(plane->speed_z);
		 t.add(plane->inHoldingPattern);
		 t.add(plane->entryTime);
		 t.endOfRow();
	 }

	 t.setAlignment( 2, TextTable::Alignment::RIGHT );
	 std::cout << t;
}



