//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 13:26 18 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef WORKER_H
#define WORKER_H

#include "SFML/Graphics.hpp"

#include <iostream>

//
class Worker
{
public:
	Worker(sf::Vector2f position);
	~Worker();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window, sf::Vector2f scale);

	bool getActive();
	void setActive(bool active);

	sf::Sprite getSprite();

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

private:
	void wander();

	void init(sf::Vector2f position);
	void loadTextures();

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position, m_newPosition;

	float m_speed, m_rotation;

	bool m_active, m_moving;

};

#endif // !WORKER_H
