#pragma once
#include <string>
#include <list>
#include "Entity.h"

using namespace std;

class World {
public:
	World(string, string);
	~World();

	string name;
	void GameLoop();

private:
	list<Entity*> entities;
};