#ifndef GUNNER_H
#define GUNNER_H

#include "Enemy.h"
#include "Map.h"
#include <ctime>

class Game;
class Actor;

class Gunner : public Enemy {
public:
	Gunner(Game*, int hp = 2, int arm = 1, int pwr = 1, int rate = 1, int m_sightDistance = Map::n_columns, char character = '{', int x = 0, int y = 0);
	virtual ~Gunner();
	virtual void attack(Actor*);
	virtual void move();
	virtual void update();
private:
	
	// private vars here
};

#endif
