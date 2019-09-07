#pragma once
#include "Creature.h"
class Monster : public Creature {
public:
	Monster(const char*, const char*, Entity*);

	void Die();

	Item* holdingItem;
	

	float item_drop_chance = 0.5;

};