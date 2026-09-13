#pragma once
#include "Renderable.h"
#include <SFML/Graphics.hpp>

class Circle : public Renderable
{	
private:
	double radius;
	sf::Color fillColor;
	sf::Color outlineColor;
	double outlineThickness;

	sf::CircleShape sprite;
		
	
public:

	Circle(double initX, double initY, double initRadius, sf::Color initFillColor);
	Circle(double initX, double initY, double initRadius, sf::Color initFillColor, sf::Color initOutlineColor, double initOutlineThickness);

	void setRadius(double newRadius);
	void setX(double newX);
	void setY(double newY);
	void setLocation(double newX, double newY);
	void setFillColor(sf::Color newColor);
	void setOutlineColor(sf::Color newColor);
	void setOutlineThickness(double newOutlineThickness);

	void setColor(sf::Color newFillColor, sf::Color newOutlineColor);

	void render(sf::RenderWindow& window, double offsetX, double offsetY) override {
		sprite.setPosition({ (float)(x + offsetX), (float)(y + offsetY) });
		window.draw(sprite);
	}
};

