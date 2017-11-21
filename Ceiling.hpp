/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Ceiling class
*********************************************************************/

#ifndef CEILING_HPP
#define CEILING_HPP

#include "RoomStruct.hpp"

class Ceiling : public Room
{
protected:
	//class variables
	std::string item = "Black light";
public:
	// class functions
	void setPointers(vector<Room*>);
	void setSpaceName();
	void interact(Bag*);
	void displayStruct();


};
#endif // !CEILING_HPP
