#pragma once
#include "MiniDino.h"
#include "Cat.h"

struct pet {
	string breed = "Cat";
	string name = "nothing";
	int hunger = 0;
	int weight = 0;
	int height = 0;
	int boredom = 0;
	int sleepiness = 0;
};

void saveInformation(vector<string>& data);

void loadInPet(pet p, vector<Pet*>& saves);

void getSavedPets(vector<Pet*>& saves, vector<string>& data);

void overWriteSaveFile(vector<Pet*>& saves);

void saveInfo(Pet* newPet, vector<Pet*>& saves);