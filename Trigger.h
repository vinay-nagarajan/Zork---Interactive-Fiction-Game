
#ifndef TRIGGER_H_
#define TRIGGER_H_

#include <iostream>
#include <string>
#include <vector>

#include "rapidxml.hpp"
#include "Condition.h"

using namespace std;
using namespace rapidxml;

class Trigger {
public:
	Trigger(xml_node<char> *);
	virtual ~Trigger();
	const Condition * getCondition();
	void setLocation(string);
	string getLocation();
	string getCommand();
	bool expired;
	string getType();
	void printMessage();
	vector<string> actionVec;
	vector<Condition *> conditionVec;
private:
	string type;
	string printMsg;
	string location;
	string command;
};

#endif /* TRIGGER_H_ */
