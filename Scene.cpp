#include "stdafx.h"

#include "Scene.h"
Scene::Scene(sf::RenderWindow& initWindow, ODESolver* initSolver) : System(initSolver), window(initWindow) {}