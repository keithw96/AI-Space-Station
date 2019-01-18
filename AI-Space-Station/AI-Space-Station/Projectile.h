// Modified by Brandon Seah-Dempsey
// At 14:37 18 January 2019

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <iostream>

//
class Projectile
{
public:
	Projectile(sf::Vector2f position, sf::Sprite sprite, bool homing);
	~Projectile();

	void update(sf::Time deltaTime, sf::Vector2f playerPos);
	void render(sf::RenderWindow *window, sf::Vector2f scale);

	void homing(sf::Vector2f playerPos);
	void move(sf::Vector2f velocity);

	bool getAlive();
	void setAlive(bool alive);

private:
	sf::Vector2f m_position;

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_rotation, m_velocity;
	int count;
	bool m_homing, m_alive;
	
};

#endif // !PROJECTILE_H