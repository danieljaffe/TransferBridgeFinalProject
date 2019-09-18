
#include "Game.h"
#include "Gameboard.h"
#include "UserInterface.h"
#include "Actor.h"
#include "Kamikazi.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

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
	m_score = 0;
	m_gameObjects = new std::vector<GameObject*>();
	m_player = new Player(this);
	add(m_player);

	map.setGame(this); 
}

// THIS CODE BELOW IS AN EXAMPLE OF HOW YOU CAN LAYOUT YOUR GAME
// YOU MAY CHANGE THIS HOWEVER YOU MAY LIKE



void Game::play()
{
	clock_t start; // init clock 
	double duration; 
	std::srand(std::time(0));
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
	map.draw(m_gameObjects);
	cout << "Health: " << getPlayer()->getHealth() << "    Shields: " << getPlayer()->getArmor() << endl;
	cout << "Score: " << m_score;
	waitForEnter();
	while (!isGameOver()) 
	{
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		
		if (duration >= 1.0 / TARGET_FPS) 
		{

			std::vector<GameObject*>::iterator it = m_gameObjects->begin();
			bool checkAgain = true;

			while (checkAgain)
			{
				checkAgain = false;
				for (int i = 0; i < m_gameObjects->size(); i++)
				{
					if (m_gameObjects->at(i)->getDestroyFlag())
					{
						remove(m_gameObjects->at(i));
						checkAgain = true;
						break;
					}
				}

			}


			//m_screen.clear();
			system("CLS");
			map.scroll();
			map.draw(m_gameObjects);
			cout << "Health: " << getPlayer()->getHealth() << "    Shields: " << getPlayer()->getArmor() << endl;
			cout << "Score: " << m_score;
			start = clock();

			for (int i = 0; i < m_gameObjects->size(); i++)
			{
				m_gameObjects->at(i)->update();
			}

			//add(new Kamikazi(this, 1, 1, 1, 1, 15, 'k', 60, 15));
			

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

std::vector<GameObject*> Game::getGameObjects() {
	return *m_gameObjects;
}

bool Game::remove(GameObject* obj)
{
	for (int i = 0; i < m_gameObjects->size(); i++)
	{
		if (m_gameObjects->at(i)->getDestroyFlag())
		{
			m_gameObjects->erase(m_gameObjects->begin() + i);
			delete obj;
			return true;
		}
	}
	return false;
}

Map* Game::getMap()
{
	return &map;
}

int Game::getScore()
{
	return m_score;
}

void Game::setScore(int points)
{
	m_score += points;
}

bool Game::isGameOver()
{
	return m_gameOver;
}

void Game::setGameOver(bool gameOver)
{
	m_gameOver = gameOver;

	if (gameOver) {
		std::cout << std::endl << "-------------------------------- GAME OVERRRR  :( --------------------------" << std::endl;
		/*std::cout << std::endl << " _____ ____  _      _____   ____  _     _____ ____  ";
		std::cout << std::endl << "/  __//  _ \/ \__/|/  __/  /  _ \/ \ |\/  __//  __\ ";
		std::cout << std::endl << "| |  _| / \|| |\/|||  \    | / \|| | //|  \  |  \/| ";
		std::cout << std::endl << "| |_//| |-||| |  |||  /_   | \_/|| \// |  /_ |    / ";
		std::cout << std::endl << "\____\\_/ \|\_/  \|\____\  \____/\__/  \____\\_/\_\ " << endl;*/
	}
                                                   
}

int Game::randInt(int min, int max) {
	return min + std::rand() % (max - min);
}

bool Game::trueWithProbability(double p)
{
	return std::rand() < p * RAND_MAX + p;
}


bool Game::playOneLevel()
{
    
    return false;  // [Replace this with the code to play a level.]
}

void Game::setPlayer(Actor* player) { m_player = player; }

Actor* Game::getPlayer() { return m_player; }