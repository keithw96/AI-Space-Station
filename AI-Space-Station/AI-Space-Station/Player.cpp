//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 13:35 8 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Player.h"

/// <summary>
/// 
/// </summary>
Player::Player()
{
	init();
}

/// <summary>
/// 
/// </summary>
Player::~Player()
{

}

/// <summary>
/// 
/// </summary>
void Player::init()
{
	loadTextures();

	m_position.x = 200;
	m_position.y = 200;

	m_velocity.x = 0;
	m_velocity.y = 0;

	m_maxSpeed = 15;
	m_angle = 0;
	m_maxVelocity = 5;

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(50, 50);
	m_sprite.setRotation(0);

	m_moving = false;
}

/// <summary>
/// 
/// </summary>
void Player::loadTextures()
{
	//
	if (!m_texture.loadFromFile("ASSETS/Textures/PlayerShip.png"))
	{
		std::cout << "Error! Unable to load .png from game files!" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void Player::update(sf::Time deltaTime, sf::View & v)
{
	m_position = m_sprite.getPosition();
	

	addVelocity();
	screenWarp();


	/*std::cout << m_position.x << std::endl;
	std::cout << m_position.y << std::endl;*/

	v.setCenter(m_sprite.getPosition());
}

/// <summary>
/// 
/// </summary>
void Player::addVelocity()
{
	//
	if (sf::Keyboard::isKeyPressed(m_keyboard.Up))
	{

		m_position.x += (sin(m_sprite.getRotation() * (3.14159265 / 180)) * m_maxSpeed);
		m_position.y += (-cos(m_sprite.getRotation() * (3.14159265 / 180)) * m_maxSpeed);

		m_moving = true;

		std::cout << "Up" << std::endl;

	}
	//
	else
	{

	}

	//
	if (sf::Keyboard::isKeyPressed(m_keyboard.Left))
	{
		m_angle -= 3;

		//std::cout << "Left" << std::endl;
	}

	//
	else if (sf::Keyboard::isKeyPressed(m_keyboard.Right))
	{
		m_angle += 3;

		//std::cout << "Right" << std::endl;
	}

	//
	if (m_angle > 360)
	{
		m_angle = 0;
	}
	//
	else if (m_angle < -360)
	{
		m_angle = 0;
	}


	if (m_moving == true)
	{

	}
	



	/*
	std::cout << m_angle << std::endl;
	std::cout << m_sprite.getRotation() << std::endl;
	*/

	m_sprite.setRotation(m_angle);
	m_sprite.setPosition(m_position);
}

/// <summary>
/// 
/// </summary>
void Player::screenWarp()
{
	if (m_position.x <= -150)
	{
		m_sprite.setPosition(2500, m_position.y);
	}
	else if (m_position.x >= 2600)
	{
		m_sprite.setPosition(-50, m_position.y);
	}

	if (m_position.y <= -150)
	{
		m_sprite.setPosition(m_position.x, 2050);
	}
	else if (m_position.y >= 2100)
	{
		m_sprite.setPosition(m_position.x, -100);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Vector2f Player::getPosition()
{
	return m_sprite.getPosition();
}