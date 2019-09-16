#ifndef GUNNER_H
#define GUNNER_H

#include "Enemy.h"


class Gunner : public Enemy {
public:
	Gunner();
	virtual ~Gunner();
	virtual void attack(Actor*);
	virtual Position* move();
private:
	// private vars here
};

#endif
