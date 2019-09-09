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
	void Battle(Creature* monster);
	bool Drop(string);
	bool Open(string);
	bool Put(string, string);
	bool Equip(string);

	//vector<Item*> inventory;



	


};