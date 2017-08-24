#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "rapidxml.hpp"
#include "MapItem.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Container : public MapItem{
public:
	Container(xml_node<> *);
	virtual ~Container();
	bool canAccept(string);
	void addItem(string item);
	void contining();
	bool hasItem(string item);
	void removeItem(string item);
	void open();
	bool isOpen;
	vector<Trigger *> triggerVec;
private:
	vector<string> acceptVec; //items that can be placed in container
	vector<string> itemVec;   //items that are present inside container
};

#endif /* CONTAINER_H_ */
