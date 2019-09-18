#include "Item.h"
#include "GameObject.h"
#include "Game.h"

Item::Item(Effect* e, Game* game, char character, int x, int y) : GameObject(game, character, x, y)
{
	m_effect = e;
}

Effect* Item::getEffect()
{
	return m_effect;
}

void Item::setEffect(Effect* e)
{
	m_effect = e;
}

Item::~Item() {
	delete m_effect;
}
