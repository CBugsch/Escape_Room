/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Black Wall class
				This space is a blank wall that needs a black light
				to read the writing
*********************************************************************/

#ifndef WALLBLACK_HPP
#define WALLBLACK_HPP

#include"RoomStruct.hpp"

class Black : public Room
{
protected:
	//class variable
	std::string item = "Safe Code";
public:
	//function prototypes
	void setPointers(vector < Room*>);
	void setSpaceName();
	void interact(Bag*);
	void displayStruct();
};
#endif // !WALLBLACK_HPP
