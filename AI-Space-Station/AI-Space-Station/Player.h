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

#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "Power-Up.h"
#include "Projectile.h"
#include <iostream>

//
class Player
{
public:
	Player();
	~Player();

	void update(sf::Time deltaTime, sf::View & v, PowerUp * powerup);
	void render(sf::RenderWindow& window, sf::Vector2f scale);

	sf::Vector2f getPosition();

private:
	void addVelocity();
	void powerupColourAnimate();
	void powerupTime();

	void workerCollision();
	void projectileCollision();
	void enemyCollision();
	void powerupCollision(PowerUp * powerup);

	void init();
	void loadTextures();

	sf::Keyboard m_keyboard;

	sf::Texture m_texture;
	sf::Texture m_projectileTxt;
	sf::Sprite m_sprite;
	sf::Sprite m_projectileSprite;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	std::vector<Projectile*> m_projectiles;

	float m_maxSpeed, m_boostSpeed, m_angle, m_maxVelocity, m_impulseX, m_impulseY, m_friction;

	int m_health, m_animatedColour, m_iColour, m_bColour, m_powerupTime;

	bool m_moving, m_invincible, m_boosted;
};

#endif // !PLAYER_H