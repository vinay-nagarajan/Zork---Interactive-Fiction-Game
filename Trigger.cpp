#include "Trigger.h"


string Trigger::getCommand(){
	return command;
}

string Trigger::getType(){
	return type;
}

void Trigger::printMessage() {
	cout << printMsg << endl;

}

void Trigger::setLocation(string loc) {
	location = loc;
}
Trigger::Trigger(xml_node<char> * root) {
	expired = false;
	xml_node<> * type_node = root -> first_node("type");
	if(type_node == 0)
		type = "single";
	else
		type = type_node -> value();
	xml_node<> * print_node = root -> first_node("print");
	if(print_node != 0)
		printMsg = print_node -> value();
	xml_node<> * action_node = root -> first_node("action");
	for(action_node = root -> first_node("action");action_node;action_node = action_node -> next_sibling("action")){
		actionVec.push_back(action_node -> value());
	}
	xml_node<> * condition_node = root -> first_node("condition");
	for(condition_node = root -> first_node("condition");condition_node;condition_node = condition_node -> next_sibling("condition")){
		conditionVec.push_back(new Condition(condition_node));
	}
	xml_node<> * command_node = root -> first_node("command");
	if(command_node != 0)
		command = command_node -> value();
}

Trigger::~Trigger() {

}

string Trigger::getLocation(){
	return location;
}



