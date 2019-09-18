#ifndef MAP_H
#define MAP_H

#include <vector>

class GameObject;

class Map
{
public:
	Map();
	~Map()=default;
	bool isWall(int x, int y);
	void draw(std::vector<GameObject *> *objects);
	void scroll();
	static const int n_rows = 28;
	static const int n_columns = 100;
	static const int MIN_WALL_DIST = int(n_rows / 1.6);

private:

	static const char WALL = '#';
	static const char SPACE = ' ';
	unsigned int scrollIndex = 0;
	static const unsigned int NUM_FREQS{ 3 };


	double tunnelFreqs[NUM_FREQS] = {0.025, 0.05, 0.10 };
	double tunnelAmps[NUM_FREQS] = {5.0, 2.0, 2.0 };
	
	char m_map[n_rows][n_columns + 1] = {0};
	char m_mapBuffer[n_rows][n_columns + 1] = {0};
};

#endif 
