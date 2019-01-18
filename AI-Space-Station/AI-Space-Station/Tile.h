#pragma once
#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile(sf::Vector2f position, sf::Sprite sprite, int type);
	
	void draw(sf::RenderWindow *window);

	sf::Sprite getSprite();
	int getType();

private:
	sf::Sprite m_sprite;

	sf::Vector2f m_position;

	int m_type;
};