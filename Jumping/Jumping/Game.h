// author Patrick Darcy
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "WorldSquare.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	int const MAX_PLAYER = 2;

	sf::RectangleShape m_Player;
	int isTherePlatform[12][12] = { 0,0,0,0,0,0,0,0,0,0,0,0,
									1,1,1,1,0,0,0,0,1,1,1,1,
									0,0,0,0,0,0,0,0,0,0,0,0,
									0,0,0,0,1,1,1,1,0,0,0,0,
									0,0,0,0,0,0,0,0,0,0,0,0,
									1,1,1,1,1,1,1,1,1,0,0,0,
									0,0,0,0,0,0,0,0,0,0,0,0,
									0,0,0,1,1,1,1,1,1,1,1,1,
									0,0,0,0,0,0,0,0,0,0,0,0,
									1,1,1,1,1,1,1,1,0,0,0,0,
									0,0,0,0,0,0,0,0,0,0,0,0,
									1,1,1,1,1,1,1,1,1,1,1,1 };

	enum m_playerState { grounded, jumping, falling };
	m_playerState playerstate;
	sf::Vector2f m_playerPos = {100,500};
	float m_playerSpeed = 2.5;
	int const MAX_HEIGHT = 350;
	int const MIN_HEIGHT = 500;
	WorldSquare m_platform[12][12];

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void playerMovement();
	void render();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME

