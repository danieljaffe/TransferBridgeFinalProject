#ifndef MAP
class Map
{
public:
	Map();
	~Map();
	void draw();
	void scroll();



private:
	static const int n_rows = 75; 
	static const int n_columns = 22; 
};
#endif 
