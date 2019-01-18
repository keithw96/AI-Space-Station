//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 10:58 15 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Power-Up.h"

//
PowerUp::PowerUp()
{
	init();
}

//
PowerUp::~PowerUp()
{

}

//
void PowerUp::init()
{
	loadTextures();

	m_position = sf::Vector2f(1050, 3350);
	m_sprite.setOrigin(50, 50);

	m_texture = m_textureTypeOne;
	m_lifeTime = 700;
	m_respawnTime = 0;
	m_type = 1;
	m_active = true;
}

//
void PowerUp::loadTextures()
{
	//
	if (!m_textureTypeOne.loadFromFile("ASSETS/Textures/Invincibility.png"))
	{
		std::cout << "Error! Unable to load License.png from game files!" << std::endl;
	}

	//
	if (!m_textureTypeTwo.loadFromFile("ASSETS/Textures/Boost.png"))
	{
		std::cout << "Error! Unable to load License.png from game files!" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void PowerUp::update(sf::Time deltaTime)
{
	respawn();

	if (m_active == true)
	{
		m_lifeTime--;
	}

	if (m_lifeTime <= 0)
	{
		m_active = false;
	}

	//std::cout << m_lifeTime << std::endl;
}

/// <summary>
/// 
/// </summary>
void PowerUp::respawn()
{
	if (m_active == false)
	{
		m_respawnTime++;
		//std::cout << m_respawnTime << std::endl;
	}

	if (m_respawnTime >= 40 && m_active == false)
	{

		/*m_position.x = rand() % 700 + 10;
		m_position.y = rand() % 700 + 10;*/
		m_type = rand() % 20 + 1;
		

		if (m_type >= 1 && m_type <= 10)
		{
			m_texture = m_textureTypeOne;
		}

		if (m_type >= 11 && m_type <= 20)
		{
			m_texture = m_textureTypeTwo;
		}

		m_lifeTime = 700;
		m_respawnTime = 0;
		m_active = true;
	}

	m_sprite.setPosition(m_position);
	m_sprite.setTexture(m_texture);
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void PowerUp::render(sf::RenderWindow& window, sf::Vector2f scale)
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
int PowerUp::getType()
{
	return m_type;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Sprite PowerUp::getSprite()
{
	return m_sprite;
}

/// <summary>
/// 
/// </summary>
/// <param name="active"></param>
void PowerUp::setActive(bool active)
{
	m_active = active;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool PowerUp::getActive()
{
	return m_active;
}

/// <summary>
/// 
/// </summary>
/// <param name="position"></param>
void PowerUp::setPosition(sf::Vector2f position)
{
	m_position = position;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Vector2f PowerUp::getPosition()
{
	return m_position;
}