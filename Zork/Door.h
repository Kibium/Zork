#pragma once
#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Door : public Entity {

public:

	Door(const char*, const char*, Room*);

	//Variables hard to describe is less words .-. 

	Room* where_it_is;
	Item* what_opens_it;
	//Entity* what_blocks_it;

	bool locked;
};