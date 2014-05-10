// Bomberman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Bomb.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "Playerdummy.h"

std::list<sf::Vector2f> GubbePos;
Player Gubbe1 = Player(sf::Vector2f(180,150),std::string("PlayerOne.png"),sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::Num1);
Player Gubbe2 = Player(sf::Vector2f(541,150),std::string("PlayerTwo.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);
//Player Gubbe3 = Player(sf::Vector2f(150,451),std::string("PlayerThree.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);
Playerdummy Gubbe12 = Playerdummy(Gubbe1);
Playerdummy Gubbe21 = Playerdummy(Gubbe2);
void initGame()
{
	Map::load();
	GubbePos.push_back(Gubbe1.getPos());
	GubbePos.push_back(Gubbe2.getPos());
	//GubbePos.push_back(Gubbe3.getPos());
	//Map::newMap(GubbePos);
}

void Game(sf::RenderWindow& window)
{
	initGame();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
		}

		window.clear();
		Map::draw(window,Gubbe1.getPos(),Gubbe1.getStaticPos());
		Map::draw(window,Gubbe2.getPos(),Gubbe2.getStaticPos());
		//Map::draw(window,Gubbe3.getPos(),Gubbe3.getStaticPos());

		Gubbe1.update();
		Gubbe1.draw(window);
		Gubbe2.update();
		Gubbe2.draw(window);

		//Gubbe3.update();
		//Gubbe3.draw(window);

		Gubbe12.draw(window);
		Gubbe12.update(Gubbe1.getPos(),Gubbe1.getTextureRect(),Gubbe2.getStaticPos(),Gubbe2.getPos());

		Gubbe21.draw(window);
		Gubbe21.update(Gubbe2.getPos(),Gubbe2.getTextureRect(),Gubbe1.getStaticPos(),Gubbe1.getPos());

		window.display();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(790, 690), "Bomberman");
	window.setFramerateLimit(60);

	Game(window);
	return 0;
}

