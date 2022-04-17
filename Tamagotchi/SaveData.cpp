#include "SaveData.h"

void saveInformation(vector<string>& data) {
	// Loads information from savefile to this vector
	ifstream saveFile("savefile.txt");

	if (saveFile.fail()) {
		cout << "No save file!";
	}
	else {
		string info;
		while (getline(saveFile, info)) {
			data.push_back(info);
		}
	}
}

void loadInPet(pet p, vector<Pet*>& saves) {
	// Initializes pet based on the breed
	if (p.breed == "Mini Dino") {
		MiniDino* dino = new MiniDino(p.name, p.hunger, p.weight, p.height, p.boredom, p.sleepiness);
		saves.push_back(dino);
	}
	else if (p.breed == "Cat") {
		Cat* cat = new Cat(p.name, p.hunger, p.weight, p.height, p.boredom, p.sleepiness);
		saves.push_back(cat);
	}
	else if (p.breed == "Frog") {

	}
	else {
		cout << p.breed << endl;
		cout << "Invalid breed save file corrupted!" << endl;
	}
}

void getSavedPets(vector<Pet*>& saves, const vector<string>& data) {
	// Loads information from string vector and initializes all pets previously made into the Pet pointer vector
	pet petInfo;
	int num = 0;
	while (data.size() != num) {
		petInfo.breed = data.at(num);
		num += 1;
		petInfo.name = data.at(num);
		num += 1;
		stringstream hunger(data.at(num));
		hunger >> petInfo.hunger;
		num += 1;
		stringstream weight(data.at(num));
		weight >> petInfo.weight;
		num += 1;
		stringstream height(data.at(num));
		height >> petInfo.height;
		num += 1;
		stringstream boredom(data.at(num));
		boredom >> petInfo.boredom;
		num += 1;
		stringstream sleepiness(data.at(num));
		sleepiness >> petInfo.sleepiness;
		num += 2;
		loadInPet(petInfo, saves);
	}
}
