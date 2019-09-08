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
	void GameLoop(string, vector<string>);
	void CheckPickedWeapons();


	string name;
	list<Entity*> entities;
	

private:
	Player* player;
	bool weaponsPicked;
};