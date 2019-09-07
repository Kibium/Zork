#include <iostream>
#include "Monster.h"

Monster::Monster(const char* theName, const char* theDesc, Entity* theParent) {

	name = theName;
	desc = theDesc;
	parent = theParent;
	//parent->container.push_back(this);

	cout << name << " created" << endl;
	//cout << "Belongs here: "<< parent->name << endl;



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