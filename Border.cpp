#include "Border.h"

Border::Border(xml_node<char> * root) {
	name = root -> first_node("name") -> value();
	direction = root -> first_node("direction") -> value();
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

Border::~Border() {

}

string Border::getName() {
	return name;
}

string Border::getDirection() {
	return direction;
}
