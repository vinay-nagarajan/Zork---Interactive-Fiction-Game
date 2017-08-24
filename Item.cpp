#include "Item.h"

Item::Item(xml_node<char> * root) {
	name = root -> first_node("name") -> value();
	xml_node<> * status_node = root -> first_node("status");
	if(status_node != 0)
		status = status_node -> value();
	xml_node<> * description_node = root -> first_node("description");
		if(description_node != 0)
		description = description_node -> value();
	xml_node<> * writing_node = root -> first_node("writing");
	if(writing_node != 0)
		writing = writing_node -> value();
	else
		writing = "Nothing written";
	xml_node<> * turnon_node = root -> first_node("turnon");
	if(turnon_node != 0) {
		turnon_print = turnon_node -> first_node("print") -> value();
		turnon_action = turnon_node -> first_node("action") -> value();
	}
	xml_node<> * trigger_node = root -> first_node("trigger");
	for(trigger_node = root -> first_node("trigger");trigger_node;trigger_node = trigger_node -> next_sibling("trigger")){
			triggerVec.push_back(new Trigger(trigger_node));
	}

	for (int i = 0; i < triggerVec.size(); i++){
		triggerVec[i] -> setLocation(name);
	}

}

Item::~Item() {

}

void Item::read() {
	cout << writing << endl;
}

string Item::getTurnonPrint() {
	return turnon_print;
}

string Item::getTurnonAction() {
	return turnon_action;
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

bool Item::hasTurnon() {
	if(turnon_print.empty() && turnon_action.empty())
		return false;
	return true;
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

