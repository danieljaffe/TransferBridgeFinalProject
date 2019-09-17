#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"

class Player : public Actor {
public:
	Player();
	virtual ~Player();
	virtual void attack(Actor*);
	virtual void move();
	void applyEffects();
private:
	// private vars here
};

#endif