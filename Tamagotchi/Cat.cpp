#include "Cat.h"

Cat::Cat(string name) {
	breed = "Cat";
	this->name = name;
	hunger = 20;
	boredomLevels = 20;
	maximumBoredomLevels = 100;
	maximumHungerLevels = 150;
	maximumSleepinessLevels = 15;
	sleepiness = 0;
	setWeightAndHeight();
	dead = false;
}

Cat::Cat(string _n, int _h, int _w, int _he, int _b, int _s) {
	breed = "Cat";
	name = _n;
	hunger = _h;
	weight = _w;
	height = _he;
	boredomLevels = _b;
	maximumBoredomLevels = 100;
	maximumHungerLevels = 150;
	maximumSleepinessLevels = 15;
	sleepiness = _s;
	dead = false;
}

void Cat::setWeightAndHeight() {
	srand(time(0));
	int randWeight = rand() % 20 + 20;
	int randHeight = rand() % 12 + 14;
	weight = randWeight;
	height = randHeight;
}

void Cat::displayPet() const {
	ifstream catFile("cat.txt"); // Cat artwork found https://www.asciiart.eu/animals/cats
	if (catFile.fail()) {
		cout << "Missing cat.txt file!";
	}
	cout << endl;
	string catArt;
	while (getline(catFile, catArt)) {
		cout << catArt << endl;
	}
	cout << endl << endl;
}

void Cat::getStats() const {
	cout << setfill(' ') << setw(18);
	cout << "Cat Pet" << endl;
	cout << setfill('-') << setw(28);
	cout << "" << endl;
	cout << name << "'s hunger: " << hunger << "/150" << endl;
	cout << name << "'s boredom levels: " << boredomLevels << "/100" << endl;
	cout << name << "'s sleepiness: " << sleepiness << "/15" << endl;
	cout << name << "'s height: " << height << " inches " << endl;
	cout << name << "'s weight: " << weight << " pounds " << endl;
	cout << setfill('-') << setw(28);
	cout << "" << endl;
	cout << setfill(' ');
	displayPet();
}

// TODO: finish these game loop functions;

void Cat::play() {
	addHunger(weight);
	sleepiness += 5;
	system("CLS");
	if (boredomLevels == 0) {
		cout << name << " is already content but they'll go to hangout with their friends anyways." << endl << endl;
	}
	else if (boredomLevels < 50) {
		boredomLevels = 0;
		cout << name << " found some other cats to chill with at a lovely fence." << endl << endl;
	}
	else {
		boredomLevels -= 50;
		cout << name << " found some other cats to chill with at a lovely fence." << endl << endl;
	}
	ifstream catPlayFile("catplay.txt"); // cat ascii art found at https://www.asciiart.eu/animals/cats
	if (catPlayFile.fail()) {
		cout << "Missing catplay.txt file!";
	}
	string catArt;
	while (getline(catPlayFile, catArt)) {
		cout << catArt << endl;
	}
	cout << endl << endl;
}

void Cat::feed() {
	sleepiness += 5;
	boredomLevels += 10;
	foodAnimation();
}

void Cat::sleep() {
	if (sleepiness = 0) {
		cout << name << " is not tired at all! they refuse to sleep" << endl;
	}
	else {
		cout << flush;
		system("CLS");
		string catArt;
		for (int i = 0; i < 3; i++) {
			system("CLS");
			ifstream sleepingcatFile("catsleep.txt"); // Sleeping cat art found at https://www.asciiart.eu/animals/cats by Alex Lee.
			ifstream sleepingcatFile2("catsleep2.txt");
			ifstream sleepingcatFile3("catsleep3.txt");
			while (getline(sleepingcatFile, catArt)) {
				cout << catArt << endl;
			}
			cout << flush;
			Sleep(700);
			system("CLS");
			while (getline(sleepingcatFile2, catArt)) {
				cout << catArt << endl;
			}
			cout << flush;
			Sleep(400);
			system("CLS");
			while (getline(sleepingcatFile3, catArt)) {
				cout << catArt << endl;
			}
			cout << flush;
			Sleep(500);
			system("CLS");

		}
		cout << flush;
		Sleep(800);
		system("CLS");
		sleepiness = 0;
		cout << name << " is no longer tired" << endl;
		addBoredom(40);
		addHunger(weight);
	}
}
