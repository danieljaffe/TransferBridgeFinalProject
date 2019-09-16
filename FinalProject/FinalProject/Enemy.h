#ifndef ENEMY_H
#define ENEMY_H

#include "Actor.h"

class Enemy : public Actor {
public:
	Enemy();
	virtual ~Enemy();
	int getSightDistance();
	void setSightDistance(int);
private:
	int sightDistance;
};


#endif
