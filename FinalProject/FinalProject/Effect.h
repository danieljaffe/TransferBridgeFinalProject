#ifndef EFFECT_H
#define EEFECT_H

class Actor;

class Effect
{
public:
	Effect();
	~Effect();

	virtual void applyEffect(Actor*) = 0;
private:
		
	// private vars here
};

#endif