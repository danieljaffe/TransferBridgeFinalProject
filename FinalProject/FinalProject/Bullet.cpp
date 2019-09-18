#include "Bullet.h"
#include "Position.h"
#include "Game.h"
#include "Map.h"

Bullet::Bullet(Game* game, int hp, int arm, int pwr, int rate, char character, 
	int x, int y, bool playerFire) : 
	Actor(game, hp, arm, pwr, rate, character, x, y)
{
	setPlayerFire(playerFire);
}
Bullet::~Bullet() {}

bool Bullet::getPlayerFire() { return m_playerFire; }
void Bullet::setPlayerFire(bool playerFire) { m_playerFire = playerFire; }

void Bullet::attack(Actor* actor)
{
	int enemyHealth = actor->getHealth();
	int enemyArmor = actor->getArmor();

	if (getPower() > enemyArmor) {
		actor->setArmor(0);
		actor->setHealth(enemyHealth - (getPower() - enemyArmor));
	}
	else {
		actor->setArmor(enemyArmor - getPower());
	}

	this->getGame()->remove(this);
}

void Bullet::move()
{
	int bulletX = getPosition()->getX();
	if (m_playerFire) { bulletX++; }
	else { bulletX--; }
	getPosition()->setX(bulletX);
}



// This function could use clean up post mortum  :P 
void Bullet::update() {

	move();

	int bulletX = getPosition()->getX();
	int bulletY = getPosition()->getY();

	if (m_playerFire) {
		if (getGame()->getMap()->isWall(bulletX + 1, bulletY)) {
			this->getGame()->remove(this);
			return;
		}

		// This is ugly and slow but forced due to the way the map ended up being implemented
		// Iterates through all in play game object and checks if their position is one ahead of
		// the buller and if it is of an enemy type. Attacks if this is true.
		std::vector<GameObject*> gameObjects = getGame()->getGameObjects();
		for (int i = 0; i < gameObjects.size(); i++) {
			GameObject* checkObject = gameObjects.at(i);
			char type = checkObject->getDisplayChar();
			if ((bulletX + 1 == checkObject->getPosition()->getX()) && (type == '{' || type == '<')) {
				// This is bad practice but again, forced due to the setup of the project
				// Be sure to check for the correct character types or this will blow up!  :)
				Actor* enemy = (Actor*)checkObject;
				attack(enemy);
				this->getGame()->setScore(1);
				return;
			}
		}
	}
	else {
		if (getGame()->getMap()->isWall(bulletX - 1, bulletY)) {
			this->getGame()->remove(this);
		}

		Actor* player = this->getGame()->getPlayer();
		if ((player->getPosition()->getX() + 1 == bulletX) &&
			(player->getPosition()->getY() == bulletY)) {
			attack(player);
		}
	}
}