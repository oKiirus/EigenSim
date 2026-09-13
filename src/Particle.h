#pragma once
#include "Body.h"
#include "Tickable.h"
#include <iostream>

class Particle : public Body, public Tickable
{

	
public: 
	Particle();
	Particle(double x, double y, double radius, sf::Color fillColor);
	Particle(double x, double y, double radius, sf::Color fillColor, sf::Color outlineColor, double outlineThickness);

	void tick() {

	}
};

