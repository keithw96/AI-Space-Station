// Modified by Brandon Seah-Dempsey
// At 14:37 18 January 2019

#include "Projectile.h"

/// <summary>
/// 
/// </summary>
/// <param name="pos"></param>
/// <param name="sprite"></param>
/// <param name="homing"></param>
Projectile::Projectile(sf::Vector2f pos, sf::Sprite sprite, bool homing)
{
	m_position = pos;
	m_sprite = sprite;
	m_velocity = 5.0f;
	m_homing = homing;
	count = 0;
	m_alive = true;
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2));
}


/// <summary>
/// 
/// </summary>
Projectile::~Projectile()
{

}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
/// <param name="playerPos"></param>
void Projectile::update(sf::Time deltaTime, sf::Vector2f playerPos)
{
	if (m_homing && m_alive)
	{
		count++;
		homing(playerPos);
	}

	if (count >= 300)
	{
		m_alive = false;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
/// <param name="scale"></param>
void Projectile::render(sf::RenderWindow *window, sf::Vector2f scale)
{
	if (m_alive)
	{
		window->draw(m_sprite);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="playerPos"></param>
void Projectile::homing(sf::Vector2f playerPos)
{
	if (m_position.x < playerPos.x)
	{
		m_position.x += m_velocity;
	}

	if (m_position.x > playerPos.x)
	{
		m_position.x -= m_velocity;
	}

	if (m_position.y < playerPos.y)
	{
		m_position.y += m_velocity;
	}

	if (m_position.y > playerPos.y)
	{
		m_position.y -= m_velocity;
	}

	m_sprite.setPosition(m_position);
}

/// <summary>
/// 
/// </summary>
/// <param name="velocity"></param>
void Projectile::move(sf::Vector2f velocity)
{

	m_position.x += velocity.x;
	m_position.y += velocity.y;

	m_sprite.setPosition(m_position);
}


/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool Projectile::getAlive()
{
	return m_alive;
}

/// <summary>
/// 
/// </summary>
/// <param name="alive"></param>
void Projectile::setAlive(bool alive)
{
	m_alive = alive;
}