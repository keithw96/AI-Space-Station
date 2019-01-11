//
//
//
//
// C00204076
// Brandon Sea-Dempsey
// Started at 9:26 11 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "SFML/Graphics.hpp"

#include <iostream>

class License
{
public:
	License();
	~License();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);

	int getScreenTime();

private:
	void init();
	void loadTextures();

	sf::Texture m_texture;

	sf::Sprite m_sprite;

	sf::Vector2f m_position;

	int m_screenTime;
};