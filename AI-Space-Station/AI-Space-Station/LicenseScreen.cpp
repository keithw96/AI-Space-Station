//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 10:59 11 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "LicenseScreen.h"

/// <summary>
/// 
/// </summary>
License::License()
{
	init();
}

/// <summary>
/// 
/// </summary>
License::~License()
{

}

/// <summary>
/// 
/// </summary>
void License::init()
{
	//
	loadTextures();
	//
	m_position = sf::Vector2f(700, 800);
	//
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(50, 50);
	//
	m_screenTime = 0;
}

/// <summary>
/// 
/// </summary>
void License::loadTextures()
{
	//
	if (!m_texture.loadFromFile("ASSETS/Textures/License.png"))
	{
		std::cout << "Error! Unable to load License.png from game files!" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void License::update(sf::Time deltaTime)
{
	m_screenTime++;
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void License::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}


/// <summary>
/// 
/// </summary>
/// <returns></returns>
int License::getScreenTime()
{
	return m_screenTime;
}