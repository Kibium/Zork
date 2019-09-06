#include "Exit.h"

Exit::Exit(const char* theName, const char* opposite_name, const char* theDesc, Room* origin, Room* destination) {

	name = theName;
	desc = theDesc;
	oppositeName = opposite_name;

	originRoom = origin;
	destinationRoom = destination;

	type = EXIT;

	origin->container.push_back(this);

}

void Exit::Look() {
	cout << "The exit connects this room with " << destinationRoom << endl;
}