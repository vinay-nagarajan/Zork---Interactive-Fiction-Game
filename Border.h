#ifndef BORDER_H_
#define BORDER_H_

#include <string>
#include <iostream>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Border {
public:
	Border(xml_node<> *);
	virtual ~Border();
	string getName();
	string getTitle();
	string getDirection();
private:
	string direction;
	string name;
};

#endif /* BORDER_H_ */
