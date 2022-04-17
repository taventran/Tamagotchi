#include "MiniDino.h"

MiniDino::MiniDino(string name) {
	breed = "Mini Dino";
	this->name = name;
	hunger = 50;
	boredomLevels = 0;
	sleepiness = 0;
	setWeightAndHeight();
}

MiniDino::MiniDino(string _n, int _h, int _w, int _he, int _b, int _s) {
	breed = "Mini Dino";
	name = _n;
	hunger = _h;
	weight = _w;
	height = _he;
	boredomLevels = _b;
	sleepiness = _s;
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

// TODO: finish these game loop functions;

void MiniDino::play() {
	system("CLS");
	if (boredomLevels == 0){
		cout << "You took " << name << " for a walk! they were already content, but they appreciate the walk anyways :)" << endl;
	}
	else {
		cout << "You took " << name << " for a walk! they seem more content now!" << endl;
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
	if (hunger == 0) {
		cout << name << "'s is not hungry!" << endl;
	}
	else if (hunger >= 50) {
		foodAnimation();
		reduceHunger(50);
		cout << name << "'s current hunger: " << hunger << endl;
	}
	else {
		foodAnimation();
		hunger = 0;
		cout << name << "'s current hunger: " << hunger << endl;
	}
}
void MiniDino::sleep() {
	if (sleepiness == 0) {
		cout << name << " is not tired at all! they refuse to sleep" << endl;
	}
	else {
		cout << name << " is ready to go to bed" << endl;
	}
}