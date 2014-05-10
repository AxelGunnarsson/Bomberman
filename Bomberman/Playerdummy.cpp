#include "stdafx.h"
#include "Playerdummy.h"


Playerdummy::Playerdummy(Player player)
{
	dummy_sprite = player.getSprite();
}

void Playerdummy::draw(sf::RenderTarget& tgt)
{
	tgt.draw(dummy_sprite);
}

void Playerdummy::update(sf::Vector2f originalPlayerPos,sf::IntRect textureRect,sf::Vector2f centerPos,sf::Vector2f actualPos)
{
	sf::Vector2f correctedPos;
	correctedPos = sf::Vector2f(originalPlayerPos - ( actualPos - centerPos));
	dummy_sprite.setPosition(correctedPos);
	if(correctedPos.x > centerPos.x - 150 && correctedPos.x < centerPos.x + 150 && correctedPos.y > centerPos.y - 150 && correctedPos.y < centerPos.y + 150)
		dummy_sprite.setTextureRect(textureRect);
	else
		dummy_sprite.setTextureRect(sf::IntRect(0,0,0,0));	//invis
}

Playerdummy::~Playerdummy(void)
{
}
