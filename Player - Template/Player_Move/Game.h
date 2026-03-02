// Game class declaration

#ifndef GAME_HPP
#define GAME_HPP
#pragma warning( push )
#pragma warning( disable : 4275 )
// ignore this warning
// C:\SFML - 3.0.0\include\SFML\System\Exception.hpp(41, 47) : 
// warning C4275 : non dll - interface class 'std::runtime_error' used as base for dll - interface class 'sf::Exception'

/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the #endif at the bottom
/// </summary>
#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file

class Game
{
	// data members (instance variables)
	int m_gameScore = 0;   // the main game score
	int m_noOfPlayers = 1;  // the no of active players in the game
	
	Player m_myPlayer;  // creates an object of type Player using the default constructor

	
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_font;// font used by message
	sf::Text m_welcomeMessage{ m_font }; // text used for writing a message on screen
	sf::Texture m_backgroundTexture;//  texture used for background image
	sf::Sprite m_backgroundSprite{ m_backgroundTexture }; // sprite used for background image
	bool m_exitGame; // control exiting game

	void processEvents();
	void processKeys(const std::optional<sf::Event> t_event);
	void checkKeyboardState();
	void update(sf::Time t_deltaTime);
	void render();

	void setupTexts();
	void setupSprites();
	void setupPlayer();

	
public:
	Game();
	void run();

};

#pragma warning( pop ) 
#endif // !GAME_HPP





