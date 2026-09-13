#pragma once
#include "Arrow.h"
#include <vector>
class State
{
public:
	std::vector<Arrow> state_data;
	
	double deltaTime = 1;



	inline static double frameDeltaTime;

	State();
	State(const State& state);
	State(const Arrow& pos);
	State(const Arrow& pos, const Arrow& vel);
	State(const Arrow& pos, const Arrow& vel, const Arrow& acc);
	State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk);
	State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk, const Arrow& snap);
	State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk, const Arrow& snap, const Arrow& crack);
	State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk, const Arrow& snap, const Arrow& crack, const Arrow& pop);
	

	//getters
	Arrow getPosition() const;
	Arrow getVelocity() const;
	Arrow getAcceleration() const;
	Arrow getJerk() const;
	Arrow getSnap() const;
	Arrow getCrackle() const;
	Arrow getPop() const;
	Arrow getDerivative(int dot) const;
	double getDeltaTime();

	//setters
	void setPosition(const Arrow& pos);
	void setVelocity(const Arrow& vel);
	void setAcceleration(const Arrow& acc);
	void setJerk(const Arrow& jerk);
	void setSnap(const Arrow& snap);
	void setCrackle(const Arrow& crack);
	void setPop(const Arrow& pop);
	void setDerivative(int dot, const Arrow& pos);
	void setDeltaTime(double newDeltaTime);

	void extend(int newOrder);
	int size() const;

	void print() const;

};

