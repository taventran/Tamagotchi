#ifndef CAT_H
#define CAT_H

#include "Pet.h"

class Cat : public Pet {
	public: 
		Cat(string name);
		Cat(string, int, int, int, int, int);
		void setWeightAndHeight();
		void getStats() const;
		void displayPet() const;
		void play();
		void feed();
		void sleep();
};




#endif
