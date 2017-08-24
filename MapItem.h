#ifndef MAPITEM_H_
#define MAPITEM_H_

#include <string>

using namespace std;

class Room;
class Item;
class Container;
class Creature;

class MapItem{
public:
	MapItem();
	virtual ~MapItem();
	string getName();
	string getTitle();
	string getStatus();
	string getDescription();
	void updateStatus(string);
protected:
	string name;
	string status;
	string description;
	string location;
};


#endif /* MAPITEM_H_ */
