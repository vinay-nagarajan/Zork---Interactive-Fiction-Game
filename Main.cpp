/*
 * Main.cpp
 *  Created on: Nov 30, 2016
 *      Author: vinay nagarajan */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "rapidxml.hpp"

#include "Map.h"
#include "Player.h"
#include "GameManager.h"

using namespace std;
using namespace rapidxml;

int main(int argc, char ** argv){
	if(argc != 2) {
		cout << "please enter filename" << endl;
		return 1; //exit program
	}
	Map * map = new Map();
	map -> loadMap(argv[1]);
	Player * player = new Player(map -> getRoom("Entrance"));
	GameManager * game = new GameManager(map,player);
	game -> gameLoop();
	return 0;
}




