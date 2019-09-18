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

void Bullet::update() {

	move();

	int bulletX = getPosition()->getX();
	int bulletY = getPosition()->getY();

	if (m_playerFire) {
		if (getGame()->getMap()->isWall(bulletX + 1, bulletY)) {
			this->~Bullet();
		}
	
		GameObject* npc = this->getGame()->getMap();


		//	m_gameObjects  iterate through this to look for objects and call getCharacter()
	}
	else {
		if (getGame()->getMap()->isWall(bulletX - 1, bulletY)) {
			this->~Bullet();
		}

		Actor* player = this->getGame()->getPlayer();
		if ((player->getPosition()->getX() + 1 == bulletX) &&
			(player->getPosition()->getY() == bulletY)) {
			attack(player);
		}
	}
}