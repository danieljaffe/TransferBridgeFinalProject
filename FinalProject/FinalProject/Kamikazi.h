#ifndef KAMIKAZI_H
#define KAMIKAZI_H

#include "Enemy.h"
#include "Game.h"
#include "Map.h"

class Actor;

class Kamikazi : public Enemy {
public:
	Kamikazi(Game*, int hp = 1, int arm = 0, int pwr = 1, int rate = 0, int m_sightDistance = Map::n_columns, char character = '<', int x = 0, int y = 0);
	virtual ~Kamikazi();
	virtual void attack(Actor*);
	//virtual void updatePosition(Actor*, int);
	virtual void move();
	virtual void update();
private:
	
	// private vars here
};

#endif
