#include "Gunner.h"
#include "Game.h"
#include "Actor.h"
#include <ctime>

Gunner::Gunner(Game* game, int hp, int arm, int pwr, int rate, int sightDistance, char character, int x, int y) :
	Enemy(game, hp, arm, pwr, rate, sightDistance, character, x, y) {

	//m_clock = std::clock();
	m_currTime = std::clock_t();
	m_lastTimeFired = m_currTime;
	// constructor here
}

Gunner::~Gunner()
{
	// deconstructor here
}

void Gunner::attack(Actor*)
{
	/*if (space is not availible) {
		return;
	}*/

	m_currTime = std::clock_t();

	if (m_lastTimeFired + getFireRate() < m_currTime) {

		// fire

		m_lastTimeFired = m_currTime;
	}
}

void Gunner::move()
{


}

void Gunner::update() {

}