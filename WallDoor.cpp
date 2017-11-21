/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Ceiling class
*********************************************************************/

#include "WallDoor.hpp"

/********************************************************************
** Sets pointers to other spaces. In this case, sets current space to
** 1. Sets up to ceiling, sets down to floor, sets right to black light
** wall, sets left to safe
********************************************************************/
void Door::setPointers(vector<Room*> space)
{
	this->current = space[1];
	this->right = space[0];
	this->left = space[2];
	this->down = space[4];
	this->up = space[5];

}

/********************************************************************
** Sets description of space based on if the item found in the space
** has occured
********************************************************************/
void Door::setSpaceName()
{
	if (itemFound == false)
		this->spaceName = "You see a door that is locked tight";
	else
		this->spaceName = "You unlock the door with the key";

}

/********************************************************************
** Interact with the space. First checks if the item from the current
** space has been found. Then it checks the bag to see if the item
** needed to interact with the space is in there. If you can interact
** the space will display a message and add the new item to the bag.
********************************************************************/
void Door::interact(Bag* bag)
{
	//if current space's item has not been found
	if (itemFound == false)
	{
		//search bag to see if needed item is in bag
		if (bag->searchBag("Door Key") == false)
			cout << "The door is locked shut. You'll need to find a way to open it" << endl;
		//if item is in bag
		else
		{
			cout << "You unlock the door with the key!" << endl;
			
			itemFound = true;
			setSpaceName();//set new space
			bag->addItem(item);//add new item to bag
		}
	}
	
}

/********************************************************************
** Function displays a rough image of the current space to add a
** more visual element to the game.
** Code for this function was taken www.cplusplus.com/forum/general/58945/
********************************************************************/
void Door::displayStruct()
{
	string imageLines = "";
	string fileName;

	ifstream inputFile;
	//choose between two files
	if (!itemFound)
		fileName = "./Final Project Images/DoorClosed.txt";
	else
		fileName = "./Final Project Images/DoorOpen.txt";
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
