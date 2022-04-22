#include "Pet.h"
#include <cmath>


void Pet::addHunger(int weight) {
	hunger += weight;
}

void Pet::reduceBoredom(int num) {
	boredomLevels -= num;
}

void Pet::addBoredom(int num) {
	boredomLevels += num;
}

void Pet::reduceSleepiness() {
	sleepiness = 0;
}

void Pet::addSleepiness(int num) {
	sleepiness += num;
}

bool Pet::isNeglected() {
	if (hunger > maximumHungerLevels) {
		dead = true;
		cout << "Your pet died because it was under fed!" << endl << endl;
	}
	if (sleepiness > maximumSleepinessLevels) {
		dead = true;
		cout << "Your pet died from lack of sleep!" << endl << endl;
	}
	if (boredomLevels > maximumBoredomLevels) {
		dead = true;
		cout << "Your pet ran away because you were boring." << endl << endl;
	}
	return dead;
}

void Pet::foodAnimation() {
	/*The way I implemented this function will only allow Windows users to use this function since I used the Sleep function*/
	cout << flush;
	system("CLS");
	string foodArt;
	for (int i = 0; i < 3; i++) {
		ifstream food("food.txt"); // Art found at https://www.asciiart.eu/food-and-drinks/apples by Hayley Jane Wakenshaw
		while (getline(food, foodArt)) {
			cout << foodArt << endl;
		}
		cout << flush;
		Sleep(700);
		system("CLS");
		/*
		ifstream chomp("chomp.txt"); // Art generated at https://patorjk.com/software/taag/#p=display&h=1&v=2&f=Big&t=CHOMP
		while (getline(chomp, foodArt)) {
			cout << foodArt << endl;
		}
		cout << flush;
		Sleep(800);
		system("CLS");
		*/
		ifstream eatenFood("eatenfood.txt"); // Art found at https://www.asciiart.eu/food-and-drinks/apples by Hayley Jane Wakenshaw
		while (getline(eatenFood, foodArt)) {
			cout << foodArt << endl;
		}
		cout << flush;
		Sleep(400);
		system("CLS");
	}
	ifstream yum("yum.txt"); // Art generated at https://patorjk.com/software/taag/#p=display&h=1&v=2&f=Big&t=CHOMP
	while (getline(yum, foodArt)) {
		cout << foodArt << endl;
	}

	cout << flush;
	Sleep(800);
	system("CLS");
}