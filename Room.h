#ifndef ROOM_H_
#define ROOM_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "rapidxml.hpp"
#include "MapItem.h"
#include "Border.h"
#include "Container.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Room : public MapItem {
public:
	Room(xml_node<> *);
	virtual ~Room();
	string getBorderRoom(string);
	string getType();
	bool hasItem(string);
	bool hasContainer(string);
	bool hasCreature(string);
	void addItem(string);

	void addCreature(string);
	void addContainer(string);
	void removeCreature(string creature);
	void removeContainer(string container);
	void removeItem(string);
	vector<Trigger *> triggerVec;
private:
	string type;
	vector<Border> borderVec;
	vector<string> containerVec;
	vector<string> itemVec;
	vector<string> creatureVec;

};

#endif /* ROOM_H_ */
