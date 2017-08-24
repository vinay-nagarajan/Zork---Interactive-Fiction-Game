#include "Attack.h"

Attack::Attack(xml_node<char> * root) {
	xml_node<> * condition_node  = root -> first_node("condition");
	if(condition_node != 0) {
		conditionObj = condition_node -> first_node("object") -> value();
		conditionStatus = condition_node -> first_node("status") -> value();
	}
	xml_node<> * print_node  = root -> first_node("print");
	if(print_node != 0)
		printMsg = print_node -> value();
	xml_node<> * action_node = root -> first_node("action");
	for(action_node = root -> first_node("action");action_node;action_node = action_node -> next_sibling("action")){
		actionVec.push_back(action_node -> value());
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

Attack::~Attack() {

}
