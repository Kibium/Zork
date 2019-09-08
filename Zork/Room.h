#pragma once
#include <vector>
#include "Entity.h"

class Exit;


class Room : public Entity {

public:
	Room();
	Room(const char*, const char*);
	~Room();

	
	void deleteList();

	bool completed;
};