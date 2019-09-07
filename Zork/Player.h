#pragma once
#include "Creature.h"
class Player : public Creature {
public:
	Player(const char*, const char*, Room*, int);
	~Player();

	bool Look(string);
	bool Go(string);
	bool ListInventory();
	bool Pick(string);

	vector<Item*> inventory;


	


};