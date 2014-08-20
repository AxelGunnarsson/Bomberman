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

	if(correctedPos.x < centerPos.x - 210 || correctedPos.x > centerPos.x + 210 || correctedPos.y < centerPos.y - 180 || correctedPos.y > centerPos.y + 180)
		dummy_sprite.setTextureRect(sf::IntRect(0,0,0,0));	//invis

	else if(correctedPos.x > centerPos.x - 210 && correctedPos.x < centerPos.x - 180)
	{
		left = textureRect.left + ( actualPos.x - 180 - originalPlayerPos.x);
		width = textureRect.width - ( actualPos.x - 180 - originalPlayerPos.x);
		dummy_sprite.setPosition(centerPos.x - 180,correctedPos.y);
		dummy_sprite.setTextureRect(sf::IntRect(left,textureRect.top,width,textureRect.height));
	}

	else if(correctedPos.x < centerPos.x + 211 && correctedPos.x > centerPos.x + 148)
	{
		left = textureRect.left;
		width = textureRect.width - (32 - ( actualPos.x + 210 - originalPlayerPos.x));
		if(width > 32)
			width = 32;
		dummy_sprite.setTextureRect(sf::IntRect(left,textureRect.top,width,textureRect.height));
	}

	else if(correctedPos.y > centerPos.y - 210 && correctedPos.y < centerPos.y - 180)
	{
		top = textureRect.top + ( actualPos.x - 180 - originalPlayerPos.x);
		height = textureRect.height - ( actualPos.y - 180 - originalPlayerPos.y);
		dummy_sprite.setPosition(correctedPos.x,centerPos.y - 180);
		dummy_sprite.setTextureRect(sf::IntRect(textureRect.left,top,textureRect.width,height));
	}

	else if(correctedPos.y < centerPos.y + 181 && correctedPos.y > centerPos.y + 148)
	{
		top = textureRect.top;
		height = textureRect.height - (32 - ( actualPos.y + 180 - originalPlayerPos.y));

		dummy_sprite.setTextureRect(sf::IntRect(textureRect.left,top,textureRect.width,height));
	}

	else
		dummy_sprite.setTextureRect(textureRect);

}

Playerdummy::~Playerdummy(void)
{
}
