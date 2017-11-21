/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Ceiling class
*********************************************************************/

#include "Ceiling.hpp"


/********************************************************************
** Sets pointers to other spaces. In this case, sets current space to 
** five, down space set to 1 (the door) and the rest to null
********************************************************************/
void Ceiling::setPointers(vector<Room*>space)
{
	this->current = space[5];//ceiling space
	this->up = NULL;
	this->down = space[1];//door space
	this->left = NULL;
	this->right = NULL;
}

/********************************************************************
** Sets description of space based on if the item found in the space
** has occured
********************************************************************/
void Ceiling::setSpaceName()
{
	if (itemFound == false)
		this->spaceName = "You see an air vent in the ceiling";
	else
		this->spaceName = "The air vent has been opened";

}

/********************************************************************
** Interact with the space. First checks if the item from the current
** space has been found. Then it checks the bag to see if the item
** needed to interact with the space is in there. If you can interact
** the space will display a message and add the new item to the bag.
********************************************************************/
void Ceiling::interact(Bag* bag)
{
	//if current space's item has not been found
	if (itemFound == false)
	{
		//search bag for the item needed to interact with the space
		if (bag->searchBag("Screwdriver") == false)
			cout << "You can't seem to open the vent. Maybe an item will help" << endl;
		//if correct item is in bag
		else
		{
			//interact with the space
			cout << "You open the vent with the screwdriver and you find a black light!" << endl;
			bag->addItem("Black light");//add current space's item to bag
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
void Ceiling::displayStruct()
{
	//set string 
	string imageLines = "";
	//file name string
	string fileName;

	ifstream inputFile;

	//choose between two pictures based on current space
	if (!itemFound)
		fileName = "./Final Project Images/AirVent.txt";
	else
		fileName = "./Final Project Images/LightBulb.txt";

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
