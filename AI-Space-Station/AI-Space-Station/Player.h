//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 13:26 8 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "SFML/Graphics.hpp"

#include <iostream>

//
class Player
{
public:
	Player();
	~Player();

	void update(sf::Time deltaTime, sf::View & v);
	void render(sf::RenderWindow& window);

	sf::Vector2f getPosition();

private:
	void addVelocity();
	void screenWarp();

	void init();
	void loadTextures();

	sf::Keyboard m_keyboard;

	sf::Texture m_texture;

	sf::Sprite m_sprite;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	float m_maxSpeed, m_speed, m_angle, m_maxVelocity, m_impuldseX, m_impulseY;

	bool m_moving;
};