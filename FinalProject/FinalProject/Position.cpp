#include "Position.h"

//Constructors
Position::Position(int x, int y) { setX(x); setY(y); }
Position::~Position() {}

//Getters
int Position::getX() { return xPos; }
int Position::getY() { return yPos; }

//Setters
void Position::setX(int x) { xPos = x; }
void Position::setY(int y) { yPos = y; }