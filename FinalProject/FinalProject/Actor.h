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
	std::time_t getCurrTime();
	std::time_t getLastTimeFired();
	std::vector<Effect*>* getEffects();
	void setLastTimeFired(std::time_t);
	void setCurrTime();
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
	std::time_t m_currTime;
	std::time_t m_lastTimeFired;
	std::vector<Effect*>* m_effects;
};

#endif