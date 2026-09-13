#pragma once
#include "Bond.h"
class DistanceConstraint :
    public Bond
{
public:
	
	Body* affectedBody;

	Body* other;

	double targetDistance;

	DistanceConstraint(Body* initAffectedBody, Body* initOtherBody, double initDistance);

	bool isAffected(const Body* body) const override {
		return body == affectedBody;
	}

	State getChanges(Body* body) const override {

		State change;


		State bState = body->predictedState;
		State oState = other->predictedState;

		double bCompliance = affectedBody->getAttributes().compliance;
		double oCompliance = other->getAttributes().compliance;

		Arrow d = oState.getPosition() - bState.getPosition();

		double distance = d.size();

		Arrow n = d.normalize();

		Arrow deltaPosition = n * (distance - targetDistance) * ((bCompliance) / (bCompliance + oCompliance)) / 2;

		change.setPosition(deltaPosition);

		return change;
	}
};

