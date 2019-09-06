#pragma once
#include "Entity.h"


class Room : public Entity {

public:
public:
	Room(const char*, const char*);
	~Room();

	void ChangeDesc();

	
	bool completed;
};