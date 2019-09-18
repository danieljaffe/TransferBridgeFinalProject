#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Position;
class Game;

class GameObject {
public:
	// Constructors and Destructors
	GameObject(Game*, char character = ' ', int x=0, int y=0);
	virtual ~GameObject();
	
	// Getters
	char getDisplayChar();
	Position* getPosition();
	Game* getGame();
	
	// Setters
	void setPosition(Position*);
	void setPosition(int x, int y);
	void setDisplayChar(char);
	void setGame(Game*);

private:
	// Member variables
	char m_displayChar;
	Position* m_pos;
	Game* m_game;
};

#endif