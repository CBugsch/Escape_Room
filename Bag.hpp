/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Bag class
*********************************************************************/

#ifndef BAG_HPP
#define BAG_HPP


#include <iostream>
#include <vector>
#include <string>

using namespace std;
 

class Bag
{
protected:
	//class variables
	std::string item;
	std::vector <std::string> bag;


public:
	//class functions
	void addItem(std::string);
	bool searchBag(std::string);
	void displayBag();



};
#endif // !BAG_HPP
