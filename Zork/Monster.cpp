#include <iostream>
#include "Monster.h"

Monster::Monster(){}

Monster::Monster(const char* theName, const char* theDesc, Room* theParent, int health, int gold) : Creature(theName, theDesc, theParent) {

	type = CREATURE;

	name = theName;
	desc = theDesc;
	parent = (Entity*)theParent;
	
	status = HEALTHY;

	weapon = nullptr;
	armor = nullptr;
	aggressive = true;

	hp = health;
	money = gold;

	theParent->container.push_back(this);


	
}

Monster::~Monster(){}



