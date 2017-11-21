/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Black class
*********************************************************************/
#include "WallBlack.hpp"


/********************************************************************
** Sets pointers to other spaces. In this case, sets current space to
** 0, down set to floor, up set to ceiling, left set to door, right 
** set to desk.
********************************************************************/
void Black::setPointers(vector<Room*> space)
{
	this->current = space[0];
	this->left = space[1];
	this->right = space[3];
	this->up = space[5];
	this->down = space[4];
}

/********************************************************************
** Sets description of space based on if the item found in the space
** has occured
********************************************************************/
void Black::setSpaceName()
{
	if (itemFound == false)
		this->spaceName = "A wall that looks like it has something written on it";
	else
		this->spaceName = "A wall with a secret code you found using the black light";

}
/********************************************************************
** Interact with the space. First checks if the item from the current
** space has been found. Then it checks the bag to see if the item
** needed to interact with the space is in there. If you can interact
** the space will display a message and add the new item to the bag.
********************************************************************/
void Black::interact(Bag* bag)
{
	//if current space's item has not been found
	if (itemFound == false)
	{
		//search bag for the item needed to interact with the space
		if (bag->searchBag("Black light") == false)
			cout << "You can't seem to read the writing, maybe in a different light" << endl;
		else//if correct item is in bag
		{
			//interact with the space
			cout << "Using the black light you find a code written on the wall!" << endl;
			bag->addItem(item);//add current space's item to bag
			itemFound = true;
			setSpaceName();//change space description
		}
	}
	//if the current space's item has already been found
	else
		cout << "You've already searched here" << endl;
}

/********************************************************************
** Function displays a rough image of the current space to add a
** more visual element to the game.
** Code for this function was taken www.cplusplus.com/forum/general/58945/
********************************************************************/
void Black::displayStruct()
{
	string imageLines = "";
	string fileName;

	ifstream inputFile;

	//choose between two pictures based on current space
	if (!itemFound)
		fileName = "./Final Project Images/Wall.txt";
	else
		fileName = "./Final Project Images/Code.txt";

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
		cout << imageLines << endl;//print string image

		inputFile.close();//close file
	}
	else
		cout << "ERROR: Image file wasn't found..." << endl;
}
