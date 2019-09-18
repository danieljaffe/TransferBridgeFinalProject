#ifndef KAMIKAZI_H
#define KAMIKAZI_H

#include "Enemy.h"

class Kamikazi : public Enemy {
public:
	Kamikazi(Game*, int hp = 1, int arm = 0, int pwr = 0, int rate = 0, int m_sightDistance = 0, char character = ' ', int x = 0, int y = 0);
	virtual ~Kamikazi();
	virtual void attack(Actor*);
	//virtual void updatePosition(Actor*, int);
	virtual void move(Actor*);
private:
	int startingMoves; // movement state
	// private vars here
};

#endif
