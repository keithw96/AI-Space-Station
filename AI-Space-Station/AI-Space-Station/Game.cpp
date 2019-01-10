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
	is_running{ true },
	gameState{GameState::GAME}
{
	m_view.setCenter(m_window.getSize().x / 2, m_window.getSize().y / 2);
	m_view.setSize(2500, 2000);


	m_player = new Player();
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

	// Updates game based on current state
	switch (gameState)
	{
	case GameState::SPLASH:

		break;
	case GameState::LICENSE:

		break;
	case GameState::MENU:

		break;
	case GameState::GAME:
		//
		m_player->update(deltaTime, m_view);

		break;
	case GameState::CONTROLS:

		break;
	case GameState::GAMEOVER:

		break;
	}

	m_window.setView(m_view);
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

	

	// Updates rendering based on current state
	switch (gameState)
	{
	case GameState::SPLASH:

		break;
	case GameState::LICENSE:

		break;
	case GameState::MENU:

		break;
	case GameState::GAME:
		//
		m_player->render(m_window);
		break;
	case GameState::CONTROLS:

		break;
	case GameState::GAMEOVER:

		break;
	}

	//
	m_window.display();
}