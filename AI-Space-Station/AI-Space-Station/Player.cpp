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

	m_position.x = 2750;
	m_position.y = 5175;

	m_velocity.x = 0;
	m_velocity.y = 0;

	m_maxSpeed = 15;
	m_boostSpeed = 10;
	m_angle = 0;
	m_maxVelocity = 5;
	m_friction = 0.01;

	m_health = 100;
	m_animatedColour = 0;

	m_iColour = 1;
	m_bColour = 1;

	m_powerupTime = 0;

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setRotation(0);

	m_moving = false;
	m_invincible = false;
	m_boosted = false;
}

/// <summary>
/// 
/// </summary>
void Player::loadTextures()
{
	if (!m_texture.loadFromFile("ASSETS/Textures/PlayerShip.png"))
	{
		std::cout << "Error! Unable to load PlayerShip.png from game files!" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void Player::update(sf::Time deltaTime, sf::View & v, PowerUp * powerup)
{
	powerupColourAnimate();
	powerupTime();
	
	if (m_invincible == false && m_boosted == false)
	{
		m_animatedColour = 0;
		m_iColour = 1;
		m_bColour = 1;
	}

	m_position = m_sprite.getPosition();
	
	addVelocity();
	powerupCollision(powerup);

	v.setCenter(m_sprite.getPosition());

	//std::cout << std::to_string(m_position.x) + ", " + std::to_string(m_position.y) << std::endl;
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void Player::render(sf::RenderWindow& window, sf::Vector2f scale)
{
	m_sprite.setScale(scale);
	window.draw(m_sprite);
}

/// <summary>
/// 
/// </summary>
void Player::addVelocity()
{
	float speed = 0.0f;
	//
	if (sf::Keyboard::isKeyPressed(m_keyboard.Up))
	{
		if (m_boosted == true)
		{
			speed = m_maxSpeed + m_boostSpeed;
		}
		//
		else if (m_boosted == false)
		{
			speed = m_maxSpeed;
		}
	
		m_position.x += (sin(m_sprite.getRotation() * (3.14159265 / 180)) * speed);
		m_position.y += (-cos(m_sprite.getRotation() * (3.14159265 / 180)) * speed);
		
		m_moving = true;
	}

	//
	if (sf::Keyboard::isKeyPressed(m_keyboard.Left))
	{
		m_angle -= 5;
	}

	//
	else if (sf::Keyboard::isKeyPressed(m_keyboard.Right))
	{
		m_angle += 5;
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

	m_sprite.setRotation(m_angle);
	m_sprite.setPosition(m_position);
}

//
void Player::workerCollision()
{

}

//
void Player::projectileCollision()
{
	if (m_invincible == false)
	{

	}
}

//
void Player::enemyCollision()
{
	if (m_invincible == false)
	{

	}
}

/// <summary>
/// 
/// </summary>
/// <param name="powerup"></param>
void Player::powerupCollision(PowerUp * powerup)
{
	//
	if (powerup->getActive() == true)
	{
		if (m_sprite.getGlobalBounds().intersects(powerup->getSprite().getGlobalBounds()))
		{
			powerup->setActive(false);

			//
			if (powerup->getType() >= 1 && powerup->getType() <= 10)
			{
				m_invincible = true;
				m_boosted = false;
				m_iColour = 1; 
				m_bColour = 1;
				m_powerupTime = 250;
			}
			//
			else if (powerup->getType() >= 11 && powerup->getType() <= 20)
			{
				m_invincible = false;
				m_boosted = true;
				m_iColour = 1;
				m_bColour = 1;
				m_powerupTime = 400;
			}
		}
	}
}

/// <summary>
/// 
/// </summary>
void Player::powerupColourAnimate()
{
	//
	if (m_invincible == true)
	{
		m_animatedColour++;

		if (m_animatedColour > 20)
		{
			m_iColour *= -1;
			m_animatedColour = 0;
		}
	}

	//
	else if (m_boosted == true)
	{
		m_animatedColour++;

		if (m_animatedColour > 20)
		{
			m_bColour *= -1;
			m_animatedColour = 0;
		}
	}

	//
	if (m_iColour == -1)
	{
		m_sprite.setColor(sf::Color::Blue);
	}
	//
	else if (m_bColour == -1)
	{
		m_sprite.setColor(sf::Color::Red);
	}
	//
	else
	{
		m_sprite.setColor(sf::Color::White);
	}
}

/// <summary>
/// 
/// </summary>
void Player::powerupTime()
{
	if (m_invincible == true || m_boosted == true)
	{
		m_powerupTime--;
		std::cout << m_powerupTime << std::endl;

		if (m_powerupTime <= 0)
		{
			m_invincible = false;
			m_boosted = false;
			m_iColour = 1;
			m_bColour = 1;
			m_powerupTime = 0;
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Vector2f Player::getPosition()
{
	return m_sprite.getPosition();
}


