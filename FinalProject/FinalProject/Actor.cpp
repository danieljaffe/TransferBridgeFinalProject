
#include "Actor.h"
#include "Position.h"

// Constructor and Destructor
Actor::Actor(Game* game, int hp, int arm, int pwr, int rate, char character, int x, int y) : GameObject(game, character, x, y) {
	setGame(game);
	m_health = hp;
	m_armor = arm;
	m_power = pwr;
	m_fireRate = rate;
	m_numBullets = 0;
}

Actor::~Actor() {

}

// Getters
int Actor::getHealth() { return m_health; }
int Actor::getArmor() { return m_armor; }
int Actor::getPower() { return m_power; }
int Actor::getFireRate() { return m_fireRate; }

// Setters
void Actor::setHealth(int hp) { m_health = hp; }
void Actor::setArmor(int arm) { m_armor = arm; }
void Actor::setPower(int pwr) { m_power = pwr; }
void Actor::setFireRate(int fireRate) { m_fireRate = fireRate; }

bool Actor::removeEffect(Effect* effect)
{
	for (int i = 0; i < m_effects->size(); i++)
	{
		if (m_effects->at(i) == effect)
		{
			m_effects->erase(m_effects->begin() + i);
			delete effect;
			return true;
		}
	}
	return false;
}

void Actor::addEffect(Effect* effect)
{
	m_effects->push_back(effect);
}

int Actor::getNumBullets()
{
	return m_numBullets;
}

void Actor::setNumBullets(int number)
{
	m_numBullets = number;
}
