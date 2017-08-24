#ifndef ITEM_H_
#define ITEM_H_

#include <vector>
#include <iostream>
#include "rapidxml.hpp"
#include "MapItem.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Item : public MapItem {
public:
	Item(xml_node<> *);
	virtual ~Item();
	void read();
	string getTurnonPrint();
	string getTurnonAction();
	bool hasTurnon();
	vector<Trigger *> triggerVec;
private:
	string writing;
	bool hasTurnoff();
	string turnon_print;
	string turnon_action;
};

#endif /* ITEM_H_ */
