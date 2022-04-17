#ifndef PET_H
#define PET_H
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> // Need random function
#include <ctime> // Need to get time to set random seed
#include <iomanip>
#include <sstream>
#include <windows.h> // Need sleep function to allow animation to work
#include <stdlib.h> // Need this to clear console
#include <vector>

using namespace std;

class Pet {
	public:
		virtual void setWeightAndHeight() = 0; // Each animal will have different random heights and weights
		virtual void getStats() const = 0; // Each animal will have different text displaying stats
		virtual void displayPet() const = 0; // Each pet will have different ascii art
		virtual void play() = 0; 
		virtual void feed() = 0;
		virtual void sleep() = 0;
		void reduceHunger(int num);
		void addHunger(int num);
		void reduceBoredom(int num);
		void addBoredom(int num);
		void reduceSleepiness();
		void addSleepiness(int num);
		void foodAnimation();



		string getName() {
			return name;
		}
		string getBreed() {
			return breed;
		}
		int getHunger() {
			return hunger;
		}
		int getWeight() {
			return weight;
		}
		int getHeight() {
			return height;
		}
		int getBoredomLevels() {
			return boredomLevels;
		}
		int getSleepiness() {
			return sleepiness;
		}

	protected:
		string breed;
		string name;
		int hunger = 0;
		int weight = 0;
		int height = 0;
		int boredomLevels = 0;
		int sleepiness = 0;
};

#endif