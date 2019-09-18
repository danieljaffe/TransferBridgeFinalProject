#include "Kamikazi.h"
#include "Position.h"
#include "Game.h"
#include "Actor.h"
#include "Enemy.h"
#include "Map.h"
#include <cmath>

Kamikazi::Kamikazi(Game* game, int hp, int arm, int pwr, int rate, int sightDistance, char character, int x, int y) :
	Enemy(game, hp, arm, pwr, rate, sightDistance, character, x, y) {
	
	setStartingMoves(Map::n_columns / 8);
	

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

	this->setDestroyFlag(true);
	//this->getGame()->remove(this);
}

void Kamikazi::update() {
	Actor::update();
	// Check for wall collisions
	int x = getPosition()->getX();
	int y = getPosition()->getY();
	if (getGame()->getMap()->isWall(x, y)) {
		//this->getGame()->remove(this);
		this->setDestroyFlag(true);
		return;
	}
	// end Check
	
	Actor* player = this->getGame()->getPlayer();

	int playerX = player->getPosition()->getX();
	int playerY = player->getPosition()->getY();

	int enemyX = getPosition()->getX();
	int enemyY = getPosition()->getY();
	
	

	move();
	

	if ((playerX + 1 == enemyX) && (playerY == enemyY)) {
		attack(player);
	}	

	
}

void Kamikazi::move()
{
	//Position* newPos = getPosition();

	Actor* player = this->getGame()->getPlayer();

	if (getPosition() == player->getPosition()) {
		attack(player);
		return;
	}
	
	int playerX = player->getPosition()->getX();
	int playerY = player->getPosition()->getY();

	int enemyX = getPosition()->getX();
	int enemyY = getPosition()->getY();

	/*int separationDistance = std::sqrt(std::pow((enemyX - playerX), 2) + std::pow((enemyY - playerY), 2));*/

	
		
		
	if (playerY > enemyY) {
		setPosition(enemyX - 2, enemyY + 1);
	}
	else if (playerY < enemyY) {
		setPosition(enemyX - 2, enemyY - 1);
	}
	else {
		setPosition(enemyX - 2, enemyY);
	}		
	
	//return newPos;
}
