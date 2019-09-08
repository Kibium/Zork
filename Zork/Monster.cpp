#include <iostream>
#include "Monster.h"

Monster::Monster(){}

Monster::Monster(const char* theName, const char* theDesc, Room* theParent, int health, int gold) : Creature(theName, theDesc, theParent) {

	type = CREATURE;

	name = theName;
	desc = theDesc;
	parent = (Entity*)theParent;
	
	status = HEALTHY;

	Item* empty = new Item("--", "---", this, WEAPON, 0, 0);
	Item* empty2 = new Item("--", "---", this, ARMOR, 0, 0);

	weapon = empty;
	armor = empty2;
	aggressive = true;

	hp = health;
	money = gold;

	theParent->container.push_back(this);


	
}

Monster::~Monster(){}



