#ifndef ENEMY_H
#define ENEMY_H

#include "Actor.h"

class Enemy : public Actor {
public:
	// Constructors and Destructors
	Enemy();
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
