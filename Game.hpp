/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Game class
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "RoomStruct.hpp"
#include "Floor.hpp"
#include "Ceiling.hpp"
#include "WallBlack.hpp"
#include "WallSafe.hpp"
#include "WallDesk.hpp"
#include "WallDoor.hpp"
#include "Bag.hpp"
#include"Player.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


class Game
{
protected:
	//variables
	vector <Room*> space;
	Room* r;
	std::string input;
	Room* currentSpace;
	Bag* bag;
	Player* player;
	
public:
	//class constructor prototype
	Game();
	//class destructor prototype
	~Game();
	//function prototypes
	void displayScreen();
	void menu();
	char checkStatus();





};
#endif // !GAME_HPP
