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
#include "Tile.h"
#include "Projectile.h"
#include "Worker.h"

#include <iostream>
#include <vector>
#include <string>

//
class Player
{
public:
	Player();
	~Player();

	void update(sf::Time deltaTime, sf::View & v, PowerUp * powerup, std::vector<Tile> &tilemap, int playerNumber);
	void render(sf::RenderWindow * window, sf::Vector2f scale);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

	void tileCollision(std::vector<Tile> &tilemap, int playerNumber);
	void workerCollision(Worker * worker, int playerNumber);

private:
	void addVelocity();
	void powerupColourAnimate();
	void powerupTime();
	void createBoundaryTileVector(std::vector<Tile> &tilemap);
	void shootBullet();

	void projectileCollision();
	void enemyCollision();
	void powerupCollision(PowerUp * powerup);

	void init();
	void loadAssets();

	sf::Keyboard m_keyboard;

	sf::Texture m_texture;
	sf::Texture m_projectileText;
	sf::Sprite m_sprite;
	sf::Sprite m_projectileSprite;

	sf::Vector2f m_position;

	sf::Font m_font;
	sf::Text m_scoreText;

	//Projectile * m_playerBullet;
	//sf::Vector2f m_projectileVel;
	std::vector<Projectile*> m_projectiles;

	float m_maxSpeed, m_boostSpeed, m_angle, m_maxVelocity;

	int m_health, m_animatedColour, m_iColour, m_bColour, m_powerupTime, m_score;

	bool m_invincible, m_boosted, m_mapCreated, m_up, m_right, m_down, m_left, m_display, m_shoot;

	std::string m_text;

	std::vector<Tile> m_boundaryTiles;
	std::vector<Worker> m_workers;
};

#endif // !PLAYER_H