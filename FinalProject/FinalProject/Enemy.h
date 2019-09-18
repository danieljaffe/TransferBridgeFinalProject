#ifndef ENEMY_H
#define ENEMY_H

#include "Actor.h"

class Game;

class Enemy : public Actor {
public:
	// Constructors and Destructors
	Enemy(Game*, int hp = 1, int arm = 0, int pwr = 0, int rate = 0, int m_sightDistance = 0, char character = ' ', int x = 0, int y = 0);
	virtual ~Enemy();
	//virtual void updatePosition() = 0;

	// Getters
	int getSightDistance();
	int getStartingMoves();
	
	// Setters
	void setSightDistance(int);
	void setStartingMoves(int);
private:
	// Member variables
	int m_startingMoves; // movement state
	int m_sightDistance;
};


#endif
