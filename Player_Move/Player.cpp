// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	loadImage(); // load the image file for the sprite

	m_image_width = 124; // the width of the image in pixels
	m_scaled = false; // the image is not scaled

	sf::Vector2f pos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); // place the player object in the centre of the screen
	m_sprite.setPosition(pos);  // set the position of the players sprite

	m_speed = 5; // the average speed
	m_direction = (rand() % 2) + 1;        // Generates a random number between 1 and 2
	m_lives = 3;
}


void Player::loadImage()
// Loads the image for the player object
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/SquareGuy.bmp"))
	{
		std::cout << "error with player image file";
	}

	m_sprite.setTexture(m_texture, true);
}



sf::Sprite Player::getBody() // get the player's body
{
	return m_sprite;
}


void Player::setPosition()  // set the position of the player on the screen
{
	sf::Vector2f pos(200, 40);
	m_sprite.setPosition(pos);
}


void Player::setPosition(int t_xPos, int t_yPos)  // set the position of the player on the screen
{
	sf::Vector2f pos(t_xPos, t_yPos);
	m_sprite.setPosition(pos);
}


