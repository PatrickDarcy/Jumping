// author Patrick Darcy
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	sf::RectangleShape m_Player;
	sf::RectangleShape m_ground;
	sf::Sprite m_enemy;
	enum playerState { grounded, jumping, falling };
	playerState playerstate;
	int playerY = 100;
	int enemyX = 725;
	int const MAX_HEIGHT = 200;
	int const MIN_HEIGHT = 100;
private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME

