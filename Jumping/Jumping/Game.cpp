// author Ptrick Darcy

#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Jumping Game" },
	m_exitGame{ false }, //when true game will exit
	playerstate{grounded}

{
	sf::Texture texture_enemy;
	if (!texture_enemy.loadFromFile("stalagtite.gif"))
	{
		std::cout << "Error" << std::endl;
	}
	m_enemy.setPosition(enemyX, 100);

	m_ground.setSize(sf::Vector2f{ 800, 100 });
	m_ground.setPosition(0, 0);
	m_ground.setFillColor(sf::Color::Green);

	m_Player.setSize(sf::Vector2f{ 50,50 });
	m_Player.setPosition(100, 100);
	m_Player.setFillColor(sf::Color::Cyan);
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}

	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	enemyX -= 5;
	m_enemy.setPosition(enemyX, 100);

	if (enemyX == 0)
	{
		enemyX = 800;
	}
	if (playerstate == grounded)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			playerstate = jumping;
		}
	}
	if (playerstate == jumping)
	{
		playerY += 5;
		m_Player.setPosition(100, playerY);

		if (playerY == MAX_HEIGHT)
		{
			playerstate = falling;
		}
	}
	if (playerstate == falling)
	{
		playerY -= 5;
		m_Player.setPosition(100, playerY);

		if (playerY == MIN_HEIGHT)
		{
			playerstate = grounded;
		}
		
	}
	if (m_Player.getGlobalBounds().intersects(m_enemy.getGlobalBounds()))
	{
		enemyX = 800;
	}

	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_ground);
	m_window.draw(m_Player);
	m_window.draw(m_enemy);
	m_window.display();
}

