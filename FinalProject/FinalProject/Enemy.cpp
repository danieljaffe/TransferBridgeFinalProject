#include "Enemy.h"

Enemy::Enemy(Game* game, int hp, int arm, int pwr, int rate, int sightDistance, char character, int x, int y) : 
	Actor(game, hp, arm, pwr, rate, character, x, y) {

	m_sightDistance = sightDistance;
}

Enemy::~Enemy()
{
	// destructor here
}

// Getters
int Enemy::getSightDistance() {	return m_sightDistance; }

int Enemy::getStartingMoves()
{
	return m_startingMoves;
}

// Setters
void Enemy::setSightDistance(int sightDistance) { m_sightDistance = sightDistance; }

void Enemy::setStartingMoves(int startMoves)
{
	m_startingMoves = startMoves;
}
