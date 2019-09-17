#include "Map.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std; 

//Constructor
Map::Map(){
	srand(time(0));
	//init top and bottom to # sign
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_columns; j++) {
			m_map[i][j] = Map::SPACE; 
		}
	}

	for (int i = 0; i < n_columns; i++) {
		m_map[0][i] = Map::WALL;
		m_map[n_rows-1][i] = Map::WALL;
	}
	// set null termination 
	for (int i = 0; i < n_rows; i++) {
		m_map[i][Map::n_columns] = '\0';
		//m_map[i][n_columns - 1] = Map::WALL;
	}
	
}


void Map::scroll() {
	int min = 1 + Map::MIN_WALL_DIST / 2;
	int max = n_rows - 2 - Map::MIN_WALL_DIST / 2;
	int offset = min + (rand() % (max - min));

	for (int i = 0; i < 4; i++)
	{
		offset += tunnelAmps[i] * sin(tunnelFreqs[i] * scrollIndex);
	}

	//shift everything over left 1 
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_columns - 1; j++) {
			m_map[i][j] = m_map[i][j + 1];
		}
	}
	//set new column 
	for (int i = 0; i < n_rows; i++) {
		if (abs(i - offset) > MIN_WALL_DIST / 2) {
			m_map[i][n_columns - 1] = Map::WALL;
		}
		else {
			m_map[i][n_columns - 1] = Map::SPACE; 
		}
	}

	++scrollIndex;
}

void Map::draw() {
	for (int i = 0; i < n_rows; i++) {
		cout << m_map[i] << endl; 
	}
	
}
