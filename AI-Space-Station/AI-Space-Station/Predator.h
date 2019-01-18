#pragma once
#include <SFML/Graphics.hpp>
class Predator
{
public:
	Predator(sf::Vector2f pos, sf::Sprite sprite);

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow *window, sf::Vector2f scale);

private:
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
};

