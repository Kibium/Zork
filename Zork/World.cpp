#include <iostream>
#include "World.h"
#include "Player.h"
#include "Room.h"
#include "Monster.h"
#include "Entity.h"
#include "Item.h"
#include "Door.h"

World::World(string wName, string pName) {

	//Baptize the world

	name = wName;

	//Rooms

	Room* cave = new Room("Cave", "You find yourself at the end of a cave. You can see a weak light comming from the opposite side. It must be the exit.");
	Room* corridor = new Room("Corridor", "This part of the cave seems to communicate the entrance and the Cave.");
	Room* sanctuary = new Room("Sanctuary", "The light did't come from the entrance of a cave, but from a lake inside the cave! There are three pedestals. One with a ... lighter? An other with a rusty metal knive and the last one has a goat sit on it.");
	Room* stairs = new Room("Stone Stairs", "A natural formation of rocks have formed a sort of natural upstairs.");
	Room* finalRoom = new Room("Wooden door room", "An immense wooden door stands alone in this empty room. Only the torch near it is its only company.");

	Door* door = new Door("Wooden door", "Inmense wooden door that requires a key to be opened", finalRoom);

	entities.push_back(cave);
	entities.push_back(corridor);
	entities.push_back(sanctuary);
	entities.push_back(stairs);
	entities.push_back(finalRoom);

	entities.push_back(door);

	//Initial weapons

	Item* lighter = new Item("Lighter", "It's a lighter. You can burn stuff with it.", sanctuary, WEAPON, -1, 10);
	Item* goat = new Item("Goat", "Its a goat. It seems you like her.", sanctuary, WEAPON, -1, -1);
	Item* knive = new Item("Rusty knive", "A knive that seems to break at any moment.", sanctuary, WEAPON, 10, 10);
	knive->value = 10;

	//Heling stuff

	Item* herb = new Item("Mint herb", "A refreshing herb", sanctuary, NORMAL, 5, 2);
	Item* herb2 = new Item("Mint herb", "A refreshing herb", sanctuary, NORMAL, 5, 2);
	Item* herb3 = new Item("Mint herb", "A refreshing herb", sanctuary, NORMAL, 5, 2);


	entities.push_back(lighter);
	entities.push_back(goat);
	entities.push_back(knive);

	entities.push_back(herb);
	entities.push_back(herb2);
	entities.push_back(herb3);


	//Corridor figure

	Item* figure = new Item("Old figure", "An old figure. Shaking it, you hear a metallic sound", corridor, NORMAL, -1, -1);
	entities.push_back(figure);

	//Key in the corridor

	Item* key = new Item("Small key", "It must open something", figure, CHEST, -1, -1);
	entities.push_back(key);

	//Hidden sanctuary chest

	Item* sanc_chest = new Item("Old chest", "A chest covered in dust. Seems to require a key to be opened.", sanctuary, CHEST, -1, -1);
	Item* bracelet = new Item("Iron Bracelet", "An iron bracelet. It seems new despite the aspect of the chest that contained it.", sanc_chest, ARMOR, 20, 15);
	bracelet->value = 10;

	entities.push_back(sanc_chest);
	entities.push_back(bracelet);

	//Enemies

	Monster* spider = new Monster("Jumping Spider", "A spider that can jump very high, it could be venomous.", corridor);
	Monster* giant_worm = new Monster("Giant Worm", "An enormous worm", corridor);
	Monster* snake = new Monster("Snake", "Looks like a normal snake. It could be venomous", stairs);
	Monster* goblin = new Monster("Goblin", "A green humanoid creature. Looks strong and unfriendly", stairs);
	Monster* giant_goblin = new Monster("Giant Goblin", "Its bigger than you, also stronger, probably dumber.", finalRoom);

	entities.push_back(spider);
	entities.push_back(giant_worm);
	entities.push_back(snake);
	entities.push_back(goblin);
	entities.push_back(giant_goblin);



}

World::~World() {

	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
		delete *it;

	entities.clear();

}

void World::GameLoop() {

}