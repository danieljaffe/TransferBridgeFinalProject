#ifndef HEALTH_POWER_UP
#define HEALTH_POWER_UP

#include "Effect.h"

class Actor;

class HelathPowerUp : public Effect {
public:
	virtual void applyEffect(Actor*);
private:
	int hpIncreaseAmt;
};

#endif // !HEALTH_POWER_UP



