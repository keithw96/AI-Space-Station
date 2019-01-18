#include "Predator.h"

Predator::Predator(sf::Vector2f pos, sf::Sprite sprite)
{
	m_position = pos;
	m_sprite = sprite;
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2));
}

void Predator::update(sf::Time deltaTime)
{

}

void Predator::render(sf::RenderWindow *window, sf::Vector2f scale)
{
	m_sprite.setScale(scale);
	window->draw(m_sprite);
}
