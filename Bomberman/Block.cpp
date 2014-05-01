#include "stdafx.h"
#include "Block.h"
#include <SFML\Graphics.hpp>

sf::Vector2i Block::Wall()
{
	return sf::Vector2i(0,0);
}

sf::Vector2i Block::Box()
{
	return sf::Vector2i(1,0);
}

sf::Vector2i Block::Ground()
{
	return sf::Vector2i(1,1);
}

sf::Vector2i Block::Bomb()
{
	return sf::Vector2i(0,1);
}

sf::Vector2i Block::PowerUp1()
{
	return sf::Vector2i(2,0);
}

sf::Vector2i Block::PowerUp2()
{
	return sf::Vector2i(2,2);
}