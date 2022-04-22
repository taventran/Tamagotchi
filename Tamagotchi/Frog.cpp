#include "Frog.h"

Frog::Frog(string name) {
	this->name = name;
	breed = "Frog";
	hunger = 10;
	boredomLevels = 20;
	maximumBoredomLevels = 100;
	maximumHungerLevels = 150;
	maximumSleepinessLevels = 10;
	sleepiness = 0;
	setWeightAndHeight();
	dead = false;
}

Frog::Frog(string _n, int _h, int _w, int _he, int _b, int _s, bool _d) {
	breed = "Frog";
	name = _n;
	hunger = _h;
	weight = _w;
	height = _he;
	boredomLevels = _b;
	maximumBoredomLevels = 100;
	maximumHungerLevels = 150;
	maximumSleepinessLevels = 10;
	sleepiness = _s;
	dead = _d;
}

void Frog::setWeightAndHeight() {
	srand(time(0));
	int randWeight = rand() % 5 + 5;
	int randHeight = rand() % 6 + 3;
	weight = randWeight;
	height = randHeight;
}

void Frog::displayPet() const {
	ifstream frogFile("frog.txt"); // Frog artwork found https://asciiart.website/index.php?art=animals/frogs
	if (frogFile.fail()) {
		cout << "Missing cat.txt file!";
	}
	cout << endl;
	string frogArt;
	while (getline(frogFile, frogArt)) {
		cout << frogArt << endl;
	}
	cout << endl << endl;
}

void Frog::getStats() const {
	cout << setfill(' ') << setw(18);
	cout << "Frog Pet" << endl;
	cout << setfill('-') << setw(28);
	cout << "" << endl;
	cout << name << "'s hunger: " << hunger << "/60" << endl;
	cout << name << "'s boredom levels: " << boredomLevels << "/100" << endl;
	cout << name << "'s sleepiness: " << sleepiness << "/10" << endl;
	cout << name << "'s height: " << height << " inches " << endl;
	cout << name << "'s weight: " << weight << " pounds " << endl;
	cout << setfill('-') << setw(28);
	cout << "" << endl;
	cout << setfill(' ');
	displayPet();
}

void Frog::play() {
	sleepiness += 3;
	addHunger(weight);
	system("CLS");
	ifstream frogPlay("frogplay.txt"); // frog art found at https://www.asciiart.eu/animals/frogs by Igbeard
	if (frogPlay.fail()) {
		cout << "Missing frogplay.txt!" << endl;
	}
	string frogArt;
	while (getline(frogPlay, frogArt)) {
		cout << frogArt << endl;
	}
	if (boredomLevels = 0) {
		cout << name << " was not bored but still roleplayed as a wizard!" << endl;
	}
	else if (boredomLevels < 50) {
		boredomLevels = 0;
		cout << name << " roleplayed as a wizard" << endl << endl;
	}
	else {
		boredomLevels -= 50;
		cout << name << " found some other cats to chill with at a lovely fence." << endl << endl;
	}

}

void Frog::feed() {
	sleepiness += 5;
	boredomLevels += 20;
	if (hunger == 0) {
		cout << name << "'s is not hungry!" << endl;
	}
	else if (hunger >= 50) {
		foodAnimation();
		hunger -= 50;
		cout << name << "'s current hunger: " << hunger << endl;
	}
	else {
		foodAnimation();
		hunger = 0;
		cout << name << "'s current hunger: " << hunger << endl;
	}
}

void Frog::sleep() {
	if (sleepiness = 0) {
		cout << name << " is not tired at all! they refuse to sleep" << endl;
	}
	else {
		cout << flush;
		system("CLS");
		string frogArt;
		for (int i = 0; i < 3; i++) {
			system("CLS");
			ifstream sleepingfrogFile("frogsleep.txt"); // Sleeping cat art found at https://www.asciiart.eu/animals/cats by Alex Lee.
			ifstream sleepingfrogFile2("frogsleep2.txt");
			ifstream sleepingfrogFile3("frogsleep3.txt");
			while (getline(sleepingfrogFile, frogArt)) {
				cout << frogArt << endl;
			}
			cout << flush;
			Sleep(700);
			system("CLS");
			while (getline(sleepingfrogFile2, frogArt)) {
				cout << frogArt << endl;
			}
			cout << flush;
			Sleep(400);
			system("CLS");
			while (getline(sleepingfrogFile3, frogArt)) {
				cout << frogArt << endl;
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
		addBoredom(20);
		addHunger(weight);
	}
}
