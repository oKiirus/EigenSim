#include "stdafx.h"

#include "System.h"
#include "Funcs.h"


System::System(ODESolver* initSolver) : solver(initSolver)
{
}

void System::addBody(Body* newBody)
{
	bodies.push_back(newBody);
}

void System::addBond(Bond* newBond)
{
	bonds.push_back(newBond);
}

void System::addConstraint(Bond* newConstraint)
{
	constraints.push_back(newConstraint);
}

void System::removeBody(Body* body)
{
	std::erase(bodies, body);
}

void System::removeBond(Bond* bond)
{
	std::erase(bonds, bond);
}

void System::removeConstraint(Bond* newConstraint)
{
	std::erase(constraints, newConstraint);
}



void System::update()
{

	for (Body* body : bodies) {

		body->oldState = body->getState();

		for (Bond* bond : bonds) {

			bond->apply(body);

		}

		solver->step(body->getStateRef());

		body->predictedState = body->getState();

	}

	for (Body* body : bodies) {

		
		
		for (Bond* constraint : constraints) {
			constraint->apply(body);
		}
		

		State newState = body->getState();

		body->setDerivative(1, ((newState.getPosition() - body->oldState.getPosition()) / (solver->deltaTimeMult * State::frameDeltaTime)));
	}
}
