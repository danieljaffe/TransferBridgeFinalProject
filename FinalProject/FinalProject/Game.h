#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Gameboard.h"
#include "GameObject.h"
#include "UserInterface.h"
#include "Map.h" 
#include <string>
#include <vector>
// [Add other #include directives as necessary.]

class Map;

class Game
{
public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();

	void add(GameObject* obj);

	bool remove(GameObject* obj);
    
    // [Add other members as necessary.]
    
private:
    Gameboard   m_board;
    Screen		m_screen;
    int			m_level;
	
	static const int TARGET_FPS = 30;

	std::vector<GameObject*>* m_gameObjects;
	
	Map map; 
    // [Add other members as necessary.]
};

#endif // GAME_INCLUDED

