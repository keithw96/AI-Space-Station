#pragma once
#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile(sf::Vector2f position, sf::Sprite sprite, int t);
	Tile() {};
	
	void draw(sf::RenderWindow *window);

	sf::Sprite m_sprite;
	sf::RectangleShape rec; 
	int m_type;

	sf::Vector2f m_position;
	std::vector<Tile*> adjacents;
};