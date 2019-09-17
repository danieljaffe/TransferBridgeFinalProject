#ifndef ACTOR_H
#define ACTOR_H

#include "GameObject.h"
#include <vector>

class Effect;
class Position;

class Actor : public GameObject{
public:
	Actor();
	virtual ~Actor();
	virtual void attack(Actor *);
	virtual Position* move();
	int getArmor();
	int getHealth();
	int getPower();
	int getFireRate();
	void setArmor(int);
	void setHealth(int);
	void setPower(int);
	void setFireRate(int);

private:
	int health;
	int armor;
	int power;
	int fireRate;
	std::vector<Effect*> effects;
};

#endif