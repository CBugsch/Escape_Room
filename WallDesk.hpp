/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Desk class
*********************************************************************/
#ifndef WALLDESK_HPP
#define WALLDESK_HPP

#include"RoomStruct.hpp"

class Desk : public Room
{
protected:
	//variable
	std::string item = "Screwdriver";
public:
	//function prototypes
	void setPointers(vector<Room*>);
	void setSpaceName();
	void interact(Bag*);
	void displayStruct();
	

	
};
#endif // !WALLDESK_HPP
