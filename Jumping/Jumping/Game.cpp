// author Ptrick Darcy

#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ 600, 600, 32 }, "Jumping Game" },
	m_exitGame{ false }, //when true game will exit
	playerstate{ grounded }


{


	m_Player.setSize(sf::Vector2f{ 50,50 });
	m_Player.setPosition(100, 500);
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
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			//if (isTherePlatform[i][j] == 1 && m_Player.getGlobalBounds().intersects(m_platform[i][j].getGlobalBounds()))
			//{
			//	
			//}
		}
	}


	playerMovement();

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			int r = isTherePlatform[i][j];
			int rX = i * 50;
			int rY = j * 50;
			m_platform[i][j].update(r, rY, rX );
		}
	}

	if (m_exitGame)
	{
		m_window.close();
	}

}

void Game::playerMovement()
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_playerPos.x -= m_playerSpeed;
			m_Player.setPosition(m_playerPos);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_playerPos.x += m_playerSpeed;
			m_Player.setPosition(m_playerPos);
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
		m_playerPos.y -= 5;
		m_Player.setPosition(m_playerPos);

		if (m_playerPos.y <= MAX_HEIGHT)
		{
			playerstate = falling;
		}
	}
	if (playerstate == falling)
	{
		m_playerPos.y += 5;
		m_Player.setPosition(m_playerPos);

		if (m_playerPos.y >= MIN_HEIGHT)
		{
			playerstate = grounded;
		}

	}
}


/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_Player);

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			m_platform[i][j].draw(m_window);
		}
	}
	m_window.display();
}


