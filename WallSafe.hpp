/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Safe class
*********************************************************************/

#ifndef WALLSAFE_HPP
#define WALLSAFE_HPP

#include"RoomStruct.hpp"

class Safe : public Room
{
protected:
	//variable
	std::string item = "Crowbar";
public:
	//function prototypes
	void setPointers(vector<Room*>);
	void setSpaceName();
	void interact(Bag*);
	void displayStruct();
	

	
};
#endif // !WALLSAFE_HPP
