/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Door class
*********************************************************************/

#ifndef WALLDOOR_HPP
#define WALLDOOR_HPP

#include"RoomStruct.hpp"

class Door : public Room
{
protected:
	//variable
	std::string item = "Winner";

public:
	//function prototypes
	void setPointers(vector<Room*>);
	void setSpaceName();
	void interact(Bag*);
	void displayStruct();

	
};
#endif // !WALLDOOR_HPP
