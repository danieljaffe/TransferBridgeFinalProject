#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Position;

class GameObject {
public:
	// Constructors and Destructors
	GameObject(char character = ' ', int x=0, int y=0);
	virtual ~GameObject();
	
	// Getters
	char getDisplayChar();
	Position* getPosition();
	
	// Setters
	void setPosition(Position*);
	void setPosition(int x, int y);
	void setDisplayChar(char);

	virtual void update() = 0;
private:
	// Member variables
	char m_displayChar;
	Position* m_pos;
};

#endif