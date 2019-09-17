#include "Kamikazi.h"
#include "Position.h"
#include <cmath>

Kamikazi::Kamikazi(int hp, int arm, int pwr, int rate, int sightDistance, char character, int x, int y) :
	Enemy(hp, arm, pwr, rate, sightDistance, character, x, y) {
	
	// constructor here
}

Kamikazi::~Kamikazi()
{
	// Destructor here
}

void Kamikazi::attack(Actor* actor)
{
	int enemyHealth = actor->getHealth();
	int enemyArmor = actor->getArmor();

	if (getPower() > enemyArmor) {
		actor->setArmor(0);
		actor->setHealth(enemyHealth - (getPower() - enemyArmor));
	}
	else {
		actor->setArmor(enemyArmor - getPower());
	}	
}

void Kamikazi::updatePosition(Actor* actor, int startingMoves) {

}

void Kamikazi::move(Actor* player)
{
	//Position* newPos = getPosition();

	if (getPosition() == player->getPosition()) {
		attack(player);
	}
	
	int playerX = player->getPosition()->getX();
	int playerY = player->getPosition()->getY();

	int enemyX = getPosition()->getX();
	int enemyY = getPosition()->getY();

	int separationDistance = std::sqrt(std::pow((enemyX - playerX), 2) + std::pow((enemyY - playerY), 2));

	if (separationDistance <= getSightDistance()) {
		setPosition(enemyX - 1, enemyY);
		
		if (playerY > enemyY) {
			setPosition(this->getPosition()->getX(), enemyY + 1);
		}
		else if (playerY < enemyY) {
			setPosition(this->getPosition()->getX(), enemyY - 1);
		}
		else {
			// player and enemy are on same y-coord. Just move along x only
		}		
	}

	//return newPos;
}
