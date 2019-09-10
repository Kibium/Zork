#pragma once
#include "Creature.h"
class Player : public Creature {
public:
	Player(const char*, const char*, Room*, int);
	~Player();

	bool Look(const string &s);
	bool Go(const string &s);
	bool ListInventory();
	bool Pick(const string &s);
	void Battle(Creature* monster);
	bool Drop(const string &s);
	bool Open(const string &s);
	bool Put(const string &s, const string &s2);
	bool Equip(const string &s);

	//vector<Item*> inventory;



	


};