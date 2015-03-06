#pragma once
#include "Player.h"
class Playerdummy
{
	Player &copyFrom;
	sf::Vector2f pos;
	sf::Sprite dummy_sprite;
	
public:
	Playerdummy(Player&);
	void draw(sf::RenderTarget&);
	void update(sf::Vector2f,sf::Vector2f);
	~Playerdummy(void);
};

