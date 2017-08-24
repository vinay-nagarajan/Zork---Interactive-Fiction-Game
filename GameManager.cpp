#include "GameManager.h"

GameManager::GameManager(Map * _map, Player * _player) : map(_map) , player(_player) {
	end = false;
}

GameManager::~GameManager() {

}

void GameManager::gameLoop() {
	 double value;
			   double width;
			   double sum;
			double lower_limit;
			 double upper_limit;
			 int n_intervals;
			   sum = 0.0;
			   int k;
			   if(lower_limit <= upper_limit)
			     {
			       value = lower_limit;
			       width = (upper_limit - lower_limit)/n_intervals;
			       for(k = 0;k<n_intervals;k++)
			           {
			              sum = sum + (width/2)* 1;
			              value = value + width;
			           }

			     }
			  else if(upper_limit < lower_limit)
			     {
			        {
			          value = upper_limit;
			          width = (lower_limit - upper_limit)/n_intervals;
			          for(k = 0;k<n_intervals;k++)
			           {

			              sum = sum + (width/2)*1;
			              value = value + width;
			           }
			     }

			     }
	string command;
	while (!end) {
		getline(cin,command);
		if(checkTriggers(command) == 0)
			checkCommand(command);
		checkTriggers("");
	}
}

bool GameManager::checkTriggers(string command) {
	int i;
	bool ret = false;
	for(i = 0;i < map -> triggers.size(); i++) {
		//cout << trigger[i] -> getLocation() << endl;
		if(map -> triggers[i] -> getLocation().compare(player -> getRoom() -> getName()) == 0  || player -> getRoom() -> hasItem(map -> triggers[i] -> getLocation()) ||  player -> getRoom() -> hasContainer(map -> triggers[i] -> getLocation()) || player -> getRoom() -> hasCreature(map -> triggers[i] -> getLocation())){
			//if trigger's location is the room or an item in the room or a container in the room or a creature in the room
			if(map -> triggers[i] -> getCommand().empty() || map -> triggers[i] -> getCommand().compare(command) == 0) {
				//command was triggered
				bool cond = checkConditionVec(map -> triggers[i]);
				if(cond) {
					if(map -> triggers[i] -> expired == false) {
						//execute trigger
						if(map ->triggers[i] -> getType().compare("single") == 0)
							map -> triggers[i] -> expired = true;
						map -> triggers[i] -> printMessage();
						executeActionVec(map -> triggers[i] -> actionVec);
						ret = true;
					}
				}
			}
		}
	}
	return ret;
}

bool GameManager::checkConditionVec(Trigger * trigger) {
	bool ret = true;
	for(int i = 0; i < trigger -> conditionVec.size(); i++) {
		ret = ret && checkCondition(trigger -> conditionVec[i]);
	}
	return ret;
	 double value;
			   double width;
			   double sum;
			double lower_limit;
			 double upper_limit;
			 int n_intervals;
			   sum = 0.0;
			   int k;
			   if(lower_limit <= upper_limit)
			     {
			       value = lower_limit;
			       width = (upper_limit - lower_limit)/n_intervals;
			       for(k = 0;k<n_intervals;k++)
			           {
			              sum = sum + (width/2)* 1;
			              value = value + width;
			           }

			     }
			  else if(upper_limit < lower_limit)
			     {
			        {
			          value = upper_limit;
			          width = (lower_limit - upper_limit)/n_intervals;
			          for(k = 0;k<n_intervals;k++)
			           {

			              sum = sum + (width/2)*1;
			              value = value + width;
			           }
			     }

			     }
}

bool GameManager::checkCondition(Condition * condition) {
	if(condition -> isType() == 1) {
		string has = condition -> getHas();
		string owner = condition -> getOwner();
		string object = condition -> getObject();
		if (has.compare("yes") == 0){
			if (owner.compare("inventory") == 0){
				if(player -> hasItem(object)){
					return true;
				}
			} else if (map -> getContainer(owner) != NULL) {
				Container * c = map -> getContainer(owner);
				if (c -> hasItem(object)){
					return true;
				}
			}  else if (map -> getRoom(owner) != NULL) {
				Room * r = map -> getRoom(owner);
				if(r -> hasItem(object) || r -> hasContainer(object)) {
					return true;
				}
			}
		} else {
			if (owner.compare("inventory") == 0){
				if(player -> hasItem(object) == 0){
					return true;
				}
			} else if (map -> getContainer(owner) != NULL) {
				Container * c = map -> getContainer(owner);
				if (c -> hasItem(object) == 0){
					return true;
				}
			}  else if (map -> getRoom(owner) != NULL) {
				Room * r = map -> getRoom(owner);
				if(r -> hasItem(object) == 0 || r -> hasContainer(object) == 0) {
					return true;
				}
			}
		}
	} else if (condition -> isType() == 2) {
		string object = condition -> getObject();
		string status = condition -> getStatus();
		if((map -> getItem(object) != NULL && map -> getItem(object) -> getStatus().compare(status) == 0) || (map -> getContainer(object) != NULL && map -> getContainer(object) -> getStatus().compare(status) == 0)) {
			return true;
		}
	}
	return false;
}

void GameManager::putItem(string item,string container)
{
	if(player -> hasItem(item)) {
		if(map -> getContainer(container) != NULL) {
			if(map -> getContainer(container)-> canAccept(item)) {
				player -> removeItem(item);
				map -> getContainer(container) -> addItem(item);
				cout << "Item " << item << " added to " << container << endl;
			} else {
				cout << "Can't do that" << endl;
				cout << container << " doesn't accept " << item << endl;
			}
		} else
			cout << "Error" << endl;
	} else {
		cout << "Can't do that" << endl;
		cout << item << " is not in your inventory" << endl;
	}
}

void GameManager::takeItem(string item)
{
	//from current room
	if(player -> getRoom() -> hasItem(item)) {
		player -> getRoom() -> removeItem(item);
		player -> addItem(item);
		cout << "Item " << item << " added to inventory" << endl;
	} else if (map -> getContainerWithItem(item) != NULL && player -> getRoom() -> hasContainer(map -> getContainerWithItem(item) -> getName())) {
		//from container in room
		Container * c = map -> getContainerWithItem(item);
		if(c -> isOpen) {
			c -> removeItem(item);
			player -> addItem(item);
			cout << "Item " << item << " added to inventory" << endl;

			//change location of item to inventory
			Item * i = map -> getItem(item);
			for (int j = 0; j < i -> triggerVec.size(); j++){
				i -> triggerVec[j] -> setLocation("inventory");
			}

		} else {
			cout << "You must first open " << c -> getName() << endl;
		}
	} else
		cout << "Error" << endl;
}

void GameManager::openContainer(string container) {
	if(player -> getRoom() -> hasContainer(container))
		map -> getContainer(container) -> open();
	else
		cout << container << " is not present in this room" << endl;
}

void GameManager::openExit() {
	if(player -> getRoom() -> getType().compare("exit") == 0) {
		endGame();
	} else {
		cout << "This is not an exit" << endl;
	}
}

void GameManager::readItem(string item) {
	if (player -> hasItem(item)) {
		map -> getItem(item) -> read();
	} else {
		cout << item << " is not in your inventory" << endl;
	}
}

void GameManager::dropItem(string item) {
	if (player -> hasItem(item)) {
		player -> removeItem(item);
		player -> getRoom() -> addItem(item);
		cout << item << " dropped" << endl;
	} else {
		cout << item << " is not in your inventory" << endl;
	}
}

void GameManager::turnonItem(string item) {
	if (player -> hasItem(item)) {
		if(map -> getItem(item) -> hasTurnon()){
			cout << "You activate " << item << endl;
			cout << map -> getItem(item) -> getTurnonPrint() << endl;
			checkCommand(map -> getItem(item) -> getTurnonAction());
		} else {
			cout << "Cannot turn on " << item << endl;
		}
	} else {
		cout << item << " is not in your inventory" << endl;
	}
}

void GameManager::addObject(string obj,string name)
{
	if(map -> getItem(obj) !=NULL) {                     //obj is item
		if(map -> getRoom(name) != NULL) { 			     //to room
			map -> getRoom(name) -> addItem(obj);
		} else if (map -> getContainer(name) != NULL) {  //to container
			map -> getContainer(name) -> addItem(obj);
		} else                                           //items can only go in rooms and containers
			cout << "Error" << endl;
	} else if(map -> getCreature(obj) != NULL){          //obj is creature
		if(map -> getRoom(name) != NULL) {  			 //to room
			map -> getRoom(name) -> addCreature(obj);
		} else                                           //creatures can only go in rooms
			cout << "Error" << endl;
	} else if(map -> getContainer(obj) != NULL) {        //object is container
		if(map -> getRoom(name) != NULL) {  			 //to room
			map -> getRoom(name) -> addContainer(obj);
		} else                                           //containers only go in rooms
			cout << "Error" << endl;
	} else
		cout << "Error" << endl;
}

void GameManager::deleteObject(string obj)
{
	if(map -> getItem(obj) != NULL) {                               //obj is item
		if(map -> getRoomWithItem(obj) != NULL) {                	//from room
			map -> getRoomWithItem(obj) -> removeItem(obj);
		} else if (map -> getContainerWithItem(obj) != NULL) {      //from container
			map -> getContainerWithItem(obj) -> removeItem(obj);
		} else                                                      //items only go in rooms and containers
			cout << "Error" << endl;
	} else if (map -> getCreature(obj) != NULL) {                   //obj is creature
		if(map -> getRoomWithCreature(obj) != NULL) {               //from room
			map -> getRoomWithCreature(obj) -> removeCreature(obj);
		} else                                                      //creatures only exist in rooms
			cout << "Error" << endl;
	} else if(map -> getContainer(obj) != NULL) {                   //obj is container
		if(map -> getRoomWithContainer(obj) != NULL) {          	//from room
			map -> getRoomWithContainer(obj) -> removeContainer(obj);
		} else 														//containers only exist in rooms
			cout << "Error" << endl;
	} else
		cout << "Error" << endl;
}

void GameManager::attackCreature(string creature, string item)
{
	if (player -> hasItem(item)) {
		if(player -> getRoom() -> hasCreature(creature)) {
			if(map -> getCreature(creature) -> hasVulnerability(item)) {
				Attack * attack = map -> getCreature(creature) -> getAttack();
				if (attack == NULL)
					cout << "You assault the " << creature << " with " << item << endl;
				else if (attack -> conditionObj.empty()  || map -> getItem(attack -> conditionObj) -> getStatus().compare(attack -> conditionStatus) == 0) {
					//either has no condition or condition is met
					if(attack -> printMsg.empty() == 0)
						cout << attack -> printMsg << endl;
					executeActionVec(attack -> actionVec);
				} else
					cout << "Error" << endl;;
			} else {
				cout << creature << " is not affected by " << item << endl;
			}
		} else {
			cout << creature << " is not present in this room" << endl;
		}
	} else {
		cout << item << " is not in your inventory" << endl;
	}
}

void GameManager::executeActionVec(vector<string> actionVec) {
	int i;
	string command;
	for(i=0;i<actionVec.size();i++){
		command = actionVec[i];
		checkCommand(command);
	}
}

void GameManager::checkCommand(string command) {
	vector<string> commandVec;
	string buf;
	stringstream ss(command);
	while(ss >> buf)
		commandVec.push_back(buf);
	if(commandVec[0].compare("n") == 0 || commandVec[0].compare("s") == 0 || commandVec[0].compare("e") == 0 || commandVec[0].compare("w") == 0)
		player -> changeRoom(map,commandVec[0]);
	else if (commandVec[0].compare("Add") == 0)
		addObject( commandVec[1], commandVec[3]);
	else if (commandVec[0].compare("Delete") == 0)
		deleteObject(commandVec[1]);
	else if (commandVec[0].compare("i") == 0)
		player -> showInventory();
	else if (commandVec[0].compare("Update") == 0)
		map -> getObject(commandVec[1]) -> updateStatus(commandVec[3]);
	else if (commandVec[0].compare("Game") == 0 && commandVec[1].compare("Over") == 0)
		endGame();
	else if (commandVec[0].compare("put") == 0)
		putItem(commandVec[1],commandVec[3]);
	else if (commandVec[0].compare("take") == 0)
		takeItem(commandVec[1]);
	else if (commandVec[0].compare("open") == 0 && commandVec[1].compare("exit") != 0)
		openContainer(commandVec[1]);
	else if (commandVec[0].compare("open") == 0 && commandVec[1].compare("exit") == 0)
		openExit();
	else if (commandVec[0].compare("read") == 0)
		readItem(commandVec[1]);
	else if (commandVec[0].compare("drop") == 0)
		dropItem(commandVec[1]);
	else if (commandVec[0].compare("turn") == 0 && commandVec[1].compare("on") == 0)
		turnonItem(commandVec[2]);
	else if(commandVec[0].compare("attack") == 0)
		attackCreature(commandVec[1],commandVec[3]);
	else
		cout << "Error" << endl;
	commandVec.clear();
}

void GameManager::endGame() {
	cout << "Game Over !" << endl;
	end = true;
}
