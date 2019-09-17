#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Position;

class GameObject {
public:
	GameObject();
	virtual ~GameObject();
	Position* getPosition();
	void setPosition(Position*);
	char getDisplayChar();
	void setDisplayChar(char);

private:
	char displayChar;
	Position* pos;
};

#endif