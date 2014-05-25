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
Player Gubbe2 = Player(sf::Vector2f(573,150),std::string("PlayerTwo.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);
Player Gubbe3 = Player(sf::Vector2f(180,483),std::string("PlayerThree.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);
Player Gubbe4 = Player(sf::Vector2f(573,483),std::string("PlayerThree.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);

Playerdummy Gubbe12 = Playerdummy(Gubbe1);
Playerdummy Gubbe13 = Playerdummy(Gubbe2);
Playerdummy Gubbe14 = Playerdummy(Gubbe3);
Playerdummy Gubbe21 = Playerdummy(Gubbe2);
Playerdummy Gubbe23 = Playerdummy(Gubbe2);
Playerdummy Gubbe24 = Playerdummy(Gubbe2);
Playerdummy Gubbe31 = Playerdummy(Gubbe3);
Playerdummy Gubbe32 = Playerdummy(Gubbe3);
Playerdummy Gubbe34 = Playerdummy(Gubbe3);
Playerdummy Gubbe41 = Playerdummy(Gubbe4);
Playerdummy Gubbe42 = Playerdummy(Gubbe4);
Playerdummy Gubbe43 = Playerdummy(Gubbe4);

void initGame()
{
	Map::load();
	GubbePos.push_back(Gubbe1.getPos());
	GubbePos.push_back(Gubbe2.getPos());
	GubbePos.push_back(Gubbe3.getPos());
	GubbePos.push_back(Gubbe4.getPos());
	Map::newMap(GubbePos);
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
		Map::draw(window,Gubbe3.getPos(),Gubbe3.getStaticPos());
		Map::draw(window,Gubbe4.getPos(),Gubbe4.getStaticPos());

		Gubbe1.update();
		Gubbe1.draw(window);
		Gubbe2.update();
		Gubbe2.draw(window);

		Gubbe3.update();
		Gubbe3.draw(window);
		Gubbe4.update();
		Gubbe4.draw(window);

		Gubbe12.draw(window);
		Gubbe12.update(Gubbe1.getPos(),Gubbe1.getTextureRect(),Gubbe2.getStaticPos(),Gubbe2.getPos());
		Gubbe13.draw(window);
		Gubbe13.update(Gubbe1.getPos(),Gubbe1.getTextureRect(),Gubbe3.getStaticPos(),Gubbe3.getPos());
		Gubbe14.draw(window);
		Gubbe14.update(Gubbe1.getPos(),Gubbe1.getTextureRect(),Gubbe4.getStaticPos(),Gubbe4.getPos());

		Gubbe21.draw(window);
		Gubbe21.update(Gubbe2.getPos(),Gubbe2.getTextureRect(),Gubbe1.getStaticPos(),Gubbe1.getPos());
		Gubbe23.draw(window);
		Gubbe23.update(Gubbe2.getPos(),Gubbe2.getTextureRect(),Gubbe3.getStaticPos(),Gubbe3.getPos());
		Gubbe24.draw(window);
		Gubbe24.update(Gubbe2.getPos(),Gubbe2.getTextureRect(),Gubbe4.getStaticPos(),Gubbe4.getPos());

		Gubbe31.draw(window);
		Gubbe31.update(Gubbe3.getPos(),Gubbe3.getTextureRect(),Gubbe1.getStaticPos(),Gubbe1.getPos());
		Gubbe32.draw(window);
		Gubbe32.update(Gubbe3.getPos(),Gubbe3.getTextureRect(),Gubbe2.getStaticPos(),Gubbe2.getPos());
		Gubbe34.draw(window);
		Gubbe34.update(Gubbe3.getPos(),Gubbe3.getTextureRect(),Gubbe4.getStaticPos(),Gubbe4.getPos());

		Gubbe41.draw(window);
		Gubbe41.update(Gubbe4.getPos(),Gubbe4.getTextureRect(),Gubbe1.getStaticPos(),Gubbe1.getPos());
		Gubbe42.draw(window);
		Gubbe42.update(Gubbe4.getPos(),Gubbe4.getTextureRect(),Gubbe2.getStaticPos(),Gubbe2.getPos());
		Gubbe43.draw(window);
		Gubbe43.update(Gubbe4.getPos(),Gubbe4.getTextureRect(),Gubbe3.getStaticPos(),Gubbe3.getPos());

		window.display();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(781, 690), "Bomberman");
	window.setFramerateLimit(60);

	Game(window);
	return 0;
}

