#ifndef GUNNER_H
#define GUNNER_H

#include "Enemy.h"


class Gunner : public Enemy {
public:
	Gunner();
	virtual ~Gunner();
	virtual void attack(Actor*);
	virtual void move();
private:
	// private vars here
};

#endif
