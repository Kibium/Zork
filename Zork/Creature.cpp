#include <iostream>
#include "Creature.h"

Creature::Creature() {}


Creature::Creature(const char* theName, const char* theDesc, Room* theRoom, int health, int gold) : Entity(theName, theDesc, (Entity*)theRoom) {

	
	type = CREATURE;
	status = HEALTHY;

	hp = health;
	money = gold;

	//parent->container.push_back(this);

}


Creature::Creature(const char* theName, const char* theDesc, Room* room) : Entity(theName, theDesc, (Entity*)room) {
	

	hp = 25;
	status = HEALTHY;
	weapon = nullptr;
	armor = nullptr;

	type = PLAYER;
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

	/*if (droppable != nullptr) {

		droppable->parent = room;
		cout << name << " has dropped " << droppable->name << endl;
	}
	*/
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

	cout << "Name: " << name << endl;
	


	switch (status) {
	case HEALTHY:
		cout << "Status: Healthy" << endl;
		break;
	case POISONED:
		cout << "Status: Poisoned" << endl;
		break;

	case DEAD:
		cout << "Status: Dead" << endl;
	}

	cout << "HP: " << hp << endl;

	if (weapon != nullptr)
		cout << "Attack: " << weapon->value << endl;
	else
		cout << "Attack: 0" << endl;

	if(armor!= nullptr)
	cout << "Armor: " << armor->value << endl;

	else
		cout << "Armor: 0" << endl;


	
}

void Creature::Open(string s) {


}

void Creature::Pick(string s) {


}
