#pragma once
#include "Bond.h"
class GravitationalForce : public Bond
{
	bool isAffected(const Body* body) const override {
		return true;
	}

	State getChanges(Body* body) const override {
		State state;
		State bState = body->getState();
		double gravity;

		gravity = 1;
		state.setVelocity(Arrow({ 0, gravity}));

		return state;
	}
};

