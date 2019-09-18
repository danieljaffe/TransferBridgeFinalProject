#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Gameboard.h"
#include "GameObject.h"
#include "UserInterface.h"
//#include <random>
#include "Map.h" 
#include <string>
#include <vector>
// [Add other #include directives as necessary.]

class Map;
class Actor;

class Game
{
public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();
	Actor* getPlayer();
	void setPlayer(Actor*);
	int randInt(int min, int max);
	bool trueWithProbabitiliy(double p);
	void add(GameObject* obj);

	std::vector<GameObject*> getGameObjects();

	bool remove(GameObject* obj);
	Map* getMap();
	int getScore();
	void setScore(int points);
    
    // [Add other members as necessary.]
    
private:
    Gameboard   m_board;
    Screen		m_screen;
    int			m_level;
	Actor* m_player;
	int m_score;
	
	static const int TARGET_FPS = 30;

	std::vector<GameObject*>* m_gameObjects;
	
	Map map; 
    // [Add other members as necessary.]
};

#endif // GAME_INCLUDED

