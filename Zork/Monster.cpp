#include <iostream>
#include "Monster.h"

Monster::Monster(const char* theName, const char* theDesc, Room* room) {

	name = theName;
	desc = theDesc;
	parent = room;

	status = HEALTHY;

	weapon = nullptr;
	armor = nullptr;

}



void Monster::Die() {

	//Check if this works
	Drop((Room*)parent);

	//Resetting target for both monster and player
	battle_target = battle_target->battle_target = nullptr;

	status = DEAD;
	cout << name << " has been defeated." << endl;

}