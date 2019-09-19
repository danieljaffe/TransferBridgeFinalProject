#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Effect;

class Item : public GameObject
{
public:
	Item(Effect*, Game*, char character = ' ', int x = 0, int y = 0);
	virtual ~Item();
	Effect* getEffect();
	void setEffect(Effect*);
private:
	Effect* m_effect;
};

#endif