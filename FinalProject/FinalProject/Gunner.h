#ifndef GUNNER_H
#define GUNNER_H

#include "Enemy.h"
#include <ctime>

class Game;

class Gunner : public Enemy {
public:
	Gunner(Game*, int hp = 1, int arm = 0, int pwr = 0, int rate = 0, int m_sightDistance = 0, char character = ' ', int x = 0, int y = 0);
	virtual ~Gunner();
	virtual void attack(Actor*);
	virtual void move();
private:
	std::clock_t m_currTime;
	double m_lastTimeFired;
	// private vars here
};

#endif
