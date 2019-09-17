#ifndef BOSS_H
#define BOSS_H

class Boss : public Enemy {
public:
	Boss();
	virtual ~Boss();
	virtual void attack(Actor*);
	virtual Position* move();
private:
	// private vars here
};

#endif