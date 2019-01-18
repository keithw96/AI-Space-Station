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

	m_position.x = 950;
	m_position.y = 1200;

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

	m_invincible = false;
	m_boosted = false;
	m_mapCreated = false;
	m_up = false;
	m_right = false; 
	m_down = false; 
	m_left = false;
}

/// <summary>
/// 
/// </summary>
void Player::loadTextures()
{
	//
	if (!m_texture.loadFromFile("ASSETS/Textures/PlayerShip.png"))
	{
		std::cout << "Error! Unable to load PlayerShip.png from game files!" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void Player::update(sf::Time deltaTime, sf::View & v, PowerUp * powerup, std::vector<Tile> &tilemap)
{
	//
	m_position = m_sprite.getPosition();
	//
	createBoundaryTileVector(tilemap);
	//
	powerupColourAnimate();
	//
	powerupTime();
	
	//
	if (m_invincible == false && m_boosted == false)
	{
		m_animatedColour = 0;
		m_iColour = 1;
		m_bColour = 1;
	}

	//
	addVelocity();
	//
	powerupCollision(powerup);
	tileCollision(m_boundaryTiles);

	m_sprite.setPosition(m_position);
	v.setCenter(m_sprite.getPosition());
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
		//
		if (m_boosted == true)
		{
			speed = m_maxSpeed + m_boostSpeed;
		}
		//
		else if (m_boosted == false)
		{
			speed = m_maxSpeed;
		}
		//
		m_up = true;
		m_down = false;
		m_left = false;
		m_right = false;
		//
		m_angle = 0;
		m_position.y -= speed;
		/*m_position.x += (sin(m_sprite.getRotation() * (3.14159265 / 180)) * speed);
		m_position.y += (-cos(m_sprite.getRotation() * (3.14159265 / 180)) * speed);
		

		m_moving = true;

		//std::cout << "Up" << std::endl;*/
	}

	//
	else if (sf::Keyboard::isKeyPressed(m_keyboard.Down))
	{
		//
		if (m_boosted == true)
		{
			speed = m_maxSpeed + m_boostSpeed;
		}
		//
		else if (m_boosted == false)
		{
			speed = m_maxSpeed;
		}

		//
		m_up = false;
		m_down = true;
		m_left = false;
		m_right = false;
		//
		m_angle = 180;
		m_position.y += speed;
		/*m_position.x += (sin(m_sprite.getRotation() * (3.14159265 / 180)) * speed);
		m_position.y += (-cos(m_sprite.getRotation() * (3.14159265 / 180)) * speed);


		m_moving = true;

		//std::cout << "Up" << std::endl;*/
	}

	//
	else if (sf::Keyboard::isKeyPressed(m_keyboard.Left))
	{
		//
		if (m_boosted == true)
		{
			speed = m_maxSpeed + m_boostSpeed;
		}
		//
		else if (m_boosted == false)
		{
			speed = m_maxSpeed;
		}

		//
		m_up = false;
		m_down = false;
		m_left = true;
		m_right = false;
		//
		m_angle = 270;
		m_position.x -= speed;
		
		/*m_angle -= 5;
		std::cout << "Left" << std::endl;*/
	}

	//
	else if (sf::Keyboard::isKeyPressed(m_keyboard.Right))
	{
		//
		if (m_boosted == true)
		{
			speed = m_maxSpeed + m_boostSpeed;
		}
		//
		else if (m_boosted == false)
		{
			speed = m_maxSpeed;
		}

		//
		m_up = false;
		m_down = false;
		m_left = false;
		m_right = true;
		//
		m_angle = 90;
		m_position.x += speed;
		/*m_angle += 5;
		std::cout << "Right" << std::endl;*/
	}

	/*
	//
	if (m_angle > 360)
	{
		m_angle = 0;
	}
	//
	else if (m_angle < -360)
	{
		m_angle = 0;
	}*/
	



	/*
	std::cout << m_angle << std::endl;
	std::cout << m_sprite.getRotation() << std::endl;
	*/

	m_sprite.setRotation(m_angle);
	
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

//
void Player::tileCollision(std::vector<Tile> &tilemap)
{
	/*
	r1x + r1w >= r2x      r1 right edge past r2 left
	r1x <= r2x + r2w      r1 left edge past r2 right
	r1y + r1h >= r2y      r1 top edge past r2 bottom
	r1y <= r2y + r2h      r1 bottom edge past r2 top
	*/


	for (int i = 0; i < tilemap.size(); i++)
	{
		if (tilemap[i].getType() == 1)
		{
			//
			if (m_sprite.getPosition().x + m_sprite.getGlobalBounds().width >= tilemap[i].getSprite().getPosition().x &&
				m_sprite.getPosition().x <= tilemap[i].getSprite().getPosition().x + tilemap[i].getSprite().getGlobalBounds().width &&
				m_sprite.getPosition().y + m_sprite.getGlobalBounds().height >= tilemap[i].getSprite().getPosition().y && 
				m_sprite.getPosition().y <=tilemap[i].getSprite().getPosition().y + tilemap[i].getSprite().getGlobalBounds().height)
			{
				std::cout << "Collided" << std::endl;

				//
				if (m_up == true)
				{
					m_position.y += 50;
				}
				//
				else if (m_down == true)
				{
					m_position.y -= 50;
				}
				//
				else if (m_left == true)
				{
					m_position.x += 55;
				}
				//
				else if (m_right == true)
				{
					m_position.x -= 55;
				}
			}//End if
		}//End if
	}//End for
	
}

/// <summary>
/// 
/// </summary>
/// <param name="tilemap"></param>
void Player::createBoundaryTileVector(std::vector<Tile> &tilemap)
{
	//
	if (m_mapCreated == false)
	{
		//
		for (int i = 0; i < tilemap.size(); i++)
		{
			//
			if (tilemap[i].getType() == 1)
			{
				m_boundaryTiles.push_back(tilemap[i]);
			}

		}
	}

	//
	m_mapCreated = true;
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


