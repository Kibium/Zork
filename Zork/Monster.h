#pragma once
#include "Creature.h"
class Monster : public Creature {
public:
	Monster();
	Monster(const char*, const char*, Room*, int, int);
	~Monster();

	//void Die();

	Item* holdingItem;
	

	float item_drop_chance = 0.5;

};