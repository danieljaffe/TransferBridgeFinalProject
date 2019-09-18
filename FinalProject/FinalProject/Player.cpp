#include "Player.h"
#include "Position.h"
#include "Actor.h"
#include "Game.h"
#include "Bullet.h"
#include <ctime>

// Constructors and Destructors
Player::Player(Game* game, int hp, int arm, int pwr, int rate, char character, int x, int y) : 
	Actor(game, hp, arm, pwr, rate, character, x, y) {

	setNumBullets(1);
}
Player::~Player() {}

void Player::attack(Actor* enemy)
{
	setCurrTime(std::clock_t());

	if (getLastTimeFired() + getFireRate() < getLastTimeFired()) {
		//Actor* enemy = this->getGame()->getPlayer();
		

		Bullet* temp1 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() + 1, getPosition()->getY(), true);
		getGame()->add(temp1);

		if (getNumBullets() == 3) {

			Bullet* temp2 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() + 1, getPosition()->getY() + 1, true);
			Bullet* temp3 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() + 1, getPosition()->getY() - 1, true);


			getGame()->add(temp2);
			getGame()->add(temp3);
		}

		setLastTimeFired(getCurrTime());
	}

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

