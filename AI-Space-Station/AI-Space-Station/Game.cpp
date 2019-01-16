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
	m_view.zoom(1.5f);

	m_view.zoom(0.35f);

	miniMap.reset(sf::FloatRect(0, 0, m_window.getSize().x / 2, m_window.getSize().y / 2));
	miniMap.setViewport(sf::FloatRect(1.1f - (1.f*miniMap.getSize().x) / m_window.getSize().x - 0.04f, 0.3f - (1.f*miniMap.getSize().y) / m_window.getSize().y - 0.02f, (1.f*miniMap.getSize().x) / m_window.getSize().x, (1.f*miniMap.getSize().y) / m_window.getSize().y));
	miniMap.zoom(11.0f);

	loadSprites();

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			determineTile(map[i][j], j, i);
		}
	}

	m_splash = new Splash();
	m_license = new License();
	m_player = new Player();
	m_powerup = new PowerUp();
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
		m_splash->update(deltaTime);
		//
		if (m_splash->getScreenTime() > 270)
		{
			setGameState(GameState::LICENSE);
		}
		break;
	case GameState::LICENSE:
		//
		m_license->update(deltaTime);
		//
		if (m_license->getScreenTime() > 270)
		{
			setGameState(GameState::GAME);
		}
		break;
	case GameState::MENU:

		break;
	case GameState::GAME:
		//

		m_player->update(deltaTime, m_view, m_powerup);
		m_powerup->update(deltaTime);

		break;
	case GameState::CONTROLS:

		break;
	case GameState::GAMEOVER:

		break;
	}

	m_window.display();
	//m_window.setView(m_view);
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
		m_splash->render(m_window);
		break;
	case GameState::LICENSE:
		m_license->render(m_window);
		break;
	case GameState::MENU:

		break;
	case GameState::GAME:
		//
//game render
		m_window.setView(m_view);

		for (int i = 0; i < m_tileMap.size(); i++)
		{
			m_tileMap[i].draw(&m_window);
		}

		m_player->render(m_window, sf::Vector2f(1.0f, 1.0f));
		//
		m_powerup->render(m_window);

		m_window.setView(miniMap);
//minimap render
		for (int i = 0; i < m_tileMap.size(); i++)
		{
			m_tileMap[i].draw(&m_window);
		}

		m_player->render(m_window, sf::Vector2f(10.0f, 10.0f));
		//
		m_powerup->render(m_window);
		break;
	case GameState::CONTROLS:

		break;
	case GameState::GAMEOVER:

		break;
	}

	//
	m_window.display();
}

/// <summary>
/// 
/// </summary>
/// <param name="gameMode"></param>
void Game::setGameState(GameState gameMode)
{
	gameState = gameMode;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
GameState Game::getGameState()
{
	return gameState;
}

void Game::loadSprites()
{
	m_bottomLeftTileTexture.loadFromFile("ASSETS/Textures/bottom_left_corner.png");
	m_bottomRightTileTexture.loadFromFile("ASSETS/Textures/bottom_right_corner.png");
	m_topLeftTileTexture.loadFromFile("ASSETS/Textures/top_left_corner.PNG");
	m_topRightTileTexture.loadFromFile("ASSETS/Textures/top_right_corner.PNG");
	m_horizontalTileTexture.loadFromFile("ASSETS/Textures/horizontal_tile.PNG");
	m_verticalTileTexture.loadFromFile("ASSETS/Textures/vertical_tile.PNG");
	m_tJunctionLeftTexture.loadFromFile("ASSETS/Textures/T_junction_left.PNG");
	m_tJunctionRightTexture.loadFromFile("ASSETS/Textures/T_junction_right.PNG");
	m_tJunctionUpTexture.loadFromFile("ASSETS/Textures/T_junction_up.PNG");
	m_tJunctionDownTexture.loadFromFile("ASSETS/Textures/T_junction_down.PNG");
	m_black_tileTexture.loadFromFile("ASSETS/Textures/black_tile.png");
	m_tileTexture.loadFromFile("ASSETS/Textures/tile.png");

	m_black_tileSprite.setTexture(m_black_tileTexture);
	m_bottomLeftTileSprite.setTexture(m_bottomLeftTileTexture);
	m_bottomRightTileSprite.setTexture(m_bottomRightTileTexture);
	m_horizontalTileSprite.setTexture(m_horizontalTileTexture);
	m_tileSprite.setTexture(m_tileTexture);
	m_tJunctionLeftSprite.setTexture(m_tJunctionLeftTexture);
	m_tJunctionRightSprite.setTexture(m_tJunctionRightTexture);
	m_tJunctionUpSprite.setTexture(m_tJunctionUpTexture);
	m_tJunctionDownSprite.setTexture(m_tJunctionDownTexture);
	m_topLeftTileSprite.setTexture(m_topLeftTileTexture);
	m_topRightTileSprite.setTexture(m_topRightTileTexture);
	m_verticalTileSprite.setTexture(m_verticalTileTexture);
}

void Game::determineTile(int type, int x, int y)
{
	if (type == 1) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_black_tileSprite));
	}
	if (type == 2) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_verticalTileSprite));
	}
	if (type == 3) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_horizontalTileSprite));
	}
	if (type == 4) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_topLeftTileSprite));
	}
	if (type == 5) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_topRightTileSprite));
	}
	if (type == 6) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_bottomLeftTileSprite));
	}
	if (type == 7) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_bottomRightTileSprite));
	}
	if (type == 8) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_tileSprite));
	}
	if (type == 9) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_tJunctionLeftSprite));
	}
	if (type == 10) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_tJunctionRightSprite));
	}
	if (type == 11) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_tJunctionUpSprite));
	}
	if (type == 12) {
		m_tileMap.push_back(Tile(sf::Vector2f(x, y), m_tJunctionDownSprite));
	}
}