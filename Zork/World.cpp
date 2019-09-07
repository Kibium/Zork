#include <iostream>
#include <algorithm> 
#include "World.h"
#include "Utils.h"
#include "Player.h"
#include "Room.h"
#include "Monster.h"
#include "Entity.h"
#include "Item.h"
#include "Door.h"
#include "Exit.h"

World::World(string wName, string pName) {

	//Baptize the world

	name = wName;

	//Rooms

	Room* cave = new Room("Cave", "You find yourself at the end of a cave. You can see a weak light comming from the opposite side.");
	Room* corridor = new Room("Corridor", "This part of the cave seems to communicate the entrance and the Cave.");
	Room* sanctuary = new Room("Sanctuary", "The light did't come from the entrance of a cave, but from a lake inside the cave! There are three pedestals. One with a ... lighter? An other with a rusty metal knive and the last one has a goat sit on it.");
	Room* stairs = new Room("Stone Stairs", "A natural formation of rocks have formed a sort of natural upstairs.");
	Room* finalRoom = new Room("Door room", "An immense wooden door stands alone in this empty room. Only the torch near it is its only company.");
	Room* end = new Room("Outside", "The sunlight reaches your skin. Feels awesome. Now... Let's go play videogames!");

	//Exits

	Exit* cave_corridor = new Exit("forward", "back", "Exit to the corridor", cave, corridor);
	Exit* corridor_cave = new Exit("back", "forward", "Exit to the Cave", corridor, cave);

	Exit* corridor_sanctuary = new Exit("east", "west", "Marble Portal", corridor, sanctuary);
	Exit* corridor_stairs = new Exit("west", "east", "Corner", corridor, stairs);

	Exit* sanctuary_corridor = new Exit("west", "east", "Marble Portal", sanctuary, corridor);

	Exit* stairs_corridor = new Exit("east", "west", "Corner", stairs, corridor);
	Exit* stairs_finalRoom = new Exit("forward", "back", "Platform", stairs, finalRoom);

	Exit* finalRoom_stairs = new Exit("back", "forward", "Platform", finalRoom, stairs);

	Exit* finalRoom_end = new Exit("forward", "back", "Insanely large door", finalRoom, end);
	finalRoom_end->locked = true;

	/*cave->neighborRooms.push_back(corridor);

corridor->neighborRooms.push_back(cave);
corridor->neighborRooms.push_back(sanctuary);

sanctuary->neighborRooms.push_back(corridor);
sanctuary->neighborRooms.push_back(corridor);
sanctuary->neighborRooms.push_back(stairs);
sanctuary->neighborRooms.push_back(cave); //connects with the first one. Only one way

stairs->neighborRooms.push_back(sanctuary);
stairs->neighborRooms.push_back(finalRoom);

finalRoom->neighborRooms.push_back(stairs);*/

	entities.push_back(cave);
	entities.push_back(corridor);
	entities.push_back(sanctuary);
	entities.push_back(stairs);
	entities.push_back(finalRoom);

	entities.push_back(cave_corridor);
	entities.push_back(corridor_cave);
	entities.push_back(corridor_sanctuary);
	entities.push_back(corridor_stairs);
	entities.push_back(sanctuary_corridor);
	entities.push_back(stairs_corridor);
	entities.push_back(stairs_finalRoom);
	entities.push_back(finalRoom_stairs);
	entities.push_back(finalRoom_end);

	//Initial weapons

	Item* lighter = new Item("Lighter", "It's a lighter. You can burn stuff with it.", sanctuary, WEAPON, -1, 10);
	Item* goat = new Item("Goat", "Its a goat. It seems you like her.", sanctuary, WEAPON, -1, -1);
	Item* knive = new Item("Rusty knive", "A knive that seems to break at any moment.", sanctuary, WEAPON, 10, 10);
	knive->value = 10;

	//Heling stuff

	Item* herb = new Item("Herb", "A refreshing herb", sanctuary, NORMAL, 5, 2);
	Item* herb2 = herb;
	Item* herb3 = herb;


	entities.push_back(lighter);
	entities.push_back(goat);
	entities.push_back(knive);

	entities.push_back(herb);
	entities.push_back(herb2);
	entities.push_back(herb3);

	//Other stuff
	Item* rock = new Item("Cool Rock", "It's a rock. It has a cool form that remembers of a water drop.", cave, NORMAL, 1, 3);
	entities.push_back(rock);

	//Corridor figure

	Item* figure = new Item("Figure", "An old figure. Shaking it, you hear a metallic sound", corridor, NORMAL, -1, -1);
	entities.push_back(figure);

	//Key in the corridor

	Item* key = new Item("Key", "It must open something", figure, CHEST, -1, -1);
	entities.push_back(key);
	finalRoom_end->key = key;
	figure->container.push_back(key);

	//Sack to put objects in
	Item* sack = new Item("Sack", "A sack that seems to have space for everything. Makes me think about a cosmic cat from the future.", stairs, NORMAL, -1, -1);

	//Hidden sanctuary chest

	Item* sanc_chest = new Item("Chest", "A chest covered in dust. Seems to require a key to be opened.", sanctuary, CHEST, -1, -1);
	Item* bracelet = new Item("Iron bracelet", "An iron bracelet. It seems new despite the aspect of the chest that contained it.", sanc_chest, ARMOR, 20, 15);
	bracelet->value = 10;

	entities.push_back(sanc_chest);
	entities.push_back(bracelet);

	//Enemies

	Monster* spider = new Monster("Jumping spider", "A spider that can jump very high, it could be venomous.", corridor);
	Monster* giant_worm = new Monster("Worm", "An enormous worm", corridor);
	Monster* snake = new Monster("Snake", "Looks like a normal snake. It could be venomous", stairs);
	Monster* goblin = new Monster("Goblin", "A green humanoid creature. Looks strong and unfriendly", stairs);
	Monster* giant_goblin = new Monster("Giant goblin", "Its bigger than you, also stronger, probably dumber.", finalRoom);

	entities.push_back(spider);
	entities.push_back(giant_worm);
	entities.push_back(snake);
	entities.push_back(goblin);
	entities.push_back(giant_goblin);



	//Player

	player = new Player(pName.c_str(), "You don't remember anything but one thing, you are awesome.", cave);



}

World::~World() {

	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
		delete *it;

	entities.clear();

}

void World::GameLoop(string player_input, vector<string> commands) {

	//for (int i = 0; i < commands.size(); i++)
	std::transform(commands[0].begin(), commands[0].end(), commands[0].begin(), ::tolower);

	//The game knows what the player introduced
	if (commands.size() == 1) {

		if (commands[0] == "help") {
			cout << "List of available commands:" << endl;
			cout << "- look" << endl << "- go" << endl << "- room" << endl << "- status" << endl;
		}

		if (commands[0] == "room") {
			cout << "You are in: " << player->parent->name << endl;
			cout << player->parent->desc;

		}

		if (commands[0] == "status") {
			player->CheckStatus();

		}

		if (commands[0] == "look") {
			cout << "What do you wanna look at?" << endl;
			//cout << "- " << player->parent->name << endl;
			for (auto i = player->parent->container.begin(); i != player->parent->container.end(); i++)
				cout << "- " << (*i)->name << endl;

			string looking_at;
			getline(cin,looking_at);
			player->Look(looking_at);
		}

		if (commands[0] == "go") {
			cout << "Where do you want to go?" << endl;

			Room* temp = (Room*)player->parent;
			//cout << "There are " << temp->container.size() << " exits" << endl;
			for (auto i = temp->container.begin(); i != temp->container.end(); i++) {
				if ((*i)->type == EXIT) {
					cout << "- " << (*i)->desc << '(' << (*i)->name << ')' << endl;
				}


			}


			string go_to;
			getline(cin, go_to);
			player->Go(go_to);
		}


	}

	if (commands.size() > 1) {
		if (commands[0] == "look") {
			player->Look(commands[1]);
		}
	}


}