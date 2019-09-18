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
}

Gunner::~Gunner()
{
	// deconstructor here
}

void Gunner::attack(Actor* player)
{
	/*if (space is not availible) {
		return;
	}*/

	setCurrTime(std::clock_t());

	if (getLastTimeFired() + getFireRate() < getCurrTime()) {

		Actor* player = this->getGame()->getPlayer();


		int playerX = player->getPosition()->getX();
		int playerY = player->getPosition()->getY();

		int enemyX = getPosition()->getX();
		int enemyY = getPosition()->getY();

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

void Gunner::move()
{
	int movementOffset;
	
	if (getGame()->trueWithProbabitiliy(.5)) {
		movementOffset = getGame()->randInt(-1, 1);
	}
	
	setPosition(getPosition()->getX(), getPosition()->getY() + movementOffset);
	int x = getPosition()->getX();

	int y = getPosition()->getY();
	if (getGame()->getMap()->isWall(x, y)) {

		this->getGame()->remove(this);

	}

}

void Gunner::update() {
	if (getHealth() <= 0) {
		this->getGame()->setScore(4);
		this->getGame()->remove(this);
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


	if (playerY == enemyY) {
		attack(player);
	}

	setStartingMoves(getSightDistance() - 1);
}