#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include "Projectile.h"

class AlienNest
{
public:
	AlienNest(sf::Vector2f pos, sf::Sprite sprite, sf::Sprite projectileSprite);

	void render(sf::RenderWindow *window, sf::Vector2f scale);
	void update(sf::Time deltaTime, sf::Vector2f playerPos);
private:
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Sprite m_projectileSprite;
	std::vector<Projectile> m_projectiles;
};