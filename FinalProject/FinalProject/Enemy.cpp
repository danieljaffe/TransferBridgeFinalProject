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

// Setters
void Enemy::setSightDistance(int sightDistance) { m_sightDistance = sightDistance; }
