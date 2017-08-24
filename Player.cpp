#include "Player.h"

Player::Player(Room * entrance) : room(entrance) {
	cout << room -> getDescription() << endl;
}

Player::~Player() {

}

void Player::changeRoom(Map * map, string dir) {
	string bDir;
	if (dir.compare("n") == 0)
		bDir = "north";
	else if (dir.compare("s") == 0)
		bDir = "south";
	else if (dir.compare("e") == 0)
		bDir = "east";
	else
		bDir = "west";
	string newRoomName = room -> getBorderRoom(bDir);
	if (newRoomName.empty()) {
		cout << "Can't go that way" << endl;
	} else {
		room = map -> getRoom(newRoomName);
		cout << room -> getDescription() << endl;
	}
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

void Player::showInventory() {
	if(inventoryVec.empty()) {
		cout << "Inventory: empty" << endl;
	} else {
		cout << "Inventory: ";
		int i;
		for(i=0; i < inventoryVec.size() - 1;i++){
			cout << inventoryVec[i] << ", " ;
		}
		cout << inventoryVec[i] << endl;
	}
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

void Player::removeItem(string item){
	 vector<string>::iterator del = find(inventoryVec.begin(), inventoryVec.end(), item);
	 inventoryVec.erase(del);
}

bool Player::hasItem(string item) {
	int i = 0;
	for(i = 0; i < inventoryVec.size();i++) {
		if (inventoryVec[i].compare(item) == 0) {
			return 1;
			break;
		}
	}
	return 0;
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

void Player::addItem(string item) {
	inventoryVec.push_back(item);
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

Room * Player::getRoom(){
	return room;
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
