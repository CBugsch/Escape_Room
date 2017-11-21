/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Floor class
*********************************************************************/


#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "RoomStruct.hpp"

class Floor : public Room
{
protected:
	//class vairbales
	std::string item = "Door Key";
public:
	//class functions
	void setPointers(vector<Room*>);
	void setSpaceName();
	void interact(Bag*);
	void displayStruct();
};
#endif // !FLOOR_HPP
