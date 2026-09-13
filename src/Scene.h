#pragma once

#include "Camera.h"
#include "System.h"
#include "Tickable.h"
#include "ODESolver.h"

class Scene : public System
{
	Camera camera;
	sf::RenderWindow& window;

public:
	Scene(sf::RenderWindow& initWindow, ODESolver* initSolver);

	void render() {
		for (Body* body : bodies) {
			camera.renderBody(window, body);
		}
	}

	
};

