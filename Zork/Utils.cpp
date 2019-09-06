#include "Utils.h"

bool CompareCommand(string s, const char* c) {
	return s == c;
}

vector<string> GetCommands(string input) {

	string helper = input;
	vector<string> commands;

	//We detect how many commands have been introduced

	int spaces = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) == ' ')
			spaces++;
	}

	for (int i = 0; i <= spaces; i++) {
		int slicePos = helper.find(" ");
		string temp = helper.substr(0, slicePos);

		//the command gets stored in the vector

		commands.push_back(temp);

		// the input has recognized a command, looks for others from where it dectected the last one

		string temp2 = helper.substr(slicePos + 1); 
		helper = temp2;
	}

	return commands;

}

/*
	string asd = "yolo a lol";

	int spaces = 0;
	for (int i = 0; i < asd.length(); i++) {
		if (asd.at(i) == ' ')
			spaces++;
	}


	cout << spaces << endl;

	for (int i = 0; i <= spaces; i++) {
		int slicePos = asd.find(" ");
		string temp = asd.substr(0, slicePos);
		//cout << asd << endl;
		string temp2 = asd.substr(slicePos+1);
		cout << temp << endl;
		asd = temp2;
	}

*/