#pragma once
#include <SFML\Graphics.hpp>
class Map
{
public:
	static void draw(sf::RenderTarget& tgt);
	static void update(sf::Vector2i,sf::Vector2i);
	static int collision(sf::Vector2f); //Ska vara i player föfan
	static void load();
	static sf::Vector2i getBlock(sf::Vector2i);
	~Map(void);
private:

};