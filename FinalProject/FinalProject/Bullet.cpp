#include "Bullet.h"

Bullet::Bullet(Game* game, int hp, int arm, int pwr, int rate, char character, int x, int y) : Actor(game, hp, arm, pwr, rate, character, x, y)
{

}

Bullet::~Bullet()
{
}

void Bullet::attack(Actor*)
{
}


//void Bullet::move(bool playerShot)
//{
//
//	int x = getPosition()->getX();
//	int y = getPosition()->getY();
//	switch (input)
//	{
//	case 'w':
//	case 'W': y--;
//		break;
//	case 'a':
//	case 'A': x--;
//		break;
//	case 's':
//	case 'S': y++;
//		break;
//	case 'd':
//	case 'D': x++;
//		break;
//	default:
//		break;
//	}
//	getPosition()->setX(x);
//	getPosition()->setY(y);
//}

void Bullet::move()
{
}

void Bullet::update()
{

}
