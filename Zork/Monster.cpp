#include <iostream>
#include "Monster.h"

Monster::Monster(){}

Monster::Monster(const char* theName, const char* theDesc, Room* theParent, int health, int gold) {

	type = CREATURE;

	name = theName;
	desc = theDesc;
	parent = theParent;
	
	status = HEALTHY;

	weapon = nullptr;
	armor = nullptr;

	hp = health;
	money = gold;

	//NOT WORKING, NAMES DON'T APPEAR
	theParent->container.push_back(this);


	
}

Monster::~Monster(){}



/*void Monster::Die() {

	//Check if this works
	Drop((Room*)parent);

	//Resetting target for both monster and player
	battle_target = battle_target->battle_target = nullptr;

	status = DEAD;
	cout << name << " has been defeated." << endl;

}*/