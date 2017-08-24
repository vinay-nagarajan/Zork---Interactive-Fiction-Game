#ifndef CONDITION_H_
#define CONDITION_H_

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Condition {
public:
	Condition(xml_node<char> *);
	virtual ~Condition();
	string getHas() const;
	string getObject() const;
	string getOwner()const;
	string getStatus() const;
	int isType() const;
private:
	string has;
	string object;
	string owner;
	string status;
};

#endif /* CONDITION_H_ */
