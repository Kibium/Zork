#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Exit.h"

Player::Player(const char* theName, const char* theDesc, Room* room) {

	name = theName;
	desc = theDesc;
	parent = room;

	status = HEALTHY;
	weapon = nullptr;
	armor = nullptr;

	type = PLAYER;

}

Player::~Player() {}

bool Player::Look(string s) {

	//cout << "You entered: " << s << endl;
	//vector<Entity*> vect;

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


