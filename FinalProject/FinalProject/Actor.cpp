
#include "Actor.h"
#include "Position.h"

// Constructor and Destructor
Actor::Actor(int hp, int arm, int pwr, int rate, char character, int x, int y) : GameObject(character, x, y) {
	m_health = hp;
	m_armor = arm;
	m_power = pwr;
	m_fireRate = rate;
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