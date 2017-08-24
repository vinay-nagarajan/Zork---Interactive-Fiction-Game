#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include "rapidxml.hpp"
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "MapItem.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Map {
public:
	Map();
	virtual ~Map();
	void loadMap(string);
	Room * getRoom (string);
    Container * getContainer (string name);
    Item * getItem (string name);
	Creature * getCreature (string name);
	Container * getContainerWithItem(string item);
	Room * getRoomWithItem(string item);
	Room * getRoomWithCreature(string creature);
	Room * getRoomWithContainer(string container);
	MapItem * getObject(string name);
	vector<Room *> roomVec;
	vector<Item *> itemVec;
	vector<Container *> containerVec;
	vector<Creature *> creatureVec;
	vector<Trigger *> triggers;
private:
	xml_node<>* readFile(const string);	//read an xml file
};

#endif /* MAP_H_ */
