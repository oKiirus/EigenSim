#include "stdafx.h"
#include "Animal.h"



void Animal::makeNoise()
{
	std::cout << "the animal says: " << noise;
}


Animal::Animal(double newNoise) {
	noise = newNoise;
}
