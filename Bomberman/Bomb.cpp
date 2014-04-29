#include "stdafx.h"
#include "Bomb.h"
#include <time.h>
#include "Map.h"

Bomb::Bomb()
{

}

Bomb::Bomb(sf::Vector2i Pos,int Range)
{
	range = Range;
	x = 0;
	z = 0;
	Exploded = false;
	spriten.setTexture(m_texturen);
	spriten.setPosition((float)Pos.x * 30,(float)Pos.y * 30);
	spriten.setScale(1,1);
	Exploded = false;
	droprate = 10;
}


Bomb::~Bomb(void)
{
}

void Bomb::draw(sf::RenderTarget& tgt)
{
	if(timeToExplode() == true)
	{
		explode(tgt);
	}
	else
		Map::update(sf::Vector2i(((int)spriten.getPosition().x + 15) / 30,((int)spriten.getPosition().y + 15)/30),sf::Vector2i(0,1));
	
}

bool Bomb::timeToExplode()
{
	if(x == 120)
	{
		return true;
	}
	else 
	{
		x++;
		return false;
	}
}

bool firstRound = false;

bool Bomb::explode(sf::RenderTarget& tgt)
{
	int x = (int)spriten.getPosition().x / 30;
	int y = (int)spriten.getPosition().y / 30;

	if(firstRound == false)
	{
		Map::update(sf::Vector2i(x,y),sf::Vector2i(3,2));

		for(int yled = 1; yled < range+1; yled ++)
		{
			if(Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(0,0) || Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(2,0) || Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(2,2) || Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(0,1))
				break;	
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(1,0))
			{
				Map::update(sf::Vector2i(x,y - yled),sf::Vector2i(5,0));
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(1,1))
				Map::update(sf::Vector2i(x,y - yled),sf::Vector2i(3,0));
		}
		for(int yled = 1; yled < range+1; yled ++)
		{
			if(Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(0,0) || Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(2,0) || Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(2,2) || Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(0,1))
				break;	
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(1,0))
			{
				Map::update(sf::Vector2i(x,y + yled),sf::Vector2i(6,0));
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(1,1))
				Map::update(sf::Vector2i(x,y + yled),sf::Vector2i(4,0));
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			if(Map::getBlock(sf::Vector2i(x - xled,y)) == sf::Vector2i(0,0) || Map::getBlock(sf::Vector2i(x-xled,y)) == sf::Vector2i(2,0) || Map::getBlock(sf::Vector2i(x-xled,y)) == sf::Vector2i(2,2) || Map::getBlock(sf::Vector2i(x-xled,y)) == sf::Vector2i(0,1))
				break;	
			else if(Map::getBlock(sf::Vector2i(x - xled,y)) == sf::Vector2i(1,0))
			{
				Map::update(sf::Vector2i(x - xled,y),sf::Vector2i(6,1));
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x - xled,y)) == sf::Vector2i(1,1))
				Map::update(sf::Vector2i(x - xled,y),sf::Vector2i(4,1));
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			if(Map::getBlock(sf::Vector2i(x + xled,y)) == sf::Vector2i(0,0) || Map::getBlock(sf::Vector2i(x+xled,y)) == sf::Vector2i(2,0) || Map::getBlock(sf::Vector2i(x+xled,y)) == sf::Vector2i(2,2) || Map::getBlock(sf::Vector2i(x+xled,y)) == sf::Vector2i(0,1))
				break;	
			else if(Map::getBlock(sf::Vector2i(x + xled,y)) == sf::Vector2i(1,0))
			{
				Map::update(sf::Vector2i(x + xled,y),sf::Vector2i(5,1));
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x + xled,y)) == sf::Vector2i(1,1))
				Map::update(sf::Vector2i(x + xled,y),sf::Vector2i(3,1));
		}

		firstRound = true;
	}

	if( z < 30)
	{
		z++;
		return false;
	}
	else 
	{
		z = 0;
		Exploded = true;
		return true;
	}
}

bool Bomb::exploded()
{
	int b = 0;
	if(Exploded == true)
	{
		int x = (int)spriten.getPosition().x / 30;
		int y = (int)spriten.getPosition().y / 30;
		

		for(int yled = 1; yled < range+1; yled ++)
		{
			b = rand() % droprate;
			if(Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(0,0))
				break;	
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(1,0))
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(3,0))
			{
				Map::update(sf::Vector2i(x,y - yled),sf::Vector2i(1,1));	// test 2,1
			}
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == sf::Vector2i(5,0))
			{
				if(b==1)
					Map::update(sf::Vector2i(x,y - yled),sf::Vector2i(2,0));	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x,y - yled),sf::Vector2i(2,2));	// test 2,1
				else
					Map::update(sf::Vector2i(x,y - yled),sf::Vector2i(1,1));	// test 2,1
			}
		}
		for(int yled = 1; yled < range+1; yled ++)
		{
			b = rand() % droprate;
			if(Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(0,0))
				break;	
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(1,0))
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(4,0))
			{
				Map::update(sf::Vector2i(x,y + yled),sf::Vector2i(1,1));
			}
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == sf::Vector2i(6,0))
			{
				if(b==1)
					Map::update(sf::Vector2i(x,y + yled),sf::Vector2i(2,0));	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x,y + yled),sf::Vector2i(2,2));	// test 2,1
				else
					Map::update(sf::Vector2i(x,y + yled),sf::Vector2i(1,1));	// test 2,1
			}
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			b = rand() % droprate;
			if(Map::getBlock(sf::Vector2i(x - xled ,y)) == sf::Vector2i(0,0))
				break;	
			else if(Map::getBlock(sf::Vector2i(x - xled ,y)) == sf::Vector2i(1,0))
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x - xled ,y)) == sf::Vector2i(4,1))
			{
				Map::update(sf::Vector2i(x - xled ,y),sf::Vector2i(1,1));
			}
			else if(Map::getBlock(sf::Vector2i(x - xled,y)) == sf::Vector2i(6,1))
			{
				if(b==1)
					Map::update(sf::Vector2i(x - xled,y),sf::Vector2i(2,0));	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x - xled,y),sf::Vector2i(2,2));	// test 2,1
				else
					Map::update(sf::Vector2i(x - xled,y),sf::Vector2i(1,1));	// test 2,1
			}
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			b = rand() % droprate;
			if(Map::getBlock(sf::Vector2i(x + xled ,y)) == sf::Vector2i(0,0))
				break;	
			else if(Map::getBlock(sf::Vector2i(x + xled ,y)) == sf::Vector2i(1,0))
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x + xled ,y)) == sf::Vector2i(3,1))
			{
				Map::update(sf::Vector2i(x + xled ,y),sf::Vector2i(1,1));
			}
			else if(Map::getBlock(sf::Vector2i(x + xled,y)) == sf::Vector2i(5,1))
			{
				if(b==1)
					Map::update(sf::Vector2i(x + xled,y),sf::Vector2i(2,0));	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x + xled,y),sf::Vector2i(2,2));	// test 2,1
				else
					Map::update(sf::Vector2i(x + xled,y),sf::Vector2i(1,1));	// test 2,1
			}
		}
		Map::update(sf::Vector2i(x,y),sf::Vector2i(1,1));

		firstRound = false;
	}
	return Exploded;
}

