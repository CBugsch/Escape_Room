/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Ceiling class
*********************************************************************/

#include "Floor.hpp"

/********************************************************************
** Sets pointers to other spaces. In this case, sets current space to
** four, up space set to 1 (the door) and the rest to null
********************************************************************/
void Floor::setPointers(vector<Room*> space)
{
	this->current = space[4];
	this->left = NULL;
	this->right = NULL;
	this->up = space[1];
	this->down = NULL;
}


/********************************************************************
** Sets description of space based on if the item found in the space
** has occured
********************************************************************/
void Floor::setSpaceName()
{
	if (itemFound == false)
		this->spaceName = "A wood floor with a board that looks loose";
	else
		this->spaceName = "The floor board has been removed";

}

/********************************************************************
** Interact with the space. First checks if the item from the current
** space has been found. Then it checks the bag to see if the item
** needed to interact with the space is in there. If you can interact
** the space will display a message and add the new item to the bag.
********************************************************************/
void Floor::interact(Bag* bag)
{
	//if current space's item has not been found
	if (itemFound == false)
	{
		//search bag for the item needed to interact with the space
		if (bag->searchBag("Crowbar") == false)
			cout << "The floorboard wont budge. Maybe if you had something to pry it up with" << endl;
		else//if correct item is in bag
		{
			//interact with the space
			cout << "You pry the floorboard up and find a box with a door key inside" << endl;
			bag->addItem(item);//add current space's item to bag
			itemFound = true;
			setSpaceName();//change space description
		}
	}
	else
		cout << "You've already searched here" << endl;
}


/********************************************************************
** Function displays a rough image of the current space to add a
** more visual element to the game.
** Code for this function was taken www.cplusplus.com/forum/general/58945/
********************************************************************/
void Floor::displayStruct()
{
	string imageLines = "";
	string fileName;

	ifstream inputFile;

	//choose between two pictures based on current space
	if (!itemFound)
		fileName = "./Final Project Images/Floor.txt";
	else
		fileName = "./Final Project Images/Key.txt";

	//open file
	inputFile.open(fileName.c_str());

	if (inputFile)
	{
		while (inputFile)
		{
			string temp;
			getline(inputFile, temp);//get an entire line of text
			temp += "\n";//add a new line
			imageLines += temp;//add text to imageLines string
		}
		cout << imageLines << endl;//print entire string

		inputFile.close();//close file
	}
	else
		cout << "ERROR: Image file wasn't found..." << endl;
}
