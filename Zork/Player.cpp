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

