#include "Player.h"
#include "Position.h"

// Constructors and Destructors
Player::Player(Game* game, int hp, int arm, int pwr, int rate, char character, int x, int y) : 
	Actor(game, hp, arm, pwr, rate, character, x, y) {}
Player::~Player() {}

void Player::attack(Actor*)
{

}

void Player::move(char input)
{
	int x = getPosition()->getX();
	int y = getPosition()->getY();
	switch (input)
	{
	case 'w': 
	case 'W': y--;
		break;
	case 'a': 
	case 'A': x--;
		break;
	case 's': 
	case 'S': y++;
		break;
	case 'd': 
	case 'D': x++;
		break;
	default:
		break;
	}
	getPosition()->setX(x);
	getPosition()->setY(y);
}

void Player::update()
{
}

void Player::applyEffects()
{
}
