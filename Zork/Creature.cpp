#include <iostream>
#include "Creature.h"

Creature::Creature() {}

Creature::Creature(const char* theName, const char* theDesc, Room* theRoom) {

	name = theName;
	desc = theDesc;
	parent = theRoom;

	type = CREATURE;

	status = HEALTHY;

}

Creature::~Creature() {}

void Creature::MakeObjective(Creature* target) {

	if (battle_target == nullptr)
		battle_target = target;

}

void Creature::Attack(Creature* target) {

	Creature* objective = (Creature*)parent->Find(target);
}

void Creature::Skill(Creature* target) {

}

void Creature::Drop(Room* room) {

	if (droppable != nullptr) {

		droppable->parent = room;
		cout << name << " has dropped " << droppable->name << endl;
	}
	
}

void Creature::Die() {
}

bool Creature::isAlive() {
	return status != DEAD;
}

void Creature::ChangeParent(Entity* newParent) {
	parent = newParent;
}

void Creature::Go(Room* newRoom) {


	if (type == PLAYER)
		cout << "You went to " << newRoom->name << endl;
	else
		cout << name << " went to " << newRoom->name << endl;
	
	parent = newRoom;

	
}
