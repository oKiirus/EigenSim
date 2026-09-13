#include "stdafx.h"

#include "Circle.h"



Circle::Circle(double initX, double initY, double initRadius, sf::Color initFillColor) : Circle(initX, initY, initRadius, initFillColor, sf::Color::Black, 0)
{
}

Circle::Circle(double initX, double initY, double initRadius, sf::Color initFillColor, sf::Color initOutlineColor, double initOutlineThickness) {
	sprite = sf::CircleShape();
	setRadius(initRadius);
	setLocation(initX, initY);
	setColor(initFillColor, initOutlineColor);
	setOutlineThickness(initOutlineThickness);
}

void Circle::setRadius(double newRadius)
{
	radius = newRadius;
	sprite.setRadius((float)newRadius);
}

void Circle::setX(double newX)
{
	x = newX;
}

void Circle::setY(double newY)
{
	y = newY;
}

void Circle::setLocation(double newX, double newY)
{
	setX(x);
	setY(y);
}

void Circle::setFillColor(sf::Color newFillColor)
{
	fillColor = newFillColor;
	sprite.setFillColor(newFillColor);
}

void Circle::setOutlineColor(sf::Color newOutlineColor)
{
	outlineColor = newOutlineColor;
	sprite.setOutlineColor(newOutlineColor);
}

void Circle::setOutlineThickness(double newOutlineThickness)
{
	outlineThickness = newOutlineThickness;
	sprite.setOutlineThickness((float)newOutlineThickness);
}

void Circle::setColor(sf::Color newFillColor, sf::Color newOutlineColor) {
	setFillColor(newFillColor);
	setOutlineColor(newOutlineColor);
}

