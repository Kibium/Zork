#pragma once
#include "Entity.h"
class Room : public Entity {

public:
public:
	Room(const char* name, const char* description);
	~Room();

	void ChangeDesc();

	
	bool completed;
};