#include "Door.h"

Door::Door(const char* theName, const char* theDesc, Room* room) {
	name = theName;
	desc = theDesc;
	where_it_is = room;
	
}