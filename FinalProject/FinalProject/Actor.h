#ifndef ACTOR_H
#define ACTOR_H

#include "GameObject.h"
#include <vector>
#include <ctime>

class Effect;
class Position;
class Game;

class Actor : public GameObject{
public:
	Actor(Game*, int hp=1, int arm=0, int pwr=0, int rate=0, char character=' ', int x=0, int y=0);
	virtual ~Actor();
	virtual void attack(Actor *) = 0;
	virtual void move() = 0;
	int getArmor();
	int getHealth();
	int getPower();
	int getFireRate();
	int getNumBullets();
	double getCurrTime();
	double getLastTimeFired();
	std::vector<Effect*>* getEffects();
	void setLastTimeFired(double);
	void setCurrTime(double);
	void setNumBullets(int);
	void setArmor(int);
	void setHealth(int);
	void setPower(int);
	void setFireRate(int);
	bool removeEffect(Effect*);
	void addEffect(Effect*);

private:
	int m_health;
	int m_armor;
	int m_power;
	int m_fireRate;
	int m_numBullets;
	std::clock_t m_currTime;
	double m_lastTimeFired;
	std::vector<Effect*>* m_effects;
};

#endif