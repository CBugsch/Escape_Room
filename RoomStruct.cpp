/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the RoomStruct class. These
				are the functions that are the same for all child classes
*********************************************************************/

#include "RoomStruct.hpp"

/********************************************************************
** Return the description of the current space
** 
********************************************************************/
std::string Room::getSpaceName()
{
	return spaceName;
}

/********************************************************************
** Function allows user to turn left from current space. If left pointer
** doesn't equal NULL set current space to the left pointer
********************************************************************/
Room* Room::turnLeft()
{
	if (current->left != NULL)
		return current->left;//return left pointer
	else
	{
		cout << "you cant look that way";
		return current;
	}
}

/********************************************************************
** Function allows user to turn right from current space. If right pointer
** doesn't equal NULL set current space to the right pointer
********************************************************************/
Room* Room::turnRight() 
{
	if (current->right != NULL) 
		return current->right; 
	else
	{
		cout << "you cant look that way";
		return current;
	}
}
/********************************************************************
** Function allows user to look up from current space. If up pointer
** doesn't equal NULL set current space to the up pointer
********************************************************************/
Room* Room::lookUp()
{
	if (current->up != NULL) 
		return current->up; 
	else
	{
		cout << "you cant look that way";
		return current;
	}
}
/********************************************************************
** Function allows user to look down from current space. If down pointer
** doesn't equal NULL set current space to the down pointer
********************************************************************/
Room* Room::lookDown()
{
	if (current->down != NULL)
		return current->down;
	else
	{
		cout << "you cant look that way";
		return current;
	}
}

/********************************************************************
** Class destrucor sets each space's current pointer to NULL
********************************************************************/
Room::~Room()
{
	this->current = NULL;
}


