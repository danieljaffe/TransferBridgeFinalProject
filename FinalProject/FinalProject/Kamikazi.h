#ifndef KAMIKAZI_H
#define KAMIKAZI_H

#include "Enemy.h"

class Kamikazi : public Enemy {
public:
	Kamikazi(int hp = 1, int arm = 0, int pwr = 0, int rate = 0, int m_sightDistance = 0, char character = ' ', int x = 0, int y = 0);
	virtual ~Kamikazi();
	virtual void attack(Actor*);
	virtual void move(Actor*);
private:
	// private vars here
};

#endif
