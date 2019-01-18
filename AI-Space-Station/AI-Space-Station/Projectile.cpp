#include "Projectile.h"



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

Projectile::~Projectile()
{

}

void Projectile::Update(sf::Time deltaTime, sf::Vector2f playerPos)
{
	std::cout << std::to_string(count) << std::endl;
	if (m_homing && m_alive)
	{
		count++;
		Homing(playerPos);
	}

	if (count >= 300)
	{
		m_alive = false;
	}
}

void Projectile::Render(sf::RenderWindow *window, sf::Vector2f scale)
{
	if (m_alive)
	{
		window->draw(m_sprite);
	}
}

void Projectile::Homing(sf::Vector2f playerPos)
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

	float PI = 3.14159265;

	float dx = m_position.x - playerPos.x;
	float dy = m_position.y - playerPos.y;

	m_rotation = ((atan2(dy, dx)) * 180 / PI) + 180;
	m_sprite.setRotation(m_rotation);
	m_sprite.setPosition(m_position);
}