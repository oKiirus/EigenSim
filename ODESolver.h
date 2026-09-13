#pragma once
#include "State.h"
class ODESolver
{
public:
	double deltaTimeMult = 1;
	virtual void step(State& state) = 0;
};

