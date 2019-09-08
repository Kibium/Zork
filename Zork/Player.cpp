#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Monster.h"
#include "Room.h"
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
		string temp = (*i)->name;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		if (temp == s && (*i)->type != EXIT) {

			cout << (*i)->desc << endl;
			if ((*i)->type == CREATURE && ((Creature*)(*i))->status == DEAD) {

				cout << "It's dead" << endl;

			}
			return true;
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



	return false;

}

bool Player::Go(string roomName) {


	Room* temp;

	for (auto i = parent->container.begin(); i != parent->container.end(); i++) {

		if ((*i)->name == roomName && (*i)->type == EXIT) {

			if (!((Exit*)(*i))->locked) {
				parent = ((Exit*)(*i))->destinationRoom;
				cout << "You went to: " << parent->name << endl;
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

			if (((Item*)(*i))->item_type == WEAPON && weapon == nullptr) {
				(*i)->parent = this;
				weapon = ((Item*)(*i));

				cout << "Weapon equipped" << endl;
				return true;
			}

			else if (((Item*)(*i))->item_type == ARMOR && armor == nullptr) {
				cout << "Armor equipped" << endl;
				(*i)->parent = this;
				armor = ((Item*)(*i));
				return true;
			}

			else if (weapon != nullptr) {
				cout << "You are too happy with your" << weapon->name << " to substitute it!" << endl;
				return false;
			}

			(*i)->parent = this;
			container.push_back(*i);
			cout << "Picked, and put to the inventory." << endl;
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
			string eetem;

			cout << "- Weapon" << endl << "- Stomp" << endl << "- Ignore" << endl << "- Status" << endl << "- Item" << endl;
			getline(cin, command);
			std::transform(command.begin(), command.end(), command.begin(), ::tolower);

			if (command == "weapon") {
				cout << "You attacked the " << monster->name << endl;
				int damage;

				if (weapon == nullptr) {
					cout << "You threw a punch" << endl;
					damage = 2;
				}

				if (weapon != nullptr && monster->armor != nullptr)
					damage = weapon->value - monster->armor->value;

				if (weapon != nullptr && monster->armor == nullptr)
					damage = weapon->value;



				cout << "It received " << damage << " damage" << endl;
				monster->hp -= damage;



				turn = false;
				monster->turn = true;
			}

			if (command == "stomp") {
				if (tempMonsterName == "jumping spider" || tempMonsterName == "worm") {


					cout << "You deployed your feed onto the bug. Now there is no bug anymore." << endl;
					monster->hp = 0;
					monster->aggressive = false;
					turn = false;
					monster->turn = true;
				}

				if (tempMonsterName == "snake") {
					cout << "You smashed the snake with your foot" << endl;
					cout << "It took damage, but not enough!" << endl;
					turn = false;
					monster->turn = true;
				}
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
				cout << "Select item: " << endl;

				getline(cin, eetem);

				std::transform(eetem.begin(), eetem.end(), eetem.begin(), ::tolower);
				cout << "You selected " << eetem << endl;

				for (auto i = container.begin(); i != container.end(); i++) {

					string temp = (*i)->name;
					std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

					if (temp == "herb") {
						cout << "The herb heals you for 30 with a mint flavor" << endl;
						hp += 30;
						turn = false;
						monster->turn = true;
						break;

					}

					else if (temp == "cool rock") {

						cout << "The rock nailed against the " << monster->name << "'s face" << endl;
						monster->hp -= 20;
						turn = false;
						monster->turn = true;
						break;

					}

					else {
						cout << "It had no effect" << endl;
						turn = false;
						monster->turn = true;
						break;
					}


				}

			}

			if (command == "status") {
				CheckStatus();
			}

		}

		if (monster->hp <= 0)
			monster->hp = 0;

		if (monster->turn && inBattle) {

			if (monster->hp <= 0) {
				monster->Die((Creature*)this);
				inBattle = false;
				monster->aggressive = false;
				break;
			}

			cout << "The " << monster->name << " attacks!" << endl;

			if (monster->weapon != nullptr) {
				int damage = monster->weapon->value - armor->value;
				cout << "You took " << damage << " damage" << endl;
				hp -= damage;
				monster->turn = false;
				turn = true;

			}
			else {
				cout << "But it had no weapon!" << endl;
				monster->turn = false;
				turn = true;
			}


		}



	}

}


