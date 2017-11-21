/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: RoomStruct is the abstract parent class of the spaces.
				This file contains the virtual function prototypes
*********************************************************************/

#ifndef ROOMSTRUCT_HPP
#define ROOMSTRUCT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Bag.hpp"
#include <fstream>

using namespace std;


class Room
{
protected:
	//class variables
	bool itemFound;
	//space pointers points to other spaces (other room structures)
	Room* up;
	Room* down;
	Room* left;
	Room* right;
	Room* current;
	std::string spaceName = "";
	Bag* bag;

public:
	//virtual function prototypes
	virtual void setPointers(vector<Room*>) = 0;
	virtual void setSpaceName() = 0;
	virtual std::string getSpaceName();
	virtual Room* getCurrentSapce() { return this->current; }
	virtual Room* turnLeft();
	virtual Room* turnRight();
	virtual Room* lookUp();
	virtual Room* lookDown();
	virtual void interact(Bag*) = 0;
	virtual void displayStruct() = 0;
	virtual ~Room(); 
	








};
#endif // !ROOMSTRUCT_HPP
