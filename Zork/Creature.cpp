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

void Creature::Go(string roomName) {

	cout << "arriba aqui";

	for (auto i = parent->container.begin(); i != parent->container.end(); i++) {
		//if ((*i)->name == roomName && (*))
		//	ChangeParent(*i);
	}

	cout << "i aqui" << endl;

	/*if (type == PLAYER)
		cout << "You went to " << parent->name << endl;
	else
		cout << name << " went to " << parent->name << endl;

	/*if (type == PLAYER)
		cout << "You went to " << newRoom->name << endl;
	else
		cout << name << " went to " << newRoom->name << endl;
	
	parent = newRoom;
	*/
	
}

void Creature::Look(string a) {

}

void Creature::CheckStatus() {

	switch (status) {
	case NORMAL:
		cout << "Status: Healthy" << endl;
		break;
	case POISONED:
		cout << "Status: Poisoned" << endl;
		break;

	case DEAD:
		cout << "Status: Dead" << endl;

	}
	
}
