#pragma once
#include <SFML\Graphics.hpp>
class Block
{
public:
	static sf::Vector2i Wall(void);
	static sf::Vector2i Box(void);
	static sf::Vector2i Ground(void);
	static sf::Vector2i Bomb(void);
	static sf::Vector2i PowerUp1(void);
	static sf::Vector2i PowerUp2(void);
};

