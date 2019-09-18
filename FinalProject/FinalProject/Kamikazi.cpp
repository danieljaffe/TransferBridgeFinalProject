#include "Kamikazi.h"
#include "Position.h"
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

	this->getGame()->remove(this);
}

void Kamikazi::update() {
	if (getHealth() <= 0) {
		this->getGame()->setScore(2);
		this->getGame()->remove(this);
		return;
	}

	// Check for wall collisions
	int x = getPosition()->getX();
	int y = getPosition()->getY();
	if (getGame()->getMap()->isWall(x, y)) {
		this->getGame()->remove(this);
	}
	// end Check
	
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

	

	if ((playerX + 1 == enemyX) && (playerY == enemyY)) {
		attack(player);
	}	

	setStartingMoves(getSightDistance() - 1);
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
