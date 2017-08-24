#include "Room.h"

Room::Room(xml_node<char> * root) {
	name = root -> first_node("name") -> value();
	description = root -> first_node("description") -> value();
	xml_node<> * type_node = root -> first_node("type");
	if(type_node == 0)
		type = "regular";
	else
		type = type_node -> value();
	xml_node<> * status_node = root -> first_node("status");
	if(status_node != 0)
		status = status_node -> value();
	/*cout << "==============================" << endl;
	cout << "room name = " << name << endl;
	cout << "room type = " << type << endl;
	cout << "room status = " << status << endl;
	cout << "room description = " << description << endl;*/
	xml_node<> * border_node = root -> first_node("border");
	for(border_node = root -> first_node("border");border_node;border_node = border_node -> next_sibling("border")){
		borderVec.push_back(Border(border_node));
	}
	xml_node<> * container_node = root -> first_node("container");
	for(container_node = root -> first_node("container");container_node;container_node = container_node -> next_sibling("container")){
		containerVec.push_back(container_node->value());
	}
	xml_node<> * item_node = root -> first_node("item");
	for(item_node = root -> first_node("item");item_node;item_node = item_node -> next_sibling("item")){
		itemVec.push_back(item_node->value());
	}
	xml_node<> * creature_node = root -> first_node("creature");
	for(creature_node = root -> first_node("creature");creature_node;creature_node = creature_node -> next_sibling("creature")){
		creatureVec.push_back(creature_node->value());
	}
	xml_node<> * trigger_node = root -> first_node("trigger");
	for(trigger_node = root -> first_node("trigger");trigger_node;trigger_node = trigger_node -> next_sibling("trigger")){
			triggerVec.push_back(new Trigger(trigger_node));
	}

	for (int i = 0; i < triggerVec.size(); i++){
		triggerVec[i] -> setLocation(name);
	}


}

Room::~Room() {

}

string Room::getBorderRoom(string dir) {
	string room;
	int i;
	for(i = 0;i<borderVec.size();i++) {
		if(borderVec[i].getDirection().compare(dir) == 0) {
			room = borderVec[i].getName();
			break;
		}
	}
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

string Room::getType(){
	 return type;
}

bool Room::hasItem(string item) {
	int i;
	for(i = 0;i<itemVec.size();i++) {
		if(itemVec[i].compare(item) == 0) {
			return 1;
		}
	}
	return 0;
}

bool Room::hasContainer(string container) {
	int i;
	for(i = 0;i<containerVec.size();i++) {;
		if (containerVec[i].compare(container) == 0)
			return true;
	}
	return false;
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

bool Room::hasCreature(string creature) {
	int i;
	for(i = 0;i<creatureVec.size();i++) {;
		if (creatureVec[i].compare(creature) == 0)
			return true;
	}
	return false;
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

void Room::addItem(string item) {
	itemVec.push_back(item);
}

void Room::addCreature(string creature) {
	creatureVec.push_back(creature);
}

void Room::addContainer(string container) {
	containerVec.push_back(container);
}

void Room::removeCreature(string creature){
	 vector<string>::iterator del = find(creatureVec.begin(), creatureVec.end(), creature);
	 creatureVec.erase(del);
}

void Room::removeContainer(string container){
	 vector<string>::iterator del = find(containerVec.begin(), containerVec.end(), container);
	 containerVec.erase(del);
}

void Room::removeItem(string item){
	 vector<string>::iterator del = find(itemVec.begin(), itemVec.end(), item);
	 itemVec.erase(del);
}


