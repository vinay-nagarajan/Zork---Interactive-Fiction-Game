#include "Container.h"

Container::Container(xml_node<char> * root) {
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
	name = root -> first_node("name") -> value();
	xml_node<> * description_node = root -> first_node("description");
	if(description_node != 0)
			description = description_node -> value();
	xml_node<> * status_node = root -> first_node("status");
	if(status_node != 0)
		status = status_node -> value();
	xml_node<> * accept_node = root -> first_node("accept");
	for(accept_node = root -> first_node("accept");accept_node;accept_node = accept_node -> next_sibling("accept")){
		if(accept_node != 0)
			acceptVec.push_back(accept_node -> value());
	}
	xml_node<> * item_node = root -> first_node("item");
	for(item_node = root -> first_node("item");item_node;item_node = item_node -> next_sibling("item")){
		if(item_node != 0)
			itemVec.push_back(item_node -> value());

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
	xml_node<> * trigger_node = root -> first_node("trigger");
	for(trigger_node = root -> first_node("trigger");trigger_node;trigger_node = trigger_node -> next_sibling("trigger")){
		triggerVec.push_back(new Trigger(trigger_node));
	}
	isOpen = false;

	for (int i = 0; i < triggerVec.size(); i++){
		triggerVec[i] -> setLocation(name);
	}

}

Container::~Container() {

}

bool Container::canAccept(string item) {
	int i;
	if(acceptVec.empty())
		return 1;
	for(i = 0;i < acceptVec.size();i++) {
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
		if(acceptVec[i].compare(item) == 0) {
			return 1;
		}
	}
	return 0;
}

void Container::addItem(string item) {
	itemVec.push_back(item);
}

bool Container::hasItem(string item) {
	int i;
	for(i = 0;i<itemVec.size();i++) {
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
		if(itemVec[i].compare(item) == 0) {
			return 1;
		}
	}
	return 0;
}

void Container::removeItem(string item){
	 vector<string>::iterator del = find(itemVec.begin(), itemVec.end(), item);
	 itemVec.erase(del);
}

void Container::open(){
	if(itemVec.empty()) {
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
		cout << name << " is empty" << endl;
	} else {
		cout << name << " contains ";
		int i;
		for(i=0;i<itemVec.size() - 1 ;i++) {
			cout << itemVec[i] << ", ";
		}
		cout << itemVec[i] << endl;
		this -> isOpen = true;
	}

}
