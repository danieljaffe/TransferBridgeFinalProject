#ifndef GUNNER_H
#define GUNNER_H

#include "Enemy.h"
#include <ctime>

class Game;

class Gunner : public Enemy {
public:
	Gunner(Game*, int hp = 2, int arm = 1, int pwr = 1, int rate = 1, int m_sightDistance = 0, char character = '{', int x = 0, int y = 0);
	virtual ~Gunner();
	virtual void attack(Actor*);
	virtual void move();
	virtual void update();
private:
	std::clock_t m_currTime;
	double m_lastTimeFired;
	// private vars here
};

#endif
