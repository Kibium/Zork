#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "world.h"
#include "Utils.h"

int main() {

	char key;
	string player_input;
	string tempInput;
	vector<string> commands;

	string world_name;
	string player_name;



	bool endGame = false;

	cout << "Hello traveler! You find yourself in a cave, full or luminous rocks. You are very creative and you want to give the cave a name. Which would it be?" << endl;
	cin >> world_name;

	cout << "As you wake up, you don't remember nothing about how you ended here. Thus, you don't remember your name, but you want one." << endl;
	cout << "Type it:" << endl;
	cin >> player_name;

	World world(world_name, player_name);

	cout << "The first thing that comes to your mind is: I gotta get out of the " << world_name << " cave! " << endl;
	cout << player_name << ", find your way! Investigate everything!" << endl;

	while (!endGame) {

		getline(cin, player_input);

		//The game knows what the player introduced

		commands = GetCommands(player_input);

		if (commands[0] == "look"){
			cout << "An amazingly big cave" << endl;
		}


	}

	system("pause");

	return 0;

}