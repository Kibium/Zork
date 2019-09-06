#pragma once
#include <string>
#include "Item.h"
#include "Room.h"

using namespace std;

class Creature : public Entity {

public:
	Creature(const char* theName, const char* theDesc, Room* theRoom, int moneyDrop);
	~Creature();

	bool isAlive();


	string name;
	Item equipment[2]; //weapon and armor
	int hp;
	int money;

};