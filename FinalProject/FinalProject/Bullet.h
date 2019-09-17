#ifndef BULLET_H
#define BULLET_H

#include "Actor.h"

class Bullet : public Actor {
public:
	Bullet();
	virtual ~Bullet();
	virtual void attack(Actor*);
	virtual void move();
private:
	// private vars here
};

#endif // !BULLET_H
