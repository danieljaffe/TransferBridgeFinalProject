#include "Gunner.h"
#include "Game.h"
#include "Actor.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Position.h"
#include <ctime>

Gunner::Gunner(Game* game, int hp, int arm, int pwr, int rate, int sightDistance, char character, int x, int y) :
	Enemy(game, hp, arm, pwr, rate, sightDistance, character, x, y) {

	//m_clock = std::clock();	
	// constructor here

	setStartingMoves(10);
}

Gunner::~Gunner()
{
	// deconstructor here
}

void Gunner::attack(Actor* player)
{
	setCurrTime();


	if (std::difftime(getCurrTime(), getLastTimeFired()) > getFireRate()) {

		Actor* player = this->getGame()->getPlayer();


		int playerX = player->getPosition()->getX();
		int playerY = player->getPosition()->getY();

		int enemyX = getPosition()->getX();
		int enemyY = getPosition()->getY();

		Bullet* temp1 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() - 1, getPosition()->getY(), false);
		getGame()->add(temp1);

		if (getNumBullets() == 3) {

			Bullet* temp2 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() - 1, getPosition()->getY() + 1, false);
			Bullet* temp3 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() - 1, getPosition()->getY() - 1, false);


			getGame()->add(temp2);
			getGame()->add(temp3);
		}

		setLastTimeFired(getCurrTime());
	}
}

void Gunner::move()
{
	/*int movementOffset=0;
	
	if (getGame()->trueWithProbability(.5)) {
		movementOffset = getGame()->randInt(-2, 1);
	}
	
	setPosition(getPosition()->getX(), getPosition()->getY() + movementOffset);
	int x = getPosition()->getX();

	int y = getPosition()->getY();
	if (getGame()->getMap()->isWall(x, y)) {

		this->getGame()->remove(this);

	}*/

}

void Gunner::update() {
	if (getHealth() <= 0) {
		this->getGame()->setScore(4);
		this->getGame()->remove(this);
		return;
	}

	// Check for wall collisions
	int x = getPosition()->getX();
	int y = getPosition()->getY();
	if (getGame()->getMap()->isWall(x, y)) {
		//this->getGame()->remove(this);
		this->setDestroyFlag(true);
		return;
	}

	Actor* player = this->getGame()->getPlayer();

	int playerX = player->getPosition()->getX();
	int playerY = player->getPosition()->getY();

	int enemyX = getPosition()->getX();
	int enemyY = getPosition()->getY();


	if (getStartingMoves() >= 0) {
		setPosition(enemyX - 1, enemyY);
	}
	else {
		move();
	}

	attack(player);


	setStartingMoves(getStartingMoves() - 1);
}