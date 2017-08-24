#include "Map.h"

Map::Map(){

}


Map::~Map() {
}

xml_node<>* Map::readFile(string path) {
	ifstream f(path.c_str());
	xml_document<> doc;
	vector<char> buffer((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	xml_node<> *n = doc.first_node();
	if(n == NULL){//error
		cout << "Error reading XML file" << endl;
		return NULL;
	}
	string s = n -> name();
	if(s.compare("map") != 0){
		cout << "Error reading XML file: root node is not map" << endl;
		return NULL;
	}
	return n;
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

void Map::loadMap(string file){
	xml_node<> * root = readFile(file);
	//call room constructor
	xml_node<> * room_node = root -> first_node("room");
	for(room_node = root -> first_node("room");room_node;room_node = room_node -> next_sibling("room")){
		roomVec.push_back(new Room(room_node));
	}
	//call item constructor
	xml_node<> * item_node = root -> first_node("item");
	for(item_node = root -> first_node("item");item_node;item_node = item_node -> next_sibling("item")){
		itemVec.push_back(new Item(item_node));
	}
	//call container constructor
	xml_node<> * container_node = root -> first_node("container");
	for(container_node = root -> first_node("container");container_node;container_node = container_node -> next_sibling("container")){
		containerVec.push_back(new Container(container_node));
	}
	//call creature constructor
	xml_node<> * creature_node = root -> first_node("creature");
	for(creature_node = root -> first_node("creature");creature_node;creature_node = creature_node -> next_sibling("creature")){
		creatureVec.push_back(new Creature(creature_node));
	}

	int i= 0;
	int j = 0 ;
	for(i=0; i < roomVec.size();i++) {
		for(j = 0; j < roomVec[i] -> triggerVec.size();j++) {
			triggers.push_back(roomVec[i] -> triggerVec[j]);
		}
	}
	for(i=0; i < itemVec.size();i++) {
		for(j = 0; j < itemVec[i] -> triggerVec.size();j++) {
			triggers.push_back(itemVec[i] -> triggerVec[j]);
		}
	}
	for(i=0; i < containerVec.size();i++) {
		for(j = 0; j < containerVec[i] -> triggerVec.size();j++) {
			triggers.push_back(containerVec[i] -> triggerVec[j]);
		}
	}
	for(i=0; i < creatureVec.size();i++) {
		for(j = 0; j < creatureVec[i] -> triggerVec.size();j++) {
			triggers.push_back(creatureVec[i] -> triggerVec[j]);
		}
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

Room * Map::getRoom (string name) {
	int i;
	for ( i = 0; i < roomVec.size();i++) {
		if(roomVec[i] -> getName().compare(name) == 0) {
			return roomVec[i];
		}
	}
	return NULL;
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

Container * Map::getContainer (string name) {
	int i;
	for ( i = 0; i < containerVec.size();i++) {
		if(containerVec[i] -> getName().compare(name) == 0) {
			return containerVec[i];
		}
	}
	return NULL;
}

Item * Map::getItem (string name) {
	int i;
	for ( i = 0; i < itemVec.size();i++) {
		if(itemVec[i] -> getName().compare(name) == 0) {
			return itemVec[i];
		}
	}
	return NULL;
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

Creature * Map::getCreature (string name) {
	int i;
	for ( i = 0; i < creatureVec.size();i++) {
		if(creatureVec[i] -> getName().compare(name) == 0) {
			return creatureVec[i];
		}
	}
	return NULL;
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

Container * Map::getContainerWithItem(string item) {
	int i;
	for(i=0; i < containerVec.size();i++) {
		if(containerVec[i] -> hasItem(item)) {
			return containerVec[i];
		}
	}
	return NULL;
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

Room * Map::getRoomWithItem(string item) {
	int i;
	for(i=0; i < roomVec.size();i++) {
		if(roomVec[i] -> hasItem(item)) {
			return roomVec[i];
		}
	}
	return NULL;
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

Room * Map::getRoomWithCreature(string creature) {
	int i;
	for(i=0; i < roomVec.size();i++) {
		if(roomVec[i] -> hasCreature(creature)) {
			return roomVec[i];
		}
	}
	return NULL;
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

Room * Map::getRoomWithContainer(string container) {
	int i;
	for(i=0; i < roomVec.size();i++) {
		if(roomVec[i] -> hasContainer(container)) {
			return roomVec[i];
		}
	}
	return NULL;
}

MapItem * Map::getObject(string name) {
	int i;
	for ( i = 0; i < creatureVec.size();i++) {
		if(creatureVec[i] -> getName().compare(name) == 0) {
			return creatureVec[i];
		}
	}
	for ( i = 0; i < itemVec.size();i++) {
		if(itemVec[i] -> getName().compare(name) == 0) {
			return itemVec[i];
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
	}
	for ( i = 0; i < containerVec.size();i++) {
		if(containerVec[i] -> getName().compare(name) == 0) {
			return containerVec[i];
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
	}
	for ( i = 0; i < roomVec.size();i++) {
		if(roomVec[i] -> getName().compare(name) == 0) {
			return roomVec[i];
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
	}
}
