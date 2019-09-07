#pragma once
#include <string>
#include "Item.h"
#include "Room.h"

using namespace std;

enum Status {
	HEALTHY,
	POISONED,
	DEAD
};

class Creature : public Entity {

public:
	Creature();
	Creature(const char*, const char*, Room*, int, int);
	~Creature();

	void MakeObjective(Creature*);
	void Attack(Creature*);
	void Skill(Creature*);
	void Die();
	void Drop(Room*);
	void ChangeParent(Entity*);
	bool Go(string);
	void Open(string);
	void Pick(string);
	void Look(string);
	void CheckStatus();

	//void Block()

	bool isAlive();

	Creature* battle_target;

	string name;

	Item* weapon;
	Item* armor;
	Item* droppable;

	Status status;

	int hp;
	int money;

};