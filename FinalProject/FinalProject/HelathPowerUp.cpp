#include "HelathPowerUp.h"
#include "Actor.h"

void HelathPowerUp::applyEffect(Actor* actor)
{	
	actor->setHealth(actor->getHealth() + hpIncreaseAmt);
}
