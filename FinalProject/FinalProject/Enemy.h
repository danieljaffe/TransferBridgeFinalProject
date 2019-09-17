#ifndef ENEMY_H
#define ENEMY_H

#include "Actor.h"

class Enemy : public Actor {
public:
	// Constructors and Destructors
	Enemy(int hp = 1, int arm = 0, int pwr = 0, int rate = 0, int m_sightDistance = 0, char character = ' ', int x = 0, int y = 0);
	virtual ~Enemy();

	// Getters
	int getSightDistance();
	
	// Setters
	void setSightDistance(int);
private:
	// Member variables
	int m_sightDistance;
};


#endif
