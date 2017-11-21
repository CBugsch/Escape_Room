/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function declarations for the Player class
*********************************************************************/
#include <iostream>
#include <string>

class Player
{
protected:
	//class variable
	int health;
public:
	//function prototypes
	int getHealth();
	void setHealth();
	Player();
};