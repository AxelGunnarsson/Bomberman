#pragma once
#include <SFML/Graphics.hpp>

class Bomb
{
private:
	sf::Texture m_texturen;
	sf::Sprite spriten;
	int x, z,range,droprate;
	bool Exploded;

public:
	Bomb();
	Bomb(sf::Vector2i,int);
	~Bomb(void);
	bool explode(sf::RenderTarget& tgt);
	bool timeToExplode();
	void draw(sf::RenderTarget& tgt);
	bool exploded();
};


