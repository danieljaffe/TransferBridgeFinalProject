#include "Map.h"
#include <iostream>
using namespace std; 

//Constructor
Map::Map(){
	//init top and bottom to # sign
	for (int i = 0; i < n_columns; i++) {
		m_map[0][i] = '#';
		m_map[n_rows][i] = '#';
	}
}

void Map::draw() {
	for (int i = 0; i < n_rows; i++) {
		cout << m_map[i] << endl; 
	}
}
