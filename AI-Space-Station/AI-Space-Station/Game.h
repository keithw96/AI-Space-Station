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

#include "SFML/Graphics.hpp"
#include "Tile.h"
#include <iostream>
#include <vector>
//
class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow m_window;

	bool is_running;

	std::vector<Tile> m_tileMap;

	int map[3][3] = {
	{ 1,2,3 } ,
	{ 1,2,3 } ,
	{ 1,2,3 }
	};
};

#endif // !GAME_H
