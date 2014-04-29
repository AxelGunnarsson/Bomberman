// Bomberman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Bomb.h"
#include "Map.h"


#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(390, 390), "BOmberManarDoodle");
	window.setFramerateLimit(60);

	Map::load();
	Player Gubbe1 = Player(sf::Vector2f(32,32),std::string("PlayerOne.png"),sf::Keyboard::W,sf::Keyboard::S,sf::Keyboard::A,sf::Keyboard::D,sf::Keyboard::Num1);
	Player Gubbe2 = Player(sf::Vector2f(332,332),std::string("PlayerTwo.png"),sf::Keyboard::Up,sf::Keyboard::Down,sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Numpad1);
	
	
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }

		Gubbe1.update();
		Gubbe2.update();
        
		window.clear();

		Map::draw(window);

		Gubbe1.draw(window); 
		Gubbe2.draw(window); 

       window.display();
    }

    return 0;
}

