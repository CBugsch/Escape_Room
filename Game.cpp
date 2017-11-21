/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Game class
*********************************************************************/

#include "Game.hpp"

/********************************************************************
** Game Constructor. Creates 6 room structures (4 walls, a floor and 
** a ceiling), a player and a bag. It adds pointers to the room structures
** and adds them to a vector called space. It then calls the setPointers 
** function to set each Room structures pointers to point in the correct
** direction.
*********************************************************************/
Game::Game()
{
	//create the 6 room structures and push them to a vector
	r = new Black();
	space.push_back(r);
	r = new Door();
	space.push_back(r);
	r = new Safe();
	space.push_back(r);
	r = new Desk();
	space.push_back(r);
	r = new Floor();
	space.push_back(r);
	r = new Ceiling();
	space.push_back(r);
	
	//create a new bag
	bag = new Bag();

	//create a new player
	player = new Player();

	//set room structures pointers
	for (int i = 0; i < 6; i++)
	{
		space[i]->setPointers(space);
	}
	//set current space to door
	currentSpace = space[1];
}

/********************************************************************
** Game destructor. Deallocates memory
*********************************************************************/
Game::~Game()
{
	for(int i = 0; i < 6; i++ )
	{
		Room* temp = space[i];
		delete temp;
	}
	delete bag;
	delete player;

}
/********************************************************************
** Sets the description of the current space, displays the image of 
** the space, the health of the player, and the description of the space
*********************************************************************/
void Game::displayScreen()
{
	//set current spaces description
	currentSpace->setSpaceName();
	//display the image of the space
	currentSpace->displayStruct();
	//display health of player
	cout << "You're health is: " << player->getHealth() << endl;
	//diplay description of the current space
	cout << currentSpace->getSpaceName() << endl << endl;
}

/********************************************************************
** Game Menu. Allows user to look up, down, left or right. Also allows
** user to interact with the space, look in their bag, or quit the game
*********************************************************************/
void Game::menu()
{
	//display choices to user
	cout << "(l)eft  (r)ight (u)p (d)own (i)nteract (b)ag (q)uit" << endl;
	cout << "What would you like to do? ";
	
	//get input from user
	getline(cin, input);
	//use first char from input as choice
	switch (input.at(0))
	{
	case 'l': //look left
	{
		currentSpace = currentSpace->turnLeft();
		break; 
	}
	case 'd': //look down
	{
		currentSpace = currentSpace->lookDown();
		break;
	}
	case 'r': //look right
	{
		currentSpace = currentSpace->turnRight();
			break;
	}
	case 'u': //look up
	{
		currentSpace = currentSpace->lookUp();
		break;
	}
	/********************************************************************
	** Interact with the space. When the user chooses to interact with 
	** a space, there is a 50% chance they will fail and injure themselves.
	*********************************************************************/
	case 'i': 
	{
		
		int chance = rand() % 2; //generate random 50% chance
		//if failed to interact, player loses 10 health
		if (chance == 1)
			player->setHealth();
		//if interaction is succesful, complete interaction
		else
			currentSpace->interact(bag);
		break;
	}
	case 'b'://display contents of bag
	{
		bag->displayBag();
		break;
	}
	case 'q': //quit game
	{
		bag->addItem("Quit");
		break;
	}
	default:
		cout << "Oops! You didn't choose a vaild option" << endl;


	}//end of switch


}
/********************************************************************
** Keeps track of the status of the game. If user has won, the string
** "Winner" will be added to their bag and this function will return a 
** 'w'. If the user quits the game, the string "Quit" will be added to
** the bag and the function will return 'q'. If the player's health
** gets to zero, the function will return 'd'.
*********************************************************************/
char Game::checkStatus()
{
	//search bag for winner, return 'w' if found
	if (bag->searchBag("Winner"))
		return 'w';//winner
	//search bag for Quit, return 'q' if found
	else if (bag->searchBag("Quit"))
		return 'q';//quit
	//check health of player, if less than or equal to zero return 'd'
	else if (player->getHealth() <= 0)
		return 'd';//died
	//if none of the conditions are met, return 'r' for still running
	else
		return 'r';//running



}
