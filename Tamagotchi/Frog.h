#pragma once
#include "Pet.h"

class Frog : public Pet {
	public: 
		Frog(string name);
		Frog(string _n, int _h, int _w, int _he, int _b, int _s, bool _d);
		void setWeightAndHeight();
		void getStats() const;
		void displayPet() const;
		void play();
		void feed();
		void sleep();

};