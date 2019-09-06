#pragma once
#include <vector>
#include "Entity.h"

class Exit;


class Room : public Entity {

public:
public:
	Room(const char*, const char*);
	~Room();

	//vector<Exit*> exits;
	
	bool completed;
};