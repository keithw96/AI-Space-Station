#include "Tile.h"

Tile::Tile(sf::Vector2f position, sf::Sprite sprite, int t)
{
	m_sprite = sprite;
	m_position = position;
	m_type = t;
	m_sprite.setScale(sf::Vector2f(2, 2));

	m_sprite.setPosition(m_position.x * m_sprite.getTextureRect().width * m_sprite.getScale().x, m_position.y * m_sprite.getTextureRect().height * m_sprite.getScale().y);
}

void Tile::draw(sf::RenderWindow *window) 
{
	/*rec.setPosition(m_position.x * size, m_position.y * size);
	rec.setOutlineColor(sf::Color::White);
	rec.setOutlineThickness(3.0f);
	rec.setSize(sf::Vector2f(size, size));
	
	if (m_type == 1)
	{
		rec.setFillColor(sf::Color::Black);
	}

	window->draw(rec);*/
	if (m_type != 1)
	{
		int derp = 0;
	}
	window->draw(m_sprite);
}