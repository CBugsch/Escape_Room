/********************************************************************
** Name: Christpher Bugsch
** Date: 3/19/17
** Description: Function defintions for the Player class
********************************************************************/

#include "Player.hpp"

/********************************************************************
** return int health value
** 
********************************************************************/
int Player::getHealth()
{
	return health;
}


/********************************************************************
** Sets health value in the event the player has failed to interact
** with a space
********************************************************************/
void Player::setHealth()
{
	//subtract 10 from health
	health = health - 10;
	//alert user
	std::cout << "You've hurt yourself trying, your health is now: " << health << std::endl;

}

/********************************************************************
** Class constructor sets initial health value to 100
**
********************************************************************/
Player::Player()
{
	health = 100;
}