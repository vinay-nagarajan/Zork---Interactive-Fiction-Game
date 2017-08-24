#include "Creature.h"

Creature::Creature(xml_node<> * root) {
	name = root -> first_node("name") -> value();
	xml_node<> * description_node = root -> first_node("description");
	if(description_node != 0)
			description = description_node -> value();
	xml_node<> * status_node = root -> first_node("status");
	if(status_node != 0)
		status = status_node -> value();
	xml_node<> * vulnerability_node = root -> first_node("vulnerability");
	for(vulnerability_node = root -> first_node("vulnerability");vulnerability_node;vulnerability_node = vulnerability_node -> next_sibling("vulnerability")){
			vulnerabilityVec.push_back(vulnerability_node->value());
	}
	attack = NULL;
	xml_node<> * attack_node = root -> first_node("attack");
	if(attack_node != 0)
		attack = new Attack(attack_node);
	xml_node<> * trigger_node = root -> first_node("trigger");
	for(trigger_node = root -> first_node("trigger");trigger_node;trigger_node = trigger_node -> next_sibling("trigger")){
		triggerVec.push_back(new Trigger(trigger_node));
	}

	for (int i = 0; i < triggerVec.size(); i++){
		triggerVec[i] -> setLocation(name);
	}

}

Creature::~Creature() {
	// TODO Auto-generated destructor stub
}

bool Creature::hasVulnerability(string item) {
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
	int i;
	for(i=0;i<vulnerabilityVec.size();i++) {
		if(vulnerabilityVec[i].compare(item)==0)
			return true;
	}
	return false;
}

Attack * Creature::getAttack(){
	return attack;
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
