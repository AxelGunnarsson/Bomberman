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

	int left, width, top, height;

	if(correctedPos.x < centerPos.x - 180 || correctedPos.x > centerPos.x + 150 || correctedPos.y < centerPos.y - 150 || correctedPos.y > centerPos.y + 150)
		dummy_sprite.setTextureRect(sf::IntRect(0,0,0,0));	//invis
	else if(correctedPos.x > centerPos.x - 180 && correctedPos.x < centerPos.x - 150)
	{
		left = textureRect.left + ( actualPos.x - 150 - originalPlayerPos.x);
		width = textureRect.width - ( actualPos.x - 150 - originalPlayerPos.x);
		dummy_sprite.setPosition(centerPos.x - 150,correctedPos.y);
		dummy_sprite.setTextureRect(sf::IntRect(left,textureRect.top,width,textureRect.height));
	}

	else if(correctedPos.x < centerPos.x + 151 && correctedPos.x > centerPos.x + 118)
	{
		left = textureRect.left;
		width = textureRect.width - (32 - ( actualPos.x + 150 - originalPlayerPos.x));
		dummy_sprite.setTextureRect(sf::IntRect(left,textureRect.top,width,textureRect.height));
	}

	else
		dummy_sprite.setTextureRect(textureRect);

}

Playerdummy::~Playerdummy(void)
{
}
