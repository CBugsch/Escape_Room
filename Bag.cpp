/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Bag class 
*********************************************************************/
#include "Bag.hpp"


/********************************************************************
** Adds a string (name of object) to a vector called bag
**
********************************************************************/
void Bag::addItem(std::string s)
{
	bag.push_back(s);
}

/********************************************************************
** Function returns true or false if a specific string is found in
** the bag vector
********************************************************************/
bool Bag::searchBag(std::string s)
{
	//search through each element of vector
	for (int i = 0; i < bag.size(); i++)
	{	//if item is found, return true
		if (bag.at(i) == s)
			return true;
	}//if item is not found, return false
	return false;
}

/********************************************************************
** Displays the items in the bag
**
********************************************************************/
void Bag::displayBag()
{
	//if bag vecotr has no elements
	if (bag.empty())
		std::cout << " The bag is empty" << std::endl;
	else
	{	
		//traverse through vector printing each element
		std::cout << "Your bag has the following items: ";
		for (int i = 0; i < bag.size(); i++)
		{
			std::cout << bag.at(i) << ", ";
		}
	}

}