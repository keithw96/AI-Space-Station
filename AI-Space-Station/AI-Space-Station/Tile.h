#pragma once
#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile(sf::Vector2f position, int type);
	
	void draw(sf::RenderWindow *window);

	sf::Sprite m_sprite;
	sf::RectangleShape rec; 
	int x; int y; int size = 32; int m_type;

	sf::Vector2f m_position;
};