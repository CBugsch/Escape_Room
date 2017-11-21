/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Ceiling class
*********************************************************************/

#include "WallDesk.hpp"


/********************************************************************
** Sets pointers to other spaces. In this case, sets current space to
** 3. Sets up to ceiling, down to floor, left to black light wall, right
** to safe.
********************************************************************/
void Desk::setPointers(vector<Room*>space)
{
	this->current = space[3];
	this->left = space[0];
	this->right = space[2];
	this->down = space[4];
	this->up = space[5];
}


/********************************************************************
** Sets description of space based on if the item found in the space
** has occured
********************************************************************/
void Desk::setSpaceName()
{
	if (itemFound == false)
		this->spaceName = "You see an empty desk with a set of drawers";
	else
		this->spaceName = "The desk drawer is open";
}

/********************************************************************
** Interact with the space. First checks if the item from the current
** space has been found. If you can interact
** the space will display a message and add the new item to the bag.
********************************************************************/
void Desk::interact(Bag* bag)
{
	//if current space's item has not been found
	if (itemFound == false)
	{
		cout << " You open the drawer and find a screwdriver!" << endl;
		bag->addItem(item);//add item to bag
		itemFound = true;
		setSpaceName();//change space description
	}
	else
		cout << "You already checked here" << endl;


}


/********************************************************************
** Function displays a rough image of the current space to add a
** more visual element to the game.
** Code for this function was taken www.cplusplus.com/forum/general/58945/
********************************************************************/
void Desk::displayStruct()
{
	string imageLines = "";
	string fileName;

	ifstream inputFile;
	//choose between two files
	if (!itemFound)
		fileName = "./Final Project Images/Desk.txt";
	else
		fileName = "./Final Project Images/ScrewDriver.txt";
	//open file
	inputFile.open(fileName.c_str());

	if (inputFile)
	{
		while (inputFile)
		{
			string temp;
			getline(inputFile, temp);//get line of text
			temp += "\n";//add a new line
			imageLines += temp;//add line of text to string image
		}
		cout << imageLines << endl;//print image

		inputFile.close();//close file
	}
	else
		cout << "ERROR: Image file wasn't found..." << endl;
}
