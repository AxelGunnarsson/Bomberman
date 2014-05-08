// Bomberman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Bomb.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <list>

std::list<Player> Spelare;
std::list<sf::Vector2i> GubbePos;

void initGame()
{
	Map::load();
	//Spelare.push_back(Player(sf::Vector2f(32,32),std::string("PlayerOne.png"),sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::Num1));
	Spelare.push_back(Player(sf::Vector2f(332,332),std::string("PlayerOne.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1));
}

void Game(sf::RenderWindow& window)
{
	Player Gubbe1 = Player(sf::Vector2f(32,32),std::string("PlayerOne.png"),sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::Num1);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				for each (Player gubbe in Spelare)
				{
					GubbePos.push_back(gubbe.getPos());
				}
				Map::newMap(GubbePos);
			}
		}

		window.clear();
		Map::draw(window);

		for each (Player gubbe in Spelare)
		{
			gubbe.update();
		}
		Gubbe1.update();
		for each (Player gubbe in Spelare)
		{
			gubbe.draw(window); 
		}
		Gubbe1.draw(window);
		window.display();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(490, 390), "Bomberman");
	window.setFramerateLimit(60);

	initGame();
	Game(window);
	return 0;
}

