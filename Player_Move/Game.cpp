// Name: 
// Login: 
// Date: 
// Approx hours of work : 
//---------------------------------------------------------------------------
//	TEMPLATE
/*
1.	The player should have the following movement : It should move from left to right across the screen.When it reaches the boundary of the screen on the right hand side it should
	move from right to left.When it reaches the boundary on the left hand side it should move from left to right and so on.
2.	When the user presses the ‘f’ key on the keyboard, the player’s movement speed should increase by 1. The player’s speed should not increase more than 15.
3.	When the user presses the ‘s’ key on the keyboard, the player’s movement speed should decrease by 1. The minimum player’s speed is 1.
4.	When the user presses the ‘i’ key on the keyboard, the player’s size should increase.This can be done by scaling the image.This should be done ONLY once.
5.	When the user presses the ‘c’ key on the keyboard, the player’s colour should change.
6.	When the user presses the ‘d’ key on the keyboard, the player should move in the opposite direction.
*/
// ---------------------------------------------------------------------------
// Known Bugs:
// When a key is pressed on the keyboard, it picks up multiple clicks at once not just one click.

//////////////////////////////////////////////////////////// 
// include correct library files for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include <iostream> // for console window output
#include "Game.h"   // include Game header file



Game::Game() :
	m_window{ sf::VideoMode{ sf::Vector2u{1500U, 800U}, 32U }, "Player Template" },
	m_exitGame{ false } //when true game will exit
{
	setupTexts(); // load font 
	setupSprites(); // load texture
	setupPlayer();  // initialize the player
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{

	while (const std::optional newEvent = m_window.pollEvent())
	{
		if (newEvent->is<sf::Event::Closed>()) // close window message 
		{
			m_exitGame = true;
		}
		if (newEvent->is<sf::Event::KeyPressed>()) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(const std::optional<sf::Event> t_event)
{
	const sf::Event::KeyPressed* newKeypress = t_event->getIf<sf::Event::KeyPressed>();
	if (sf::Keyboard::Key::Escape == newKeypress->code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Check if any keys are currently pressed
/// </summary>
void Game::checkKeyboardState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		m_exitGame = true;
	}
	
	// checks what  keys have been pressed  

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	{
		// the player’s movement speed should increase by 1.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		// the player’s movement speed should decrease by 1.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I))
	{
		// the size of the player's image increases. This occurs only once.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
	{
		// changes the colour of the player's image when C is pressed
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		// changes the direction the player is moving when D is pressed
	}


}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	checkKeyboardState();
	
	m_welcomeMessage.setString("Press the 'f' key on the keyboard, the player's movement speed should increase by 1.\nPress the 's' key on the keyboard, the player's movement speed should decrease by 1.\nPress the 'i' key on the keyboard to increase the size of the player. This occurs only once. \nPress the 'c' key on the keyboard to change the colour of the player. \nPress the 'd' key on the keyboard to change the direction of the player.");

	if (m_exitGame)
	{
		m_window.close();
	}

	// calls the player object to move itself in the appropriate direction


}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_backgroundSprite); // draw the background image
	m_window.draw(m_welcomeMessage);   // draw the text

	m_window.draw(m_myPlayer.getBody()); // draw the player object


	m_window.display();
}


/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupTexts()
{
	if (!m_font.openFromFile("ASSETS\\FONTS\\Jersey20-Regular.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_font);
	m_welcomeMessage.setPosition(sf::Vector2f{ 20.0f, 10.0f });
	m_welcomeMessage.setCharacterSize(25U);
	m_welcomeMessage.setOutlineColor(sf::Color::Black);
	m_welcomeMessage.setFillColor(sf::Color::Red);
	m_welcomeMessage.setOutlineThickness(2.0f);

}


/// <summary>
/// load the texture and setup the sprite for the background image
/// </summary>
void Game::setupSprites()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\Asteroids Image.jpg"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}

	m_backgroundSprite.setTexture(m_backgroundTexture, true);// to reset the dimensions of texture
	m_backgroundSprite.setPosition(sf::Vector2f{ 0.0f, 0.0f });
}

/// <summary>
/// Set up the player object(s) as needed
/// </summary>
void Game::setupPlayer()
{

}