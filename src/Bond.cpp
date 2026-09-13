#include "stdafx.h"

#include "Bond.h"


void Bond::addToWhitelist(Body* newBody)
{
	whitelist.push_back(newBody);
}

void Bond::addToBlacklist(Body* newBody)
{
	blacklist.push_back(newBody);
}

void Bond::apply(Body* body)
{
	if (std::find(whitelist.begin(), whitelist.end(), body) == whitelist.end()) { //not in whitelist
		if (!isAffected(body) || std::find(blacklist.begin(), blacklist.end(), body) != blacklist.end()) { //not affected or in blacklist
			return;
		}
	}


	State changes = getChanges(body);

	for (int dot = 0; dot < changes.size(); dot++) {
		body->setDerivative(dot, body->getDerivative(dot) + changes.getDerivative(dot));
		std::cout << changes.getDerivative(dot) << "\n";
	}

}
