#pragma once
#include <string>
#include <list>
#include <vector>
#include "Player.h"


using namespace std;

class World {
public:
	World(string, string);
	~World();

	string name;
	void GameLoop(string, vector<string>);
	list<Entity*> entities;

private:
	Player* player;
};