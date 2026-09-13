#pragma once
#include "ObjectAttributes.h"
#include "Renderable.h"
#include "State.h"

class Body
{

protected:
	ObjectAttributes attributes;
	Renderable* sprite;

public:
	State oldState;
	State predictedState;

	ObjectAttributes getAttributes() const;
	State getState() const;
	State& getStateRef();
	ObjectAttributes& getAttributesRef();
	void setCharge(double newCharge);
	void setCompliance(double newCompliance);
	Renderable* getRenderable() const;
	void setDerivative(int dot, Arrow newDerivative);
	Arrow getDerivative(int dot) const;
	void setDeltaTime(double newDeltaTime);
	double getDeltaTime() const;

	virtual ~Body() = default;
};

