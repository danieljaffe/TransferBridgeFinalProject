
#include "Game.h"
#include "Gameboard.h"
#include "UserInterface.h"
#include <iostream>
#include <string>

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
}

// THIS CODE BELOW IS AN EXAMPLE OF HOW YOU CAN LAYOUT YOUR GAME
// YOU MAY CHANGE THIS HOWEVER YOU MAY LIKE



void Game::play()
{
    m_board.display(m_screen, BOARD_X, BOARD_Y);
    displayStatus();
    displayPrompt("Press the Enter key to begin ENTER GAME NAME ");
    waitForEnter();  // [in UserInterface.h]

    for(;;)
    {
        if ( ! playOneLevel())
            break;
        displayPrompt("Good job!  Press the Enter key to start next level!");
        waitForEnter();
        m_level++;
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
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



bool Game::playOneLevel()
{
    
    return false;  // [Replace this with the code to play a level.]
}

