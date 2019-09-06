#include <iostream>
#include "Player.h"

Player::Player(const char* theName, const char* theDesc, Room* room) {

	name = theName;
	desc = theDesc;
	parent = room;

	status = HEALTHY;
	weapon = nullptr;
	armor = nullptr;

}

Player::~Player(){}

bool Player::Look(string s) {

	if (s == parent->name) {
		cout << parent->desc << endl;
		return true;

	}

	else {
		for (auto i = parent->container.begin(); i != parent->container.end(); i++) {
			if ((*i)->name == s) {
				cout << (*i)->desc << endl;
				return true;
			}
		}
	}

	cout << "There is nothing like that in here" << endl;
	return false;
}


