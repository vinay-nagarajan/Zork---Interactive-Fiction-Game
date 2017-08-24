#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <sstream>
#include <cstdlib>
#include "Map.h"
#include "Player.h"
#include "Container.h"
#include "Item.h"
#include "Attack.h"

using namespace std;
using namespace rapidxml;

class GameManager {
public:
	GameManager(Map *, Player *);
	virtual ~GameManager();
	void gameLoop();
private:
	Map * map;
	Player * player;
	bool end;
	void putItem(string,string);
	void takeItem(string);
	void openContainer(string);
	void openExit();
	void readItem(string);
	void dropItem(string);
	void turnonItem(string);
	void addObject(string, string);
	void deleteObject(string);
	void attackCreature(string, string);
	void executeActionVec(vector<string>);
	void checkCommand(string);
	void endGame();
	bool checkConditionVec(Trigger * trigger);
	bool checkCondition(Condition * condition);
	bool checkTriggers(string command);
protected:
	void additionofObject(string, string);
    void deletionofObject(string);
};

#endif /* GAMEMANAGER_H_ */
