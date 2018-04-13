#pragma once
#include "SFML\Graphics.hpp"

class WorldSquare
{
	sf::RectangleShape m_platform;
	sf::Vector2f m_platformPos;
	bool m_solidBlock;
public:

	WorldSquare();
	void update(int t_isTherePlatform, int t_posX, int t_posY);
	void setPos(int t_isTherePlatform, int t_posX, int t_posY);
	bool isSolidBlock();
	void draw(sf::RenderWindow &t_window);

};