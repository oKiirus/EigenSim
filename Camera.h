#pragma once
#include "Body.h"
class Camera : public Body
{
public:
	void renderBody(sf::RenderWindow& window, const Body* body) ;
};

