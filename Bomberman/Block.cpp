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

sf::Vector2i Block::BombUp1(void)
{
	return sf::Vector2i(5,0);
}

sf::Vector2i Block::BombUp2(void)
{
	return sf::Vector2i(10,0);
}

sf::Vector2i Block::BombUpMid(void)
{
	return sf::Vector2i(5,1);
}

sf::Vector2i Block::BombDown1(void)
{
	return sf::Vector2i(5,4);
}

sf::Vector2i Block::BombDown2(void)
{
	return sf::Vector2i(10,4);
}

sf::Vector2i Block::BombDownMid(void)
{
	return sf::Vector2i(5,3);
}

sf::Vector2i Block::BombLeft1(void)
{
	return sf::Vector2i(3,2);
}

sf::Vector2i Block::BombLeft2(void)
{
	return sf::Vector2i(8,2);
}

sf::Vector2i Block::BombLeftMid(void)
{
	return sf::Vector2i(4,2);
}

sf::Vector2i Block::BombRight1(void)
{
	return sf::Vector2i(7,2);
}

sf::Vector2i Block::BombRight2(void)
{
	return sf::Vector2i(12,2);
}

sf::Vector2i Block::BombRightMid(void)
{
	return sf::Vector2i(6,2);
}

sf::Vector2i Block::BombMiddle(void)
{
	return sf::Vector2i(5,2);
}