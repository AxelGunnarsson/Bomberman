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
	static sf::Vector2i BombUp1(void);
	static sf::Vector2i BombUp2(void);
	static sf::Vector2i BombUpMid(void);
	static sf::Vector2i BombDown1(void);
	static sf::Vector2i BombDown2(void);
	static sf::Vector2i BombDownMid(void);
	static sf::Vector2i BombLeft1(void);
	static sf::Vector2i BombLeft2(void);
	static sf::Vector2i BombLeftMid(void);
	static sf::Vector2i BombRight1(void);
	static sf::Vector2i BombRight2(void);
	static sf::Vector2i BombRightMid(void);
	static sf::Vector2i BombMiddle(void);

};

