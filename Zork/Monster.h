#pragma once
#include "Entity.h"
#include "Creature.h"
#include "Player.h"


class Monster : public Creature{
public:
	Monster();
	Monster(const char*, const char*, Room*, int, int);
	~Monster();

	Item* holdingItem;
	float hit_chance = 6;

};