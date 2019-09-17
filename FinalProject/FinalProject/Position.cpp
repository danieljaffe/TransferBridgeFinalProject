#include Position.h

Constructors
PositionPosition(int x, int y) { setX(x); setY(y); }
Position~Position() {}

Getters
int PositiongetX() { return xPos; }
int PositiongetY() { return yPos; }

Setters
void PositionsetX(int x) { xPos = x; }
void PositionsetY(int y) { yPos = y; }