#include "stdafx.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

static sf::Texture BoxTextur;
static sf::Sprite Box;
static sf::Vector2i loadCounter;
static sf::Vector2i mapMat[13][13];
static sf::Vector2i Wall;

void Map::draw(sf::RenderTarget& tgt)
{
	Wall = sf::Vector2i(0,0);
	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j < loadCounter.y; j++)
		{
			if(mapMat[i][j].x != -1 && mapMat[i][j].y != -1)
			{
				Box.setPosition((float)i * 30, (float)j * 30);
				Box.setTextureRect(sf::IntRect(mapMat[i][j].x * 30, mapMat[i][j].y * 30, 30, 30));
				tgt.draw(Box);
			}
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
	ifstream Banan("Bana2.txt");
	loadCounter = sf::Vector2i(0, 0);
	if(Banan.is_open())
	{
		BoxTextur.loadFromFile("Bild.png");
		Box.setTexture(BoxTextur);
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

