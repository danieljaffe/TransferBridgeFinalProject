#include "GameObject.h"
#include "Position.h"
#include "Map.h"

// Constructors and Destructors
GameObject::GameObject(Game* game, char character, int x, int y) : m_pos(new Position(x,y)) { 
	m_game = game;
	m_displayChar = character; 
	m_destroy = false;
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

void GameObject::setDestroyFlag(bool destroy)
{
	m_destroy = destroy;
}

bool GameObject::getDestroyFlag()
{
	return m_destroy;
}

void GameObject::update()
{
	int x = getPosition()->getX();
	int y = getPosition()->getY();

	if ((x <= 1) || (y <= 0))
	{
		setDestroyFlag(true);
	}
	if ((x >= Map::n_columns) || (y >= Map::n_rows - 1))
	{
		setDestroyFlag(true);
	}
}
