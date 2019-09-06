#pragma once
#include "Creature.h"
class Player : public Creature {
public:
	void Move(const char* direction);
	void Attack(const char* target);
	void Open(const char* target);
	void Pick(const char* target);
};