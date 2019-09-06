#pragma once
#include <iostream>
#include "Entity.h"
#include "Room.h"

class Exit : public Entity {

public:
	Exit(const char*, const char*, const char*, Room*, Room*);
	void Look();


	string oppositeName;
	Room* originRoom;
	Room* destinationRoom;

};