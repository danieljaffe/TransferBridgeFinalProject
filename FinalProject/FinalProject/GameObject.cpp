#include "GameObject.h"
#include "Position.h"

// Constructors and Destructors
GameObject::GameObject(Game* game, char character, int x, int y) : m_pos(new Position(x,y)) { 
	m_game = game;
	m_displayChar = character; 
}
GameObject::~GameObject() { 
	delete m_pos;
}

// Getters
Position* GameObject::getPosition() { return m_pos; }
char GameObject::getDisplayChar() {	return m_displayChar; }
Game* GameObject::getGame() { return m_game; }

// Setters
void GameObject::setPosition(Position* pos) { m_pos = pos; }
void GameObject::setPosition(int x, int y) { m_pos->setX(x); m_pos->setY(y); }
void GameObject::setDisplayChar(char character) { m_displayChar = character; }
void GameObject::setGame(Game* game) { m_game = game; }