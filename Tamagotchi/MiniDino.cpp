#include "MiniDino.h"

MiniDino::MiniDino(string name) {
	breed = "Mini Dino";
	this->name = name;
	hunger = 50;
	boredomLevels = 20;
	maximumBoredomLevels = 100;
	maximumHungerLevels = 200;
	maximumSleepinessLevels = 20;
	sleepiness = 5;
	setWeightAndHeight();
	dead = false;
}

MiniDino::MiniDino(string _n, int _h, int _w, int _he, int _b, int _s, bool _d) {
	breed = "Mini Dino";
	maximumBoredomLevels = 100;
	maximumHungerLevels = 200;
	maximumSleepinessLevels = 20;
	name = _n;
	hunger = _h;
	weight = _w;
	height = _he;
	boredomLevels = _b;
	sleepiness = _s;
	dead = _d;
}

void MiniDino::setWeightAndHeight() {
	srand(time(0));
	int randWeight = rand() % 20 + 30;
	int randHeight = rand() % 12 + 24;
	weight = randWeight;
	height = randHeight;
}

void MiniDino::displayPet() const{
	ifstream dinosaurFile("dinosaur.txt"); // Dinosaur ascii art found at https://asciiart.cc/view/12219
	string test;
	if (dinosaurFile.fail()) {
		cout << "Missing dinosaur.txt file!";
	}
	cout << endl;
	string dinoArt;
	while (getline(dinosaurFile, dinoArt)) {
		cout << dinoArt << endl;
	}
	cout << endl << endl;
}

void MiniDino::getStats() const {
	cout << setfill(' ') << setw(22);
	cout << "Mini Dinosaur Pet" << endl;
	cout << setfill('-') << setw(28);
	cout << "" << endl;
	cout << name << "'s hunger: " << hunger << "/200" << endl;
	cout << name << "'s boredom levels: " << boredomLevels << "/100" << endl;
	cout << name << "'s sleepiness: " << sleepiness << "/20" << endl;
	cout << name << "'s height: " << height << " inches " << endl;
	cout << name << "'s weight: " << weight << " pounds " << endl;
	cout << setfill('-') << setw(28);
	cout << "" << endl;
	cout << setfill(' ');
	displayPet();
}


void MiniDino::play() {
	sleepiness += 5;
	addHunger(this->weight);
	system("CLS");
	if (boredomLevels == 0){
		cout << "You took " << name << " for a walk! they were already content, but they appreciate the walk anyways :)" << endl;
	}
	else if (boredomLevels < 50) {
		cout << "You took " << name << " for a walk! they seem more content now!" << endl;
	}
	else {
		cout << "You took " << name << " for a walk! they seem more content now!" << endl;
		boredomLevels -= 50;
	}
	ifstream dinosaurFile("dinoplay.txt"); // Dinosaur ascii art found at https://asciiart.website/index.php?art=animals/reptiles/dinosaurs
	string test;
	if (dinosaurFile.fail()) {
		cout << "Missing dinoplay.txt file!";
	}
	cout << endl;
	string dinoArt;
	while (getline(dinosaurFile, dinoArt)) {
		cout << dinoArt << endl;
	}
	cout << name << "'s boredom level is now: " << boredomLevels << endl;
	cout << endl << endl;
}

void MiniDino::feed() {
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
void MiniDino::sleep() {
	boredomLevels += 20;
	system("CLS");
	addHunger(weight);
	if (sleepiness == 0) {
		cout << name << " is not tired at all! they refuse to sleep" << endl;
	}
	else {

		string dinoSleep;
		for (int i = 0; i < 3; i++) {
			cout << flush;
			system("CLS");
			ifstream sleepingdinoFile("dinosaursleep.txt"); // Sleeping dinosaur art based off https://asciiart.website/index.php?art=animals/reptiles/dinosaurs
			ifstream sleepingdinoFile2("dinosaursleep2.txt");
			ifstream sleepingdinoFile3("dinosaursleep3.txt");
			while (getline(sleepingdinoFile, dinoSleep)) {
				cout << dinoSleep << endl;
			}
			cout << flush;
			Sleep(700);
			system("CLS");
			while (getline(sleepingdinoFile2, dinoSleep)) {
				cout << dinoSleep << endl;
			}
			cout << flush;
			Sleep(400);
			system("CLS");
			while (getline(sleepingdinoFile3, dinoSleep)) {
				cout << dinoSleep << endl;
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