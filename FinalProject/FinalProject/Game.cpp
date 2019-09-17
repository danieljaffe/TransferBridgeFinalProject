
#include "Game.h"
#include "Gameboard.h"
#include "UserInterface.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 50;

const int BOARD_X = 0;                      
const int BOARD_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

Game::Game(int width, int height)
: m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1)
{
	m_gameObjects = new std::vector<GameObject*>();
}

// THIS CODE BELOW IS AN EXAMPLE OF HOW YOU CAN LAYOUT YOUR GAME
// YOU MAY CHANGE THIS HOWEVER YOU MAY LIKE



void Game::play()
{
	clock_t start; // init clock 
	double duration; 
	start = std::clock();
    //m_board.display(m_screen, BOARD_X, BOARD_Y);
    //displayStatus();
    //displayPrompt("Press the Enter key to begin ENTER GAME NAME ");
	//displayPrompt("P");
    //waitForEnter();  // [in UserInterface.h] 



    for(;;)
    {
        if ( ! playOneLevel())
            break;
        //displayPrompt("Good job!  Press the Enter key to start next level!");
        m_level++;
		
    }
    //displayPrompt("Game Over!  Press the Enter key to exit!");
	//std::cout << "heckin " << std::endl;
	map.draw(nullptr);
	waitForEnter();
	while (!0) 
	{
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		
		if (duration >= 1.0 / TARGET_FPS) 
		{
			//m_screen.clear();
			system("CLS");
			map.scroll();
			map.draw(nullptr);
			start = clock();
			
			char input;

			getCharIfAny(input);

			if (input == 13) return;
		}
			
	}
	
    waitForEnter();
}

void Game::displayPrompt(std::string s)
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}

void Game::displayStatus()
{
    // [Replace this with code to display the status.]
}

void Game::add(GameObject* obj)
{
	m_gameObjects->push_back(obj);
}

bool Game::remove(GameObject* obj)
{
	for (int i = 0; i < m_gameObjects->size(); i++)
	{
		if (m_gameObjects->at(i) == obj)
		{
			m_gameObjects->erase(m_gameObjects->begin() + i);
		}
	}
	return false;
}



bool Game::playOneLevel()
{
    
    return false;  // [Replace this with the code to play a level.]
}

