#include "TrippleShotPowerUp.h"
#include "Actor.h"

void TrippleShotPowerUp::applyEffect(Actor* actor) {
	actor->setNumBullets(3);
}