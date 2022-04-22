#ifndef MINI_H
#define MINI_H

#include "Pet.h"

class MiniDino : public Pet{
	public:
		MiniDino(string name);
		MiniDino(string, int, int, int, int, int, bool);
		void setWeightAndHeight();
		void getStats() const;
		void displayPet() const;
		void play();
		void feed();
		void sleep();
};


#endif