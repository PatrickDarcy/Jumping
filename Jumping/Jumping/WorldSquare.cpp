#include "WorldSquare.h"

WorldSquare::WorldSquare()
{
	m_platform.setFillColor(sf::Color::Red);
	m_platform.setSize({ 50.0f, 50.0f });
	m_solidBlock = false;
}

void WorldSquare::update(int t_isTherePlatform, int t_posX, int t_posY)
{
	setPos(t_isTherePlatform, t_posX, t_posY);
}

void WorldSquare::setPos(int t_isTherePlatform, int t_posX, int t_posY)
{
	if (t_isTherePlatform > 0)
	{
		m_platform.setPosition(t_posX, t_posY);
	}
}

bool WorldSquare::isSolidBlock()
{
	return m_solidBlock;
}

void WorldSquare::draw(sf::RenderWindow &t_window)
{
	t_window.draw(m_platform);
}
