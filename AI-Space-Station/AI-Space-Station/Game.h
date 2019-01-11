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

class Player;

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

	Player * m_player;
};

#include "Player.h"

#endif // !GAME_H
