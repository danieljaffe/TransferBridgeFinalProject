#ifndef ACTOR_H
#define ACTOR_H

#include "GameObject.h"
#include <vector>

class Effect;
class Position;

class Actor : public GameObject{
public:
	Actor(int hp=1, int arm=0, int pwr=0, int rate=0, char character=' ', int x=0, int y=0);
	virtual ~Actor();
	virtual void attack(Actor *) = 0;
	virtual void move() = 0;
	int getArmor();
	int getHealth();
	int getPower();
	int getFireRate();
	void setArmor(int);
	void setHealth(int);
	void setPower(int);
	void setFireRate(int);

private:
	int m_health;
	int m_armor;
	int m_power;
	int m_fireRate;
	std::vector<Effect*> m_effects;
};

#endif