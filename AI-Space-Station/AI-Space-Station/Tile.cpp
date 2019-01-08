#include "Tile.h"

Tile::Tile(sf::Vector2f position, int type)
{
	//m_sprite.setPosition(position);
	//m_sprite.setTextureRect(rect);

	m_position = position;
	m_type = type;
}

void Tile::draw(sf::RenderWindow *window) 
{
	rec.setPosition(m_position.x * size, m_position.y * size);
	rec.setSize(sf::Vector2f(size, size));
	
	if (m_type == 1)
	{
		rec.setFillColor(sf::Color::Blue);
	}

	if (m_type == 2)
	{
		rec.setFillColor(sf::Color::Green);
	}

	if (m_type == 3)
	{
		rec.setFillColor(sf::Color::Red);
	}

	window->draw(rec);
}