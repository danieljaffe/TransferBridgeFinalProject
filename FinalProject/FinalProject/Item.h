#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Effect;

class Item : public GameObject
{
public:
	Item();
	virtual ~Item();
	Effect* getEffect();
	void setEffect(Effect*);
private:
	Effect* effect;
};

#endif