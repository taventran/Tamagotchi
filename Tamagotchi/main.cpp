#include "Menu.h"
#include "SaveData.h"

/*
This game will only work on window devices due to my use of Sleep() and system() to work with the console
*/

int main() {
	vector<string>petData;
	vector<Pet*> savedPets;
	saveInformation(petData);
	getSavedPets(savedPets, petData);
	/*
	for (unsigned int i = 0; i < savedPets.size(); i++) {
		savedPets.at(i)->getStats(); // Used to test the save feature
	}
	*/
	
	Pet* currentPet = displayMenu(savedPets);

	while (true) {
		cout << flush;
		system("CLS");
		Sleep(500);
		for (unsigned int i = 0; i < savedPets.size(); i++) {
			savedPets.at(i)->getStats(); // Used to test the save feature
		}
		overWriteSaveFile(savedPets);
		playMenu(currentPet);
	}

	delete currentPet;

	return 0;
}