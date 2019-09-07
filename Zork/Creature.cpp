#include <iostream>
#include "Creature.h"

Creature::Creature() {}

Creature::Creature(const char* theName, const char* theDesc, Room* theRoom, int health, int gold) {

	name = theName;
	desc = theDesc;
	parent = theRoom;

	type = CREATURE;
	status = HEALTHY;

	hp = health;
	money = gold;

	//parent->container.push_back(this);

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

bool Creature::Go(string roomName) {

	Room* temp;

	for (auto i = parent->container.begin(); i != parent->container.end(); i++) {
		
		if ((*i)->name == roomName && (*i)->type == EXIT) {
		
			parent = (Room*)(*i);
			
			if (type == PLAYER) {
				cout << "You went to " << (*i)->parent->name << endl;
			}

			else {
				cout << name << " went to " << (*i)->parent->name <<endl;
			}
			return true;
		}
		
	}

	cout << "There's no such exit here." << endl;
	return false;
	
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

void Creature::Open(string s) {


}

void Creature::Pick(string s) {


}
