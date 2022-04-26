#include "Menu.h"

Pet* newPet(string name, vector<Pet*>& saves) {
	cout << "There are three pets to choose from:" << endl;
	cout << "1. Mini Dino" << endl;
	cout << "2. Cat" << endl;
	cout << "3. Frog" << endl;
	cout << "Type in the number corresponding with the pet you want." << endl;
	cout << "Number: ";
	string choice;

	cin >> choice;
	while (choice != "1" && choice != "2" && choice != "3"){
		cout << "Invalid choice type 1, 2, or 3;" << endl;
		cout << "Number: ";
		cin >> choice;
	}
	int num;
	stringstream getNum(choice);
	getNum >> num;

	cout << "What do you want to name your new pet?" << endl;
	cout << "Name: ";
	string userInput;
	cin >> userInput;
	switch (num) {
	case 1: 
	{
		MiniDino* newDino = new MiniDino(userInput);
		saveInfo(newDino, saves);
		return newDino;
		break;
	}
	case 2: 
	{
		Cat* newCat = new Cat(userInput);
		saveInfo(newCat, saves);
		return newCat;
		break;
	}
	case 3:
	{
		Frog* newFrog = new Frog(userInput);
		saveInfo(newFrog, saves);
		return newFrog;
		break;
	}
	}
	return new Frog("ERROR"); // Returns this frog if something goes wrong
}

Pet* displayMenu(vector<Pet*>& saves) {
	cout << flush;
	system("CLS");
	if (saves.size() >= 1) {
		cout << "Type in pet name to load in pet!" << endl;
		for (unsigned int i = 0; i < saves.size(); i++) {
			cout << "* Breed: " << saves.at(i)->getBreed() << " | Name: " << saves.at(i)->getName() << " *" << endl;
		}
		cout << endl << endl;
		cout << "* Type in \"graveyard\" to see the graveyard of dead pets *" << endl;
		cout << "* Or... type in \"new\" to create a new pet! *" << endl;
		cout << "Type here: ";
	}
	else {
		cout << "Type in \"new\" to create a new pet!" << endl;
		cout << "Type here: ";
	}
	string userInput;
	cin >> userInput;
	if (userInput == "new") {
			Pet* freshPet = newPet(userInput, saves);
			system("CLS");
			return freshPet;
	}
	else if (userInput == "graveyard") {
		graveYard(saves);
		cin >> userInput;
		displayMenu(saves);
	}
	else {
		for (unsigned int i = 0; i < saves.size(); i++) {
			if (userInput == saves.at(i)->getName()) {
				if (saves.at(i)->getDead()) {
					saves.at(i)->gone();
				}
				system("CLS");
				return saves.at(i);
			}
		}
		cout << "Invalid option input any button and click enter to try again" << endl;
		cin >> userInput;
		displayMenu(saves);

	}

}

void playMenu(Pet* currentPet) {
	currentPet->getStats();
	cout << setfill('-') << setw(15);
	cout << "" << endl;
	cout << "1. Play" << endl;
	cout << "2. Feed" << endl;
	cout << "3. Sleep" << endl;
	cout << "4. Quit Game" << endl;
	cout << setfill('-') << setw(15);
	cout << "" << endl;
	cout << "Enter an option from 1, 2, 3, or 4 to perform an action" << endl;
	cout << "Enter number here: ";

	string choice;
	cin >> choice;
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
		cout << "Invalid choice type 1, 2, or 3;" << endl;
		cout << "Number: ";
		cin >> choice;
	}
	int num;
	stringstream getNum(choice);
	getNum >> num;

	switch (num) {
	case 1:
	{
		currentPet->play();
		cout << "Input any key and click enter to continue" << endl;
		string buffer;
		cin >> buffer;
		break;
	}
	case 2:
	{
		currentPet->feed();
		cout << "Input any key and click enter to continue" << endl;
		string buffer;
		cin >> buffer;
		break;
	}
	case 3:
	{
		currentPet->sleep();
		cout << "Input any key and click enter to continue" << endl;
		string buffer;
		cin >> buffer;
		break;
	}
	case 4: 
	{
		cout << "Exiting game" << endl;
		exit (1);
		break;
	}
	default: 
	{
		cout << "Uh-Oh something is wrong";
		break;
	}
	}
}

void graveYard(vector<Pet*>& saves) {
	system("CLS");
	cout << setfill(' ') << setw(21);
	cout << "GRAVEYARD" << endl;
	cout << setfill('|') << setw(40);
	cout << " " << endl;
	cout << endl << endl;
	int deadCount = 0;
	for (unsigned int i = 0; i < saves.size(); i++) {
		if (saves.at(i)->getDead()) {
			deadCount += 1;
		}
	}
	if (deadCount > 0) {
		for (unsigned int i = 0; i < saves.size(); i++) {
			if (saves.at(i)->getDead()) {
				cout << "REST IN PEACE " << saves.at(i)->getName() << endl << endl;
			}
		}
		cout << "You killed " << deadCount << " pet/s with your negligence hope you're happy monster!!" << endl << endl;
	}
	else {
		cout << "All pets are alive and healthy!" << endl << endl;
	}

	cout << setfill('|') << setw(40);
	cout << " " << endl;
	cout << endl << endl;
	cout << "Input anything and click enter to go back to main menu" << endl;
}