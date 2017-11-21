/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Runs escape room game (cheat sheet instructions can be
				found within the zip file in a seperate txt)
*********************************************************************/

#include "Game.hpp"
#include <limits>


/********************************************************************
** Function displays a rough image of the current space to add a
** more visual element to the game.
** Code for this function was taken www.cplusplus.com/forum/general/58945/
********************************************************************/
void displayArt(string s)
{

	string imageLines = "";//set string image to blank
	string fileName = s;//set file name to passed string
	ifstream inputFile;
	inputFile.open(fileName.c_str());//open file

	if (inputFile)
	{
		while (inputFile)
		{
			string temp;
			getline(inputFile, temp);//get line of text
			temp += "\n";//add a new line
			imageLines += temp;//add text to string image
		}
		cout << imageLines << endl;//print string image

		inputFile.close();//close file
	}
	else
		cout << "ERROR: Image file wasn't found..." << endl;

}



int main()
{
	string fileName;//used to display image
	char status = 'r';//running
	srand(time(NULL));//initialize random seed
	Game game;//create a game

	fileName = "./Final Project Images/EscapeRoomLogo.txt";
	displayArt(fileName);//display game logo 

	//display opening message 
	cout << "Welcome to Christopher's Escape Room" << endl << endl
		<< "Look around for items that could help you escape " << endl
		<< "But be careful, everytime you interact with something, you might hurt yourself" << endl
		<< "If you're health reaches '0' before you escape, you'll die in this room!" << endl 
		<<  "Press enter to begin when you're ready!" << endl << endl;
	
	//pause so user can read opening message
	cin.ignore(numeric_limits <streamsize> :: max(), '\n');
	

	//while status of game is 'running'
	while (status == 'r')
	{
		//display current space
		game.displayScreen(); 
		//display and get choice from space menu
		game.menu();
		//return current status of game
		status = game.checkStatus();
	}
	//if game status return 'w' you've won the game
	if (status == 'w')
	{
		cout << "You've escaped the room alive!";
		fileName = "./Final Project Images/Winner.txt";
		displayArt(fileName);
	}
	
	//if game status returns a 'q' it means user quit the game early
	else if (status == 'q')
	{
		cout << "You've quit the game early";
	}

	//if game status returns a 'd' it means player has died
	else if (status == 'd')
	{
		cout << "You've died in the room!";
		fileName = "./Final Project Images/Loser.txt";
		displayArt(fileName);
	}


	



	return 0;
}
