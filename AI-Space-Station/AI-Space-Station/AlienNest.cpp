#include "AlienNest.h"

AlienNest::AlienNest(sf::Vector2f pos, sf::Sprite sprite, sf::Sprite projectileSprite)
{
	m_position = pos;
	m_projectileSprite = projectileSprite;
	m_sprite = sprite;
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2));
}

void AlienNest::update(sf::Time deltaTime, sf::Vector2f playerPos)
{
	if (m_position.x - playerPos.x < 600 && m_position.x - playerPos.x > -600 && m_position.y - playerPos.y < 500 && m_position.y - playerPos.y > -500 && m_projectiles.size() < 1)
	{
		m_projectiles.push_back(Projectile(m_position, m_projectileSprite, true));
	}

	for (int i = 0; i < m_projectiles.size(); i++)
	{
		m_projectiles[i].Update(deltaTime, playerPos);

		if (m_projectiles[i].m_alive == false)
		{
			m_projectiles[i].~Projectile();
		}
	}

}

void AlienNest::render(sf::RenderWindow *window, sf::Vector2f scale)
{
	m_sprite.setScale(scale);
	window->draw(m_sprite);
	for (auto& p : m_projectiles)
	{
		p.Render(window, scale);
	}
}