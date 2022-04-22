#include "SaveData.h"

void saveInfo(Pet* newPet, vector<Pet*>& saves) {
	ofstream saveFile;
	saveFile.open("savefile.txt", fstream::app);
	saveFile << newPet->getBreed() << endl;
	saveFile << newPet->getName() << endl;
	saveFile << newPet->getHunger() << endl;
	saveFile << newPet->getWeight() << endl;
	saveFile << newPet->getHeight() << endl;
	saveFile << newPet->getBoredomLevels() << endl;
	saveFile << newPet->getSleepiness() << endl;
	saveFile << newPet->getDead() << endl;
	saveFile << endl;
	saveFile.close();
	saves.push_back(newPet);
}

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

void overWriteSaveFile(vector<Pet*>& saves, Pet* currentPet) {
	ofstream saveFile("savefile.txt");
	for (unsigned int i = 0; i < saves.size(); i++) {
		saveFile << saves.at(i)->getBreed() << endl;
		saveFile << saves.at(i)->getName() << endl;
		saveFile << saves.at(i)->getHunger() << endl;
		saveFile << saves.at(i)->getWeight() << endl;
		saveFile << saves.at(i)->getHeight() << endl;
		saveFile << saves.at(i)->getBoredomLevels() << endl;
		saveFile << saves.at(i)->getSleepiness() << endl;
		cout << saves.at(i)->getDead() << endl;
		saveFile << saves.at(i)->getDead() << endl;
		saveFile << endl;
	}
	saveFile.close();
	if (currentPet->isNeglected()) {
		for (unsigned int i = 0; i < saves.size(); i++) {
			if (currentPet->getName() == saves.at(i)->getName()) {
				saves.at(i)->setDead();
			}
		}
		ofstream saveFile("savefile.txt");
		for (unsigned int i = 0; i < saves.size(); i++) {
			saveFile << saves.at(i)->getBreed() << endl;
			saveFile << saves.at(i)->getName() << endl;
			saveFile << saves.at(i)->getHunger() << endl;
			saveFile << saves.at(i)->getWeight() << endl;
			saveFile << saves.at(i)->getHeight() << endl;
			saveFile << saves.at(i)->getBoredomLevels() << endl;
			saveFile << saves.at(i)->getSleepiness() << endl;
			saveFile << saves.at(i)->getDead() << endl;
			saveFile << endl;
		}
		saveFile.close();
		exit(2);
	}
}

void loadInPet(pet p, vector<Pet*>& saves) {
	// Initializes pet based on the breed
	if (p.breed == "Mini Dino") {
		MiniDino* dino = new MiniDino(p.name, p.hunger, p.weight, p.height, p.boredom, p.sleepiness, p.dead);
		saves.push_back(dino);
	}
	else if (p.breed == "Cat") {
		Cat* cat = new Cat(p.name, p.hunger, p.weight, p.height, p.boredom, p.sleepiness, p.dead);
		saves.push_back(cat);
	}
	else if (p.breed == "Frog") {
		Frog* frog = new Frog(p.name, p.hunger, p.weight, p.height, p.boredom, p.sleepiness, p.dead);
		saves.push_back(frog);
	}
	else {
		cout << p.breed << endl;
		cout << "Invalid breed save file corrupted!" << endl;
	}
}

void getSavedPets(vector<Pet*>& saves, vector<string>& data) {
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
		num += 1;
		stringstream dead(data.at(num));
		dead >> petInfo.dead;
		num += 2;
		loadInPet(petInfo, saves);

	}
}
