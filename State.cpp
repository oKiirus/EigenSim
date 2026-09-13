#include "stdafx.h"

#include "State.h"

//getters
Arrow State::getDerivative(int dot) const
{
    if (dot < size()) {
        return state_data[dot];
    }
    else {
        return Arrow();
    }
}

double State::getDeltaTime()
{
    return deltaTime;
}

Arrow State::getPosition() const
{
    return getDerivative(0);
}

Arrow State::getVelocity() const
{
    return getDerivative(1);
}

Arrow State::getAcceleration() const
{
    return getDerivative(2);
}

Arrow State::getJerk() const
{
    return getDerivative(3);
}

Arrow State::getSnap() const
{
    return getDerivative(4);
}

Arrow State::getCrackle() const
{
    return getDerivative(5);
}

Arrow State::getPop() const
{
    return getDerivative(6);
}


//setters
void State::setDerivative(int dot, const Arrow& arrow)
{
    if (dot < size()) {
        state_data[dot] = arrow;
    }
    else {
        extend(dot + 1);
        state_data[dot] = arrow;
    }
}

void State::setDeltaTime(double newDeltaTime)
{
    deltaTime = newDeltaTime;
}

void State::setPosition(const Arrow& pos)
{
    setDerivative(0, pos);
}

void State::setVelocity(const Arrow& vel)
{
    setDerivative(1, vel);
}

void State::setAcceleration(const Arrow& acc)
{
    setDerivative(2, acc);
}

void State::setJerk(const Arrow& jerk)
{
    setDerivative(3, jerk);
}

void State::setSnap(const Arrow& snap)
{
    setDerivative(4, snap);
}

void State::setCrackle(const Arrow& crack)
{
    setDerivative(5, crack);
}

void State::setPop(const Arrow& pop)
{
    setDerivative(6, pop);
}



//constructors
State::State() {}

State::State(const State& state)
{
    state_data = std::vector<Arrow>(state.state_data.size());

    for (int i = 0; i < state_data.size(); i++) {
        setDerivative(i, state.getDerivative(i));
    }

    deltaTime = state.deltaTime;
}

State::State(const Arrow& pos)
{
    setPosition(pos);
}

State::State(const Arrow& pos, const Arrow& vel) : State((Arrow)pos)
{
    setVelocity(vel);
}

State::State(const Arrow& pos, const Arrow& vel, const Arrow& acc) : State(pos, vel)
{
    
    setAcceleration(acc);
}

State::State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk) : State(pos, vel, acc)
{
    
    setJerk(jerk);
}

State::State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk, const Arrow& snap) : State(pos, vel, acc, jerk)
{
    
    setSnap(snap);
}

State::State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk, const Arrow& snap, const Arrow& crack) : State(pos, vel, acc, jerk, snap)
{
    
    setCrackle(crack);
}

State::State(const Arrow& pos, const Arrow& vel, const Arrow& acc, const Arrow& jerk, const Arrow& snap, const Arrow& crack, const Arrow& pop) : State(pos, vel, acc, jerk, snap, crack)
{
    
    setPop(pop);
}

void State::extend(int newSize)
{
    if (newSize <= size()) return;

    State temp((State)(*this));

    state_data = std::vector(newSize, Arrow());

    for (int i = 0; i < newSize; i++) {
        int stateSize = temp.state_data.size();
        if (i < stateSize) {
            setDerivative(i, temp.getDerivative(i));
        }
        else {
            setDerivative(i, Arrow());
        }
    }
}


int State::size() const
{
    return (int) state_data.size();
}

void State::print() const
{
    for (int i = 0; i < size(); i++) {
        getDerivative(i).print();
    }
}
