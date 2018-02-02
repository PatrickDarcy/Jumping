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
	int const MAX_PLAYER = 2;

	sf::RectangleShape m_Player;
	sf::RectangleShape m_ground;
	sf::RectangleShape m_enemy[2];
	sf::Text Score;
	sf::Font arialFont;
	enum playerState { grounded, jumping, falling };
	playerState playerstate;
	int playerY = 100;
	int enemyX = 725;
	int const MAX_HEIGHT = 250;
	int const MIN_HEIGHT = 100;
	float score;
	int score1;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME

