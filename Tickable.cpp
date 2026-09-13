#include "stdafx.h"

#include "Tickable.h"


void Tickable::tickListeners()
{
	for (Tickable* ticked : tickedList) {
		ticked->tick();
	}
}


void Tickable::listen()
{
	tickedList.push_back(this);
}

void Tickable::ignore()
{
	
	std::erase(tickedList, this);
	
}



