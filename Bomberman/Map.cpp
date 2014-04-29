#include "stdafx.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

static sf::Texture BlockTextur;
static sf::Sprite Block;
static sf::Vector2i loadCounter;
static sf::Vector2i mapMat[13][13];

void Map::draw(sf::RenderTarget& tgt)
{
	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j < loadCounter.y; j++)
		{
			if(mapMat[i][j].x != -1 && mapMat[i][j].y != -1)
			{
				Block.setPosition((float)i * 30, (float)j * 30);
				Block.setTextureRect(sf::IntRect(mapMat[i][j].x * 30, mapMat[i][j].y * 30, 30, 30));
				tgt.draw(Block);
			}
		}
	}
}
void Map::update(sf::Vector2i pos,sf::Vector2i type)
{
	mapMat[pos.x][pos.y].x = type.x;
	mapMat[pos.x][pos.y].y = type.y;
}

Map::~Map(void)
{
}

int Map::collision(sf::Vector2f pos)
{
	int posx = ((int)pos.x - (int)pos.x % 30) / 30;
	int posy = ((int)pos.y - (int)pos.y % 30) / 30;

	if(mapMat[posx][posy] == sf::Vector2i(1,1))
		return 0;
	else if(mapMat[posx][posy] == sf::Vector2i(0,1))
		return 0;
	else if(mapMat[posx][posy] == sf::Vector2i(2,1))
		return 0;
	else if(mapMat[posx][posy] == sf::Vector2i(2,0))
		return 2;
	else if(mapMat[posx][posy] == sf::Vector2i(2,2))
		return 3;
	return 1;
}

void Map::load()
{
	ifstream Banan("Bana2.txt");
	loadCounter = sf::Vector2i(0, 0);
	if(Banan.is_open())
	{
		BlockTextur.loadFromFile("Bild.png");
		Block.setTexture(BlockTextur);
		while (!Banan.eof())
		{
			string str;
			Banan >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
				mapMat[loadCounter.x][loadCounter.y] = sf::Vector2i(-1,-1);
			else
				mapMat[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			if (Banan.peek() == '\n')
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else 
				loadCounter.x ++;
		}
		loadCounter.y ++;
	}
}

sf::Vector2i Map::getBlock(sf::Vector2i pos)
{
	return mapMat[(int)pos.x][(int)pos.y];
}