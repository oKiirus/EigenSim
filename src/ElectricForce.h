#pragma once
#include "Bond.h"
class ElectricForce : public Bond
{

public:
	double k = 0.1;
	std::vector<Body*> bodies;

	ElectricForce(std::vector<Body*>& bodiesRef);

	bool isAffected(const Body* body) const override {
		return true;
	}

	State getChanges(Body* body) const override {
		State change;
		State bState = body->getState();
		
		for (Body* other : bodies) {
			if (other == body) continue;
			State oState = other->getState();
			Arrow d( bState.getPosition() - oState.getPosition() );
			double squared_distance = std::pow(d.size(), 2);
			d.normalize();

			double oCharge = other->getAttributes().charge;
			double charge = body->getAttributes().charge;
			
			change.setVelocity( change.getVelocity()  + (d * (charge * oCharge) / squared_distance) * k);
		}
		
		std::cout << change.getVelocity() << "\n";

		return change;
	}
};

