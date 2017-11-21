/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Safe class
*********************************************************************/

#include "WallSafe.hpp"

/********************************************************************
** Sets pointers to other spaces. In this case, sets current space to
** two. Sets up to ceiling, sets down to floor, sets left to desk and
** sets right to door.
********************************************************************/
void Safe::setPointers(vector<Room*>space)
{
	this->current = space[2];
	this->left = space[3];
	this->right = space[1];
	this->up = space[5];
	this->down = space[4];
}

/********************************************************************
** Sets description of space based on if the item found in the space
** has occured
********************************************************************/
void Safe::setSpaceName()
{
	if (itemFound == false)
		this->spaceName = "Wall with a safe";
	else
		this->spaceName = "The safe has been opened";
}

/********************************************************************
** Interact with the space. First checks if the item from the current
** space has been found. Then it checks the bag to see if the item
** needed to interact with the space is in there. If you can interact
** the space will display a message and add the new item to the bag.
********************************************************************/
void Safe::interact(Bag* bag)
{
	//if current space's item has not been found
	if (itemFound == false)
	{
		//search bag to see if needed item is in bag
		if (bag->searchBag("Safe Code") == false)
			cout << "The safe is locked. You'll need to find the code" << endl;
		//if the correct item is in bag interact with the space
		else
		{
			cout << "You open the safe and find a crowbar and hammer!" << endl;
			bag->addItem(item);//add new item to bag
			itemFound = true;
			setSpaceName();//set new space description
		}
	}
	//if current space's item had already been found
	else
		cout << "You've already searched here" << endl;
}

/********************************************************************
** Function displays a rough image of the current space to add a
** more visual element to the game.
** Code for this function was taken www.cplusplus.com/forum/general/58945/
********************************************************************/
void Safe::displayStruct()
{
	string imageLines = "";
	string fileName;

	ifstream inputFile;
	//choose between two files
	if (!itemFound)
		fileName = "./Final Project Images/Safe.txt";
	else
		fileName = "./Final Project Images/CrowbarHammer.txt";

	inputFile.open(fileName.c_str());//open file

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
