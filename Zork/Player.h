#pragma once
#include "Creature.h"
class Player : public Creature {
public:
	Player(const char*, const char*, Room*);
	~Player();

	bool Look(string);


};