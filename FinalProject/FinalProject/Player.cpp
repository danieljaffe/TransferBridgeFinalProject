#include "Player.h"
#include "Position.h"
#include "Actor.h"
#include "Game.h"
#include "Bullet.h"
#include "UserInterface.h"
#include "Item.h"
#include "Effect.h"
#include <iostream>
#include <vector>
#include <ctime>

// Constructors and Destructors
Player::Player(Game* game, int hp, int arm, int pwr, int rate, char character, int x, int y) : 
	Actor(game, hp, arm, pwr, rate, character, x, y) {

	setNumBullets(1);
}
Player::~Player() {}

void Player::attack(Actor* enemy)
{
	setCurrTime();	


	if (std::difftime(getCurrTime(), getLastTimeFired()) > getFireRate()) {
		
		//Actor* enemy = this->getGame()->getPlayer();

		

		Bullet* temp1 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() + 1, getPosition()->getY(), true);
		getGame()->add(temp1);

		if (getNumBullets() == 3) {

			Bullet* temp2 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() + 1, getPosition()->getY() + 1, true);
			Bullet* temp3 = new Bullet(getGame(), 1, 0, 1, 0, '-', getPosition()->getX() + 1, getPosition()->getY() - 1, true);


			getGame()->add(temp2);
			getGame()->add(temp3);
		}

		setLastTimeFired(getCurrTime());
	}

}

void Player::move()
{
	char input;
	getCharIfAny(input);

	int x = getPosition()->getX();
	int y = getPosition()->getY();
	switch (input)
	{
	case ARROW_UP: y--;
		break;
	case ARROW_LEFT: x--;
		break;
	case ARROW_DOWN: y++;
		break;
	case ARROW_RIGHT: x++;
		break;
	case SPACE_BAR: 
		attack(nullptr);
		break;
	default:
		break;
	}
	if (getGame()->getMap()->isWall(x, y)) {
		getGame()->setGameOver(true);
		//this->getGame()->remove(this);
		return;
	}
	getPosition()->setX(x);
	getPosition()->setY(y);
}

void Player::update()
{
	if (getHealth() <= 0) {
		this->getGame()->remove(this);
		return;
	}

	move();

	std::vector<GameObject*> gameObjects = getGame()->getGameObjects();

	for (int i = 0; i < gameObjects.size(); i++) {
		if ((gameObjects.at(i)->getPosition() == getPosition()) && ((gameObjects.at(i)->getDisplayChar() == '$') 
			|| (gameObjects.at(i)->getDisplayChar() == '+'))) {


			// you found an item. add it to the player's collection or something

			Item* item = (Item*)gameObjects.at(i);
			addEffect(item->getEffect());
			getGame()->remove(item);
		}
	}

	applyEffects();
	
}

void Player::applyEffects()
{
	std::vector<Effect*>* effectsOnPlayer = getEffects();

	if (effectsOnPlayer->size() != 0) {
		effectsOnPlayer->at(0)->applyEffect(this);
		this->removeEffect(effectsOnPlayer->at(0));
	}
}

