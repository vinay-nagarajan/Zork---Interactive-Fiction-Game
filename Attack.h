#ifndef ATTACK_H_
#define ATTACK_H_

#include <string>
#include <vector>

#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Attack {
public:
	Attack(xml_node<char> *);
	virtual ~Attack();
	string conditionObj;
	string conditionStatus;
	string printght;
	string printMsg;
	vector<string> actionVec;
private:
};

#endif /* ATTACK_H_ */
