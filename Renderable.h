#pragma once
#include <SFML/Graphics.hpp>
class Renderable
{
	public:
		double x;
		double y;

		std::vector<Renderable> children;

		virtual void render(sf::RenderWindow& window, double x, double y) = 0;
};

