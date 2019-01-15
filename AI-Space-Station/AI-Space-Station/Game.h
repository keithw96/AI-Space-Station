//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 10:10 7 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "SFML/Graphics.hpp"

//
class Splash;
class License;
class Player;
class PowerUp;

enum class GameState
{
	SPLASH, LICENSE, MENU, GAME, CONTROLS, GAMEOVER
};

//
class Game
{
public:
	Game();
	~Game();
	void setGameState(GameState gameMode);
	GameState getGameState();
	void run();

protected:
	GameState gameState;

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow m_window;

	sf::View m_view;

	bool is_running;

	//
	Splash * m_splash;
	License * m_license;
	Player * m_player;
	PowerUp * m_powerup;
};

#include "SplashScreen.h"
#include "LicenseScreen.h"
#include "Player.h"
#include "Power-Up.h"

#endif // !GAME_H
