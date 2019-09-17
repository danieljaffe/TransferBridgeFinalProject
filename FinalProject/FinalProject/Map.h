#ifndef MAP
class Map
{
public:
	Map();
	~Map()=default;
	void draw();
	void scroll();
	static const int n_rows = 28;
	static const int n_columns = 100;
	static const int MIN_WALL_DIST = int(n_rows / 1.6);

private:

	static const char WALL = '#';
	static const char SPACE = ' ';

	unsigned int scrollIndex = 0;

	double tunnelFreqs[3] = {0.025, 0.05, 0.10 };
	double tunnelAmps[3] = {5.0, 2.0, 2.0 };
	
	char m_map[n_rows][n_columns + 1] = {0};
};
#endif 
