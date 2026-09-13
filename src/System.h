#pragma once
#include <vector>
#include "Body.h"
#include "Bond.h"
#include "Tickable.h"
#include "ODESolver.h"

class System 
{
	
public:
	ODESolver* solver;

	System(ODESolver* initSolver);

	std::vector<Body*> bodies;
	std::vector<Bond*> bonds;
	std::vector<Bond*> constraints;

	void addBody(Body* newBody);
	void addBond(Bond* newBond);
	void addConstraint(Bond* newConstraint);

	void removeBody(Body* newBody);
	void removeBond(Bond* newBond);
	void removeConstraint(Bond* newConstraint);


	void update();

};

