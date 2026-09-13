#include "stdafx.h"

#include "Camera.h"
#include "Body.h"
#include "Renderable.h"



void Camera::renderBody(sf::RenderWindow& window, const Body* body) 
{
	Renderable* sprite = body->getRenderable();
	Arrow bodyPosition = body->getAttributes().state.getPosition();

	Arrow cameraPosition = getAttributes().state.getPosition();

	double x = bodyPosition.get(0) - cameraPosition.get(0);
	double y = bodyPosition.get(1) - cameraPosition.get(0);

	sprite->render(window, x, y);
}
