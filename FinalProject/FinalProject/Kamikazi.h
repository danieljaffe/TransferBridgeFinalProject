#ifndef KAMIKAZI_H
#define KAMIKAZI_H

#include "Enemy.h"

class Kamikazi : public Enemy {
public:
	Kamikazi();
	virtual ~Kamikazi();
	virtual void attack(Actor*);
	virtual Position* move();
private:
	// private vars here
};

#endif
