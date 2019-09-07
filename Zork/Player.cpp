#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Exit.h"

//This kind of constructor took me a while to look for it, the enemies and the player's variables didn't print from the world class without this constructor.
Player::Player(const char* theName, const char* theDesc, Room* room, int health) : Creature(theName, theDesc, room) {


	hp = health;
	status = HEALTHY;
	weapon = nullptr;
	armor = nullptr;

	type = PLAYER;

	room->container.push_back(this);

}

Player::~Player() {}

bool Player::Look(string s) {

	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	if (s == name) {
		cout << desc << endl;
		return true;

	}

	if (s == parent->name) {
		cout << parent->desc << endl;
		return true;

	}

	for (auto i = parent->container.begin(); i != parent->container.end(); i++) {
		//vect.push_back((*i));
		string temp = (*i)->name;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		if (temp == s && type != EXIT) {


			cout << "Type: " << (*i)->type << endl;

			cout << (*i)->desc << endl;

			return true;
		}

		else if (temp == s && type == EXIT) {

			cout << "- " << (*i)->desc << '(' << (*i)->name << ')' << endl;
			return true;
		}

		/*if ((*i)->name == s && type == ITEM) {
			cout << "gotcha" << endl;
			cout << (*i)->desc << endl;
			return true;

		}

		else {

			cout << "- " << (*i)->desc << '(' << (*i)->name << ')' << endl;
			return true;
		}*/
	}

	cout << "I can't see such thing." << endl;
	/*for (int i = 0; i < vect.size(); i++) {
		cout << "- " << vect[i]->name << endl;
	}*/


	return false;

}

bool Player::Go(string roomName) {


	Room* temp;

	for (auto i = parent->container.begin(); i != parent->container.end(); i++) {

		if ((*i)->name == roomName && (*i)->type == EXIT) {

			if (!((Exit*)(*i))->locked) {
				parent = ((Exit*)(*i))->destinationRoom;
				cout << "You went to:" << parent->name << endl;
				cout << parent->desc << endl;

				return true;
			}
			else {
				cout << "The exit is locked!" << endl;
				return false;
			}





		}

	}

	cout << "There's no such exit here." << endl;
	return false;



}

bool Player::ListInventory() {

	if (container.size() > 0) {
		cout << "You have: " << endl;
		for (auto i = container.begin(); i != container.end(); i++) {
			cout << "- " << (*i)->name << endl;
		}
		return true;
	}
	else {

		//sorry
		cout << "You got nothin but dust in ya pockets" << endl;
		return false;

	}


}

bool Player::Pick(string item) {

	

	for (auto i = parent->container.begin(); i != parent->container.end(); i++) {

		string temp = (*i)->name;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		if (temp == item && (*i)->type == ITEM) {
			container.push_back(*i);
			cout << container.size() << endl;
			return true;
		}
	}

	cout << "That, sir, is unpickable" << endl;
	return false;

}


