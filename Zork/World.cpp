#include <iostream>
#include "World.h"
#include "Player.h"
#include "Room.h"
#include "Creature.h"
#include "Entity.h"
#include "Item.h"

World::World(string wName,string pName) {

	//Baptize the world

	name = wName;

	//Rooms

	Room* cave = new Room("Cave", "You find yourself at the end of a cave. You can see a weak light comming from the opposite side. It must be the exit.");
	Room* corridor = new Room("Corridor", "This part of the cave seems to communicate the entrance and the Cave.");
	Room* sanctuary = new Room("Sanctuary", "The light did't come from the entrance of a cave, but from a lake inside the cave! There are three pedestals. One with a ... lighter? An other with a rusty metal knive and the last one has a goat sit on it.");
	Room* stairs = new Room("Stone Stairs", "A natural formation of rocks have formed a sort of natural upstairs.");
	Room* finalRoom = new Room("Wooden door room", "An immense wooden door stands alone in this empty room. Only the torch near it is its only company.");

	entities.push_back(cave);
	entities.push_back(corridor);
	entities.push_back(sanctuary);

	//Initial weapons

	Item* lighter = new Item("Lighter", "It's a lighter. You can burn stuff with it.", sanctuary, WEAPON, -1, 10);
	Item* goat = new Item("Goat", "Its a goat. It seems you like her.", sanctuary, WEAPON, -1, -1);
	Item* knive = new Item("Rusty knive", "A knive that seems to break at any moment.", sanctuary, WEAPON, 10, 10);

	entities.push_back(lighter);
	entities.push_back(goat);
	entities.push_back(knive);

	//Corridor figure

	Item* figure = new Item("Old figure", "An old figure. Shaking it, you hear a metallic sound", corridor, NORMAL, -1, -1);
	entities.push_back(figure);

	//Key

	Item* key = new Item("Small key", "It must open something", figure, CHEST, -1, -1);
	entities.push_back(key);

	//Hidden sanctuary chest

	Item* sanc_chest = new Item("Old chest", "A chest covered in dust. Seems to require a key to be opened.", sanctuary, CHEST, -1, -1);
	Item* bracelet = new Item("Iron Bracelet", "An iron bracelet. It seems new despite the aspect of the chest that contained it.", sanc_chest, ARMOR, 20, 15);

	entities.push_back(sanc_chest);
	entities.push_back(bracelet);





}