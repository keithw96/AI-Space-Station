//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 10:16 7 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Game.h"

/// <summary>
/// 
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{2500, 2000, 32}, "AI Space Station"},
	is_running{ true }
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_tileMap.push_back(Tile(sf::Vector2f(i, j), map[i][j]));
		}
	}
}

/// <summary>
/// 
/// </summary>
Game::~Game()
{

}

//
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			//timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timeSinceLastUpdate);
			timeSinceLastUpdate = sf::Time::Zero;

		}

		render();
	}
}

void Game::update(sf::Time deltaTime)
{

	//
	if (!is_running)
	{
		m_window.close();
	}
}

//
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				is_running = false;
			}
		}
	}
}

//
void Game::render()
{
	//
	m_window.clear(sf::Color(0, 0, 0));

	for (int i = 0; i < m_tileMap.size(); i++)
	{
		m_tileMap[i].draw(&m_window);
	}


	//
	m_window.display();
}