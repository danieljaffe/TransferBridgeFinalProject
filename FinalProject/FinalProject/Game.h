#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Gameboard.h"
#include "UserInterface.h"
#include "Map.h" 
#include <string>
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
    void t1();
    void t2();
    void t3();
    void t4();
    void t5();
    
    // [Add other members as necessary.]
    
private:
    Gameboard    m_board;
    Screen  m_screen;
    int     m_level;
	static const int TARGET_FPS = 30; 
	Map map; 
    // [Add other members as necessary.]
};

#endif // GAME_INCLUDED

