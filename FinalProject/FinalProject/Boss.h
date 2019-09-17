#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"

class Actor;
class Position;

class Boss : public Enemy {
public:
	Boss();
	virtual ~Boss();
	virtual void attack(Actor*);
	virtual Position* move();
private:
	// private vars here
};

#endif