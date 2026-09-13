#pragma once
#include "Body.h"
#include <vector>

class Bond
{
public:
	std::vector<Body*> whitelist;
	std::vector<Body*> blacklist;

	

	virtual bool isAffected(const Body* body) const = 0;
	virtual State getChanges(Body* body) const = 0;

	void addToWhitelist(Body* newBody);
	void addToBlacklist(Body* newBody);
public:
	void apply(Body* body);
};

