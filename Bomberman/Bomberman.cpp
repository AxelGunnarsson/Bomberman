// Bomberman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Bomb.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "Playerdummy.h"

int PlayerAmount = 4;
std::list<sf::Vector2f> GubbePos;
std::vector<Player> Players;
//Player Gubbe1 = Player(sf::Vector2f(180,150),sf::Vector2f(180,150),std::string("PlayerOne.png"),sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::Num1);
//Player Gubbe2 = Player(sf::Vector2f(573,301),sf::Vector2f(573,150),std::string("PlayerTwo.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);

std::vector<Playerdummy> Playerdummies;
//Playerdummy Gubbe12 = Playerdummy(Gubbe2);
//Playerdummy Gubbe21 = Playerdummy(Gubbe1);

void loadPlayerdummies()
{
	int i, j;
	for(i = 0; i < PlayerAmount;i++)
	{
		for(j = 0; j < PlayerAmount;j++)
		{
			if(i!=j)
			{
				Playerdummy tmp = Playerdummy(Players[i]);
				Playerdummies.push_back(tmp);
			}
		}
	}

}

void loadPlayers()
{
	if(PlayerAmount == 2)
	{
		Player player1 = Player(sf::Vector2f(180,150),sf::Vector2f(180,150),std::string("PlayerOne.png"),sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::Num1);
		Player player2 = Player(sf::Vector2f(573,301),sf::Vector2f(573,150),std::string("PlayerTwo.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);

		Players.push_back(player1);
		Players.push_back(player2);
		loadPlayerdummies();
	}
	else if(PlayerAmount == 4)
	{
		Player player1 = Player(sf::Vector2f(180,150),sf::Vector2f(180,150),std::string("PlayerOne.png"),sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::Num1);
		Player player2 = Player(sf::Vector2f(573,150),sf::Vector2f(573,150),std::string("PlayerTwo.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);
		Player player3 = Player(sf::Vector2f(180,483),sf::Vector2f(180,453),std::string("PlayerOne.png"),sf::Keyboard::K,sf::Keyboard::K,sf::Keyboard::K,sf::Keyboard::K,sf::Keyboard::K);
		Player player4 = Player(sf::Vector2f(573,483),sf::Vector2f(573,453),std::string("PlayerTwo.png"),sf::Keyboard::K,sf::Keyboard::K,sf::Keyboard::K,sf::Keyboard::K,sf::Keyboard::K);

		Players.push_back(player1);
		Players.push_back(player2);
		Players.push_back(player3);
		Players.push_back(player4);
		loadPlayerdummies();
	}
}

void initGame()
{
	int i;
	Map::load();
	loadPlayers();

	Playerdummy Gubbe12 = Playerdummy(Players[0]); // nå för alla gubbar
	Playerdummy Gubbe21 = Playerdummy(Players[1]); // nå för alla gubbar
	Playerdummies.push_back(Gubbe12);
	Playerdummies.push_back(Gubbe21);

	for(i = 0 ; i < PlayerAmount; i++)
	{
		GubbePos.push_back(Players[i].getPos());
	}
	//Map::newMap(GubbePos);
}

void Game(sf::RenderWindow& window)
{
	initGame();
	int i,j;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window.close();
		}

		window.clear();
		for(i = 0; i < (int)Players.size();i++)
		{
			Map::draw(window,Players[i].getPos(),Players[i].getStaticPos());
			Players[i].update();
			Players[i].draw(window);
		}
		//Map::draw(window,Gubbe1.getPos(),Gubbe1.getStaticPos());
		//Map::draw(window,Gubbe2.getPos(),Gubbe2.getStaticPos());

		//Gubbe1.update();
		//Gubbe1.draw(window);
		//Gubbe2.update();
		//Gubbe2.draw(window);
		for(i = 0; i < (int)Playerdummies.size();i++)
		{
			for(j = 0; j < PlayerAmount;j++)
			{
				Playerdummies[i].draw(window);
				Playerdummies[i].update(Players[j].getStaticPos(),Players[j].getPos());
			}
		}

		/*
		Gubbe21.draw(window);
		Gubbe21.update(Gubbe1.getPos(),Gubbe1.getTextureRect(),Gubbe2.getStaticPos(),Gubbe2.getPos());

		Gubbe12.draw(window);
		Gubbe12.update(Gubbe2.getPos(),Gubbe2.getTextureRect(),Gubbe1.getStaticPos(),Gubbe1.getPos());
		*/

		window.display();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Bomberman");
	window.setFramerateLimit(60);

	Game(window);
	return 0;
}

