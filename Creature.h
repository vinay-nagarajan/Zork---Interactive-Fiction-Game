

#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include "rapidxml.hpp"
#include "MapItem.h"
#include "Attack.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Creature : public MapItem {
public:
	Creature(xml_node<> *);
	virtual ~Creature();
	bool hasVulnerability(string item);
	bool hastoggling();
	Attack * getAttack();
	vector<Trigger *> triggerVec;
private:
	vector<string> vulnerabilityVec;
	Attack * attack;
};

#endif /* CREATURE_H_ */
