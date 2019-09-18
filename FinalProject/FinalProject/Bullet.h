#ifndef BULLET_H
#define BULLET_H

#include "Actor.h"

class Bullet : public Actor {
public:
	Bullet(Game*, int hp = 1, int arm = 0, int pwr = 0, int rate = 0, char character = '-', int x = 0, int y = 0);
	virtual ~Bullet();
	virtual void attack(Actor*);
	virtual void move();
	virtual void update();
private:
	// private vars here
};

#endif // !BULLET_H
