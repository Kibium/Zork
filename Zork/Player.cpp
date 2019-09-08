#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Monster.h"
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

		if (temp == s && (*i)->type != EXIT) {

			cout << (*i)->desc << endl;
			if ((*i)->type == CREATURE && ((Creature*)(*i))->status == DEAD) {
				
					cout << "It's dead" << endl;

				return true;
			}
		}
		else if (temp == s && (*i)->type == EXIT) {

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

void Player::Battle(Creature* monster) {

	MakeObjective(monster);
	monster->MakeObjective(this);

	string tempMonsterName = monster->name;
	std::transform(tempMonsterName.begin(), tempMonsterName.end(), tempMonsterName.begin(), ::tolower);

	inBattle = true;

	cout << monster->name << " attacks!" << endl;
	cout << "What will you do?" << endl;

	turn = true;

	while (inBattle) {

		

		if (turn) {
			string command;
			if (tempMonsterName == "jumping spider" || tempMonsterName == "worm") {
				cout << "- Weapon" << endl << "- Stomp" << endl << "- Ignore" << endl << "- Item" << endl;
				cin >> command;
				std::transform(command.begin(), command.end(), command.begin(), ::tolower);

				if (command == "weapon") {
					cout << "You attacked the " << monster->name << endl;
					int damage;

					if (weapon == nullptr) {
						cout << "You throw a punch" << endl;
						damage = 2;
					}

					if (weapon != nullptr && monster->armor != nullptr)
						damage = weapon->value - monster->armor->value;

					if (weapon != nullptr && monster->armor == nullptr)
						damage = weapon->value;

					
					
					cout << "It received " << damage << " damage" << endl;
					monster->hp -= damage;

					if (monster->hp <= 0)
						monster->hp = 0;

					turn = false;
					monster->turn = true;
				}

				if (command == "stomp") {
					cout << "You deployed your feed onto the bug. Now there is no bug anymore." << endl;
					monster->hp = 0;
					inBattle = false;
					monster->aggressive = false;
					turn = false;
					monster->turn = true;

				}

				if (command == "ignore") {
					cout << "You let the bug live happily." << endl;
					inBattle = false;
					monster->aggressive = false;
					turn = false;
					monster->turn = true;

				}

				if (command == "item") {
					ListInventory();

					//item
					string eetem;
					cin >> eetem;
					std::transform(eetem.begin(), eetem.end(), eetem.begin(), ::tolower);

					for (auto i = container.begin(); i != container.end(); i++) {
						if ((*i)->name == "herb") {
							cout << "The herb heals you for 30 with a mint flavor" << endl;
							hp += 30;
							turn = false;
							monster->turn = true;

						}

						if ((*i)->name == "cool rock") {

							cout << "The rock nailed against the" << monster->name << "'s face" << endl;
							monster->hp -= 20;
							turn = false;
							monster->turn = true;

						}


					}

				}

				
			}
		}

		if (monster->turn) {

			if (monster->hp <= 0) {
				monster->Die((Creature*)this);
				inBattle = false;
				monster->aggressive = false;
				
			}

		}


		
	}

}


