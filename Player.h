#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "rapidxml.hpp"
#include "MapItem.h"
#include "Room.h"
#include "Map.h"

using namespace std;
using namespace rapidxml;

class Player {
public:
	Player(Room *);
	virtual ~Player();
	Room * getRoom();
    void changeRoom(Map *,string);
    bool hasItem(string);
    void showInventory();
    void removeItem(string);
    void addItem(string item);
private:
	Room * room;
	vector<string> inventoryVec;
};

#endif /* PLAYER_H_ */
