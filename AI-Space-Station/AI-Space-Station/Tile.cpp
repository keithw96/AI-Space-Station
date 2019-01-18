#include "Tile.h"

/// /// <summary>
/// 
/// </summary>
/// <param name="position"></param>
/// <param name="sprite"></param>
/// <param name="type"></param>
Tile::Tile(sf::Vector2f position, sf::Sprite sprite, int type)
{
	m_sprite = sprite;
	m_position = position;
	m_type = type;

	m_sprite.setScale(sf::Vector2f(2, 2));

	m_sprite.setPosition(m_position.x * m_sprite.getTextureRect().width * m_sprite.getScale().x, m_position.y * m_sprite.getTextureRect().height * m_sprite.getScale().y);
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void Tile::draw(sf::RenderWindow *window) 
{
	window->draw(m_sprite);
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Sprite Tile::getSprite()
{
	return m_sprite;
}

//
int Tile::getType()
{
	return m_type;
}