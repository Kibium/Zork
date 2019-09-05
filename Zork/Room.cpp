#include <iostream>
#include "Room.h"

Room::Room(const char* theName, const char* theDesc{

	name = theName;
	desc = theDesc;
	type = ROOM;
	
}

Room::~Room(){}

