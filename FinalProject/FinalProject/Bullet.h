#ifndef BULLET_H
#define BULLET_H

#include "Actor.h"

class Game;

class Bullet : public Actor {
public:
	Bullet(Game*, int hp = 1, int arm = 0, int pwr = 1, int rate = 0, char character = '-', 
		int x = 0, int y = 0, bool playerFire = false);
	bool getPlayerFire();
	void setPlayerFire(bool);
	virtual ~Bullet();
	virtual void attack(Actor*);
	virtual void move();
	virtual void update();
private:
	bool m_playerFire;
};

#endif // !BULLET_H
