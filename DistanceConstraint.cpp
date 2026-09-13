#include "stdafx.h"

#include "DistanceConstraint.h"

DistanceConstraint::DistanceConstraint(Body* initAffectedBody, Body* initOtherBody, double initDistance)
	: affectedBody(initAffectedBody), other(initOtherBody), targetDistance(initDistance)
{
}


