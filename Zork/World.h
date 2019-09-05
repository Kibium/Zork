#pragma once

#include <string>
#include <list>

using namespace std;

class World {
public:
	World();
	~World();

	void GameLoop();

private:
	list<Entity*> entities;
};