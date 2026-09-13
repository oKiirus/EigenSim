#include "stdafx.h"

#include "Particle.h"
#include "Circle.h"

Particle::Particle() : Particle(0, 0, 10, sf::Color::White) {

}

Particle::Particle(double x, double y, double radius, sf::Color fillColor)
{
	sprite = new Circle(x, y, radius, fillColor);
}

Particle::Particle(double x, double y, double radius, sf::Color fillColor, sf::Color outlineColor, double outlineThickness)
{
	sprite = new Circle(x, y, radius, fillColor, outlineColor, outlineThickness);
}


