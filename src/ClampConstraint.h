#pragma once
#include "Body.h"
#include "Funcs.h"
class ClampConstraint
{
	std::vector<const Body*> confined;

	Arrow mins;
	Arrow maxes;

	ClampConstraint(Arrow mins, Arrow maxes);

	virtual bool isAffected(const Body* body) {
		return Funcs::vector_contains(confined, body);
	}

	virtual State getChanges(Body* body) {
		for (int i = 0; i < mins.size(); i++) {

		}
	}
};

