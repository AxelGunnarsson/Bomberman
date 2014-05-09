#pragma once
#include <SFML\Graphics.hpp>
#include <list>

class Map
{
public:
	static void draw(sf::RenderTarget& tgt,sf::Vector2f,sf::Vector2f);
	static void update(sf::Vector2i,sf::Vector2i);
	static void load();
	static sf::Vector2i getBlock(sf::Vector2i);
	static void newMap(std::list<sf::Vector2f>);
	~Map(void);
private:

};