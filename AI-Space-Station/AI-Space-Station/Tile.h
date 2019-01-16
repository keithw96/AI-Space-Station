#pragma once
#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile(sf::Vector2f position, sf::Sprite sprite);
	
	void draw(sf::RenderWindow *window);

	sf::Sprite m_sprite;
	sf::RectangleShape rec; 


	sf::Vector2f m_position;
};