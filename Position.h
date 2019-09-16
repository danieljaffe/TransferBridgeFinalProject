#ifndef POSITION_INCLUDED
#define POSITION_INCLUDED

class Position {
public:
	// Constructors
	Position(int x = 0, int y = 0);
	~Position();

	// Getters
	int getX();
	int getY();

	// Setters
	void setX(int x);
	void setY(int y);

private:
	// Member variables
	int xPos;
	int yPos;
};

#endif // POSITION_INCLUDED