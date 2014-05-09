#include "stdafx.h"
#include "Map.h"
#include "Block.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
#include <random>

using namespace std;

static sf::Texture BoxTextur;
static sf::Sprite Box;
static sf::Vector2i loadCounter;
static sf::Vector2i mapMat[50][50];
static sf::Vector2i Size = sf::Vector2i(40,40);

void Map::draw(sf::RenderTarget& tgt,sf::Vector2f playerPos,sf::Vector2f playerStaticPos)
{
	for (int i = 0; i < Size.x; i++)
	{
		for (int j = 0; j < Size.y; j++)
		{

			Box.setPosition((float)i * 30 - playerPos.x + playerStaticPos.x, (float)j * 30 - playerPos.y + playerStaticPos.y);
			Box.setTextureRect(sf::IntRect(mapMat[i][j].x * 30, mapMat[i][j].y * 30, 30, 30));

			int boundryRight = playerStaticPos.x + 150 - (int)Box.getPosition().x;
			int boundryLeft = playerStaticPos.x - 150 - (int)Box.getPosition().x;
			int boundryUp = playerStaticPos.y - 150 - (int)Box.getPosition().y;
			int boundryDown = playerStaticPos.y + 150 - (int)Box.getPosition().y;

			int leftx = mapMat[i][j].x * 30;
			int lefty = mapMat[i][j].y * 30;
			int rightx = 30;
			int righty = 30;

			if(Box.getPosition().x > playerStaticPos.x + 150 || Box.getPosition().y > playerStaticPos.y + 150)
			{
				break;
			}

			if(Box.getPosition().x > playerStaticPos.x + 120)
			{				
				rightx = boundryRight;
			}
			if(Box.getPosition().y > playerStaticPos.y + 120)
			{
				righty = boundryDown;
			}
			if(Box.getPosition().x < playerStaticPos.x - 150)
			{
				Box.setPosition(playerStaticPos.x - 150,Box.getPosition().y);
				leftx = mapMat[i][j].x * 30 + boundryLeft;
			}
			if(Box.getPosition().y < playerStaticPos.y - 150)
			{
				Box.setPosition(Box.getPosition().x, playerStaticPos.y - 150);
				lefty = mapMat[i][j].y * 30 + boundryUp;
			}
			Box.setTextureRect(sf::IntRect(leftx,lefty,rightx,righty));
			tgt.draw(Box);

		}
	}
}
void Map::update(sf::Vector2i pos,sf::Vector2i type)
{
	mapMat[pos.x][pos.y] = type;
}

Map::~Map(void)
{
}

void Map::load()
{
	BoxTextur.loadFromFile("Bild.png");
	Box.setTexture(BoxTextur);
	for (int x = 0; x < Size.x + 8; x++)
	{
		for (int y = 0; y < Size.y + 8; y++)
		{
			if(x == 0 || y == 0 || x == Size.x - 1 || y == Size.y - 1 )
				mapMat[x][y] = Block::Wall();
			else if(x % 2 == 0 && y % 2 == 0)
				mapMat[x][y] = Block::Wall();
			else
				mapMat[x][y] = Block::Ground();
		}
	}
}

sf::Vector2i Map::getBlock(sf::Vector2i pos)
{
	return mapMat[(int)pos.x][(int)pos.y];
}

void Map::newMap(list<sf::Vector2f> posListf)
{
	std::list<sf::Vector2i> posListi;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,1);

	bool safeZoneClear = true;

	for each (sf::Vector2f f in posListf)
	{
		posListi.push_back(sf::Vector2i((int)(f.x + 15) / 30,(int)(f.y + 15) / 30));
	}

	for (int x = 1; x < Size.x; x++)
	{
		for (int y = 1; y < Size.y; y++)
		{
			if(getBlock(sf::Vector2i(x,y)) != Block::Wall())
				update(sf::Vector2i(x,y),Block::Ground());
			for each (sf::Vector2i pos in posListi)
			{
				for(int x2 = -1; x2 < 2; x2++)
				{
					for(int y2 = -1; y2 < 2; y2++)
					{
						if(sf::Vector2i(x+x2,y+y2) == pos)
						{
							safeZoneClear = false;
						}
					}
				}
			}
			if(safeZoneClear == true)
			{
				int random = distribution(generator);
				if(getBlock(sf::Vector2i(x,y)) != Block::Wall() && random == 0)
					update(sf::Vector2i(x,y),Block::Box());
			}
			safeZoneClear = true;

		}
	}
}

