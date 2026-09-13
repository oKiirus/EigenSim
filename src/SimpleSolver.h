#pragma once
#include "ODESolver.h"
class SimpleSolver : public ODESolver
{

	void step(State& state) override {

		for (int dot = 0; dot < state.size(); dot++) {
			double dt = deltaTimeMult * State::frameDeltaTime;
			Arrow value = state.getDerivative(dot);
			Arrow derivative = state.getDerivative(dot + 1);

			state.setDerivative(dot, value + derivative * dt);
		}

	}
};

