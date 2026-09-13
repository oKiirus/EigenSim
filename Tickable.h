#pragma once
#include <vector>
class Tickable
{

public:
	static void tickListeners();

	void listen();
	void ignore();
protected:
	inline static std::vector<Tickable*> tickedList;

	

	virtual void tick() = 0;

	
};

