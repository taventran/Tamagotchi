#pragma once
#include "Cat.h"
#include "Frog.h"
#include "MiniDino.h"
#include "SaveData.h"
#include <vector>

Pet* displayMenu(vector<Pet*>& saves);

void playMenu(Pet* currentPet);

void graveYard(vector<Pet*>& saves);