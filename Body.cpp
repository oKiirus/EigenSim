#include "stdafx.h"

#include "Body.h"



ObjectAttributes Body::getAttributes() const
{
	return attributes;
}

State Body::getState() const
{
	return attributes.state;
}

State& Body::getStateRef()
{
	return attributes.state;
}

ObjectAttributes& Body::getAttributesRef()
{
	return attributes;
}

void Body::setCharge(double newCharge)
{
	attributes.charge = newCharge;
}

void Body::setCompliance(double newCompliance)
{
	attributes.compliance = newCompliance;
}


Renderable* Body::getRenderable() const
{
	return sprite;
}

void Body::setDerivative(int dot, Arrow newDerivative)
{
	attributes.state.setDerivative(dot, newDerivative);
}

Arrow Body::getDerivative(int dot) const
{
	return attributes.state.getDerivative(dot);
}

void Body::setDeltaTime(double newDeltaTime)
{
	attributes.state.setDeltaTime(newDeltaTime);
}

double Body::getDeltaTime() const
{
	return getAttributes().state.getDeltaTime();
}
