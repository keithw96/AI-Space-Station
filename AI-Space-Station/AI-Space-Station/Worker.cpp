//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 13:26 18 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Worker.h"

/// <summary>
/// 
/// </summary>
Worker::Worker(sf::Vector2f position)
{
	init(position);
}

/// <summary>
/// 
/// </summary>
Worker::~Worker()
{
	
	
}

/// <summary>
/// 
/// </summary>
void Worker::init(sf::Vector2f position)
{
	loadTextures();

	m_position = position;

	m_speed = 12;
	m_rotation = 0;

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setRotation(0);

	m_moving = false;
	m_active = true;
}

/// <summary>
/// 
/// </summary>
void Worker::loadTextures()
{
	if (!m_texture.loadFromFile("ASSETS/Textures/WorkerGreen.png"))
	{
		std::cout << "Error! Unable to load WorkerGreen.png from game files!" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void Worker::update(sf::Time deltaTime)
{
	if (m_active == true)
	{
		m_position = m_sprite.getPosition();
	
		m_rotation++;

		if(m_rotation > 360)
		{
			m_rotation = 0;
		}

		
	}

	m_sprite.setRotation(m_rotation);
}


/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
/// <param name="scale"></param>
void Worker::render(sf::RenderWindow& window, sf::Vector2f scale)
{
	if (m_active == true)
	{
		m_sprite.setScale(scale);
		window.draw(m_sprite);
	}
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool Worker::getActive()
{
	return m_active;
}

/// <summary>
/// 
/// </summary>
/// <param name="active"></param>
void Worker::setActive(bool active)
{
	m_active = active;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Sprite Worker::getSprite()
{
	return m_sprite;
}


/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Vector2f Worker::getPosition()
{
	return m_position;
}

/// <summary>
/// 
/// </summary>
/// <param name="position"></param>
void Worker::setPosition(sf::Vector2f position)
{
	m_position = position;
}