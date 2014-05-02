#include "stdafx.h"
#include "Bomb.h"
#include <time.h>
#include "Map.h"
#include "Block.h"

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
	firstRound = false;
	droprate = 10;
}


Bomb::~Bomb(void)
{
}

void Bomb::draw(sf::RenderTarget& tgt)
{
	if(timeToExplode() == true)
	{
		explode();
	}
	else
		Map::update(sf::Vector2i(((int)spriten.getPosition().x + 15) / 30,((int)spriten.getPosition().y + 15)/30),Block::Bomb());
	
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

bool Bomb::explode()
{
	int x = (int)spriten.getPosition().x / 30;
	int y = (int)spriten.getPosition().y / 30;

	if(firstRound == false)
	{
		Map::update(sf::Vector2i(x,y),Block::BombMiddle());

		for(int yled = 1; yled < range + 1; yled ++)
		{
			if(Map::getBlock(sf::Vector2i(x,y - yled)) == Block::Wall() ||
				Map::getBlock(sf::Vector2i(x,y - yled)) == Block::PowerUp1() || 
				Map::getBlock(sf::Vector2i(x,y - yled)) == Block::PowerUp2() || 
				Map::getBlock(sf::Vector2i(x,y - yled)) == Block::Bomb())
			{
				if(Map::getBlock(sf::Vector2i(x,y - yled + 1)) == Block::BombMiddle())
					break;	
				Map::update(sf::Vector2i(x,y - yled + 1),Block::BombUp1());
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == Block::Box())
			{
				Map::update(sf::Vector2i(x,y - yled),Block::BombUp2());
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == Block::Ground())
			{
				Map::update(sf::Vector2i(x,y - yled),Block::BombUpMid());
				if(yled == range)
					Map::update(sf::Vector2i(x,y - yled),Block::BombUp1());
			}
		}
		for(int yled = 1; yled < range+1; yled ++)
		{
			if(Map::getBlock(sf::Vector2i(x,y + yled)) == Block::Wall() || Map::getBlock(sf::Vector2i(x,y + yled)) == Block::PowerUp1() || Map::getBlock(sf::Vector2i(x,y + yled)) == Block::PowerUp2() || Map::getBlock(sf::Vector2i(x,y + yled)) == Block::Bomb())
			{
				if(Map::getBlock(sf::Vector2i(x,y + yled - 1)) == Block::BombMiddle())
					break;	
				else
					Map::update(sf::Vector2i(x,y + yled - 1),Block::BombDown1());
			}	
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == Block::Box())
			{
				Map::update(sf::Vector2i(x,y + yled),Block::BombDown2());
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == Block::Ground())
			{
				Map::update(sf::Vector2i(x,y + yled),Block::BombDownMid());
				if(yled == range)
					Map::update(sf::Vector2i(x,y + yled),Block::BombDown1());
			}
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			if(Map::getBlock(sf::Vector2i(x - xled,y)) == Block::Wall() || Map::getBlock(sf::Vector2i(x-xled,y)) == Block::PowerUp1() || Map::getBlock(sf::Vector2i(x-xled,y)) == Block::PowerUp2() || Map::getBlock(sf::Vector2i(x-xled,y)) == Block::Bomb())
			{
				if(Map::getBlock(sf::Vector2i(x - xled + 1,y)) == Block::BombMiddle())
					break;	
				else
					Map::update(sf::Vector2i(x - xled + 1,y),Block::BombLeft1());
			}	
			else if(Map::getBlock(sf::Vector2i(x - xled,y)) == Block::Box())
			{
				Map::update(sf::Vector2i(x - xled,y),Block::BombLeft2());
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x - xled,y)) == Block::Ground())
			{
				Map::update(sf::Vector2i(x - xled,y),Block::BombLeftMid());
				if(xled == range)
					Map::update(sf::Vector2i(x - xled,y),Block::BombLeft1());
			}
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			if(Map::getBlock(sf::Vector2i(x + xled,y)) == Block::Wall() || Map::getBlock(sf::Vector2i(x+xled,y)) == Block::PowerUp1() || Map::getBlock(sf::Vector2i(x+xled,y)) == Block::PowerUp2() || Map::getBlock(sf::Vector2i(x+xled,y)) == Block::Bomb())
			{
				if(Map::getBlock(sf::Vector2i(x + xled - 1,y)) == Block::BombMiddle())
					break;	
				else
					Map::update(sf::Vector2i(x + xled - 1,y),Block::BombRight1());
			}
			else if(Map::getBlock(sf::Vector2i(x + xled,y)) == Block::Box())
			{
				Map::update(sf::Vector2i(x + xled,y),Block::BombRight2());
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x + xled,y)) == Block::Ground())
			{
				Map::update(sf::Vector2i(x + xled,y),Block::BombRightMid());
				if(xled == range)
					Map::update(sf::Vector2i(x + xled,y),Block::BombRight1());
			}
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
			if(Map::getBlock(sf::Vector2i(x,y - yled)) == Block::Wall())
				break;	
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == Block::Box())
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == Block::BombUp1() ||
				Map::getBlock(sf::Vector2i(x,y - yled)) == Block::BombUpMid())
			{
				Map::update(sf::Vector2i(x,y - yled),Block::Ground());	// test 2,1
			}
			else if(Map::getBlock(sf::Vector2i(x,y - yled)) == Block::BombUp2())
			{
				if(b==1)
					Map::update(sf::Vector2i(x,y - yled),Block::PowerUp1());	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x,y - yled),Block::PowerUp2());	// test 2,1
				else
					Map::update(sf::Vector2i(x,y - yled),Block::Ground());	// test 2,1
			}
		}
		for(int yled = 1; yled < range+1; yled ++)
		{
			b = rand() % droprate;
			if(Map::getBlock(sf::Vector2i(x,y + yled)) == Block::Wall())
				break;	
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == Block::Box())
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == Block::BombDown1() ||
				Map::getBlock(sf::Vector2i(x,y + yled)) == Block::BombDownMid())
			{
				Map::update(sf::Vector2i(x,y + yled),Block::Ground());
			}
			else if(Map::getBlock(sf::Vector2i(x,y + yled)) == Block::BombDown2())
			{
				if(b==1)
					Map::update(sf::Vector2i(x,y + yled),Block::PowerUp1());	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x,y + yled),Block::PowerUp2());	// test 2,1
				else
					Map::update(sf::Vector2i(x,y + yled),Block::Ground());	// test 2,1
			}
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			b = rand() % droprate;
			if(Map::getBlock(sf::Vector2i(x - xled ,y)) == Block::Wall())
				break;	
			else if(Map::getBlock(sf::Vector2i(x - xled ,y)) == Block::Box())
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x - xled ,y)) == Block::BombLeft1() ||
				Map::getBlock(sf::Vector2i(x - xled ,y)) == Block::BombLeftMid())
			{
				Map::update(sf::Vector2i(x - xled ,y),Block::Ground());
			}
			else if(Map::getBlock(sf::Vector2i(x - xled,y)) == Block::BombLeft2())
			{
				if(b==1)
					Map::update(sf::Vector2i(x - xled,y),Block::PowerUp1());	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x - xled,y),Block::PowerUp2());	// test 2,1
				else
					Map::update(sf::Vector2i(x - xled,y),Block::Ground());	// test 2,1
			}
		}
		for(int xled = 1; xled < range+1; xled ++)
		{
			b = rand() % droprate;
			if(Map::getBlock(sf::Vector2i(x + xled ,y)) == Block::Wall())
				break;	
			else if(Map::getBlock(sf::Vector2i(x + xled ,y)) == Block::Box())
			{
				break;
			}
			else if(Map::getBlock(sf::Vector2i(x + xled ,y)) == Block::BombRight1() || 
				Map::getBlock(sf::Vector2i(x + xled ,y)) == Block::BombRightMid())
			{
				Map::update(sf::Vector2i(x + xled ,y),Block::Ground());
			}
			else if(Map::getBlock(sf::Vector2i(x + xled,y)) == Block::BombRight2())
			{
				if(b==1)
					Map::update(sf::Vector2i(x + xled,y),Block::PowerUp1());	// test 2,1
				else if(b==2)
					Map::update(sf::Vector2i(x + xled,y),Block::PowerUp2());	// test 2,1
				else
					Map::update(sf::Vector2i(x + xled,y),Block::Ground());	// test 2,1
			}
		}
		Map::update(sf::Vector2i(x,y),Block::Ground());

		firstRound = false;
	}
	return Exploded;
}

