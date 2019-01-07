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

#include <iostream>

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

};

#endif // !GAME_H
