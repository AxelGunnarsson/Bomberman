#include "stdafx.h"
#include "Player.h"


Player::Player(sf::Vector2f position, std::string& bild, sf::Keyboard::Key uppK,sf::Keyboard::Key nerK,sf::Keyboard::Key leftK,sf::Keyboard::Key rightK,sf::Keyboard::Key bombK)	// Bomb - Exlopde - Position om block sprängs / Player dör
{
	upp = uppK;
	ner = nerK;
	left = leftK;
	right = rightK;
	bom = bombK;
	antalBomber=0;
	maxAntalBomber=1;
	death = false;
	range = 2;
	pos = position;
	source = sf::Vector2i(0,Down);
	speed = 2;
	boxX = 22;
	boxx = 11;
	boxY = 22;
	boxy = 11;
	m_texture.loadFromFile(bild);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(pos.x,pos.y);
}	

Player::~Player(void)
{
}

void Player::update() 
{
	if(Map::getBlock(sf::Vector2i(((int)pos.x+15)/30,((int)pos.y+15)/30)) != sf::Vector2i(1,1) && Map::getBlock(sf::Vector2i(((int)pos.x+15)/30,((int)pos.y+15)/30)) != sf::Vector2i(0,1))
	{
		death=true;
	}

	if(sf::Keyboard::isKeyPressed(right) && death != true)
	{
		source.y = Right;
		if(!collision(sf::Vector2f(pos.x + 28,pos.y + 12 )) && !collision(sf::Vector2f(pos.x + 22,pos.y + 21 )))
			pos.x += speed;
		else if (collision(sf::Vector2f(pos.x + 33,pos.y + boxy )) == 2 && collision(sf::Vector2f(pos.x + 33 ,pos.y + boxY)) == 2 )
		{
			Map::update(sf::Vector2i(((int)pos.x + 35 ) / 30, ((int)pos.y+10) / 30),sf::Vector2i(1,1));
			range+=1;
			pos.x += speed;
		}
		else if (collision(sf::Vector2f(pos.x + 34,pos.y + boxy )) == 3 && collision(sf::Vector2f(pos.x + 34 ,pos.y + boxY)) == 3 )
		{
			Map::update(sf::Vector2i(((int)pos.x + 35 ) / 30, ((int)pos.y+10) / 30),sf::Vector2i(1,1));
			maxAntalBomber+=1;
			pos.x += speed;
		}
		source.x+=1;
	}
	if(sf::Keyboard::isKeyPressed(left) && death != true)
	{
		source.y = Left;
		if(!collision(sf::Vector2f(pos.x + 8,pos.y + 12 )) && !collision(sf::Vector2f(pos.x + 11,pos.y + 21)))
			pos.x -= speed;
		else if (collision(sf::Vector2f(pos.x - 2,pos.y + boxy )) == 2 && collision(sf::Vector2f(pos.x - 2 ,pos.y + boxY)) == 2 )
		{
			Map::update(sf::Vector2i(((int)pos.x - 2) / 30, ((int)pos.y+10) / 30),sf::Vector2i(1,1));
			range+=1;
			pos.x -= speed;
		}
		else if (collision(sf::Vector2f(pos.x - 2,pos.y + boxy )) == 3 && collision(sf::Vector2f(pos.x - 2 ,pos.y + boxY)) == 3 )
		{
			Map::update(sf::Vector2i(((int)pos.x - 2) / 30, ((int)pos.y+10) / 30),sf::Vector2i(1,1));
			maxAntalBomber+=1;
			pos.x -= speed;
		}
		source.x+=1;
	}
	if(sf::Keyboard::isKeyPressed(upp) && death != true)
	{
		source.y = Up;
		if(!collision(sf::Vector2f(pos.x + 12,pos.y + 8 )) && !collision(sf::Vector2f(pos.x + 21,pos.y + 11)))
			pos.y -= speed;
		else if (collision(sf::Vector2f(pos.x + boxx,pos.y - 4 )) == 2 && collision(sf::Vector2f(pos.x + boxX - 1,pos.y - 4)) == 2 )
		{
			Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y - 4) / 30),sf::Vector2i(1,1));
			range+=1;
			pos.y -= speed;
		}
		else if (collision(sf::Vector2f(pos.x + boxx,pos.y - 4 )) == 3 && collision(sf::Vector2f(pos.x + boxX - 1,pos.y - 4)) == 3 )
		{
			Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y - 4) / 30),sf::Vector2i(1,1));
			maxAntalBomber+=1;
			pos.y -= speed;
		}
		source.x+=1;
	}

	if(sf::Keyboard::isKeyPressed(ner) && death != true)
	{
		source.y = Down;
		if(!collision(sf::Vector2f(pos.x + 12,pos.y + 30)) && !collision(sf::Vector2f(pos.x + 21,pos.y + 30)))
			pos.y += speed;
		else if (collision(sf::Vector2f(pos.x + boxx,pos.y + 34 )) == 2 && collision(sf::Vector2f(pos.x + boxX,pos.y + 34 )) == 2 )
		{
			Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y+30) / 30),sf::Vector2i(1,1));
			range+=1;
			pos.y += speed;
		}
		else if (collision(sf::Vector2f(pos.x + boxx,pos.y + 34 )) == 3 && collision(sf::Vector2f(pos.x + boxX,pos.y + 34 )) == 3 )
		{
			Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y+34) / 30),sf::Vector2i(1,1));			
			maxAntalBomber+=1;
			pos.y += speed;
		}
		source.x+=1;
	}

	if(sf::Keyboard::isKeyPressed(bom) && death != true)
	{
		if(antalBomber < maxAntalBomber && Map::getBlock(sf::Vector2i(((int)pos.x + 15)/30,((int)pos.y + 15)/30)) != sf::Vector2i(0,1))
		{
			bombList[antalBomber] = Bomb(sf::Vector2i(((int)pos.x + 15) / 30,((int)pos.y + 15) /30),range);
			antalBomber+=1;
		}
	}

	if(!sf::Keyboard::isKeyPressed(bom) && !sf::Keyboard::isKeyPressed(left) && !sf::Keyboard::isKeyPressed(right) && !sf::Keyboard::isKeyPressed(upp) && !sf::Keyboard::isKeyPressed(ner))
	{
		source.x = 6;
	}


	if(source.x >= 12)
		source.x = 0;

	m_sprite.setTextureRect(sf::IntRect((source.x / 6) * 32, source.y * 32,32,32));
	m_sprite.setPosition(pos.x,pos.y);
}

int Player::collision(sf::Vector2f Pos)
{
	sf::Vector2i pos = sf::Vector2i((int)Pos.x / 30, (int)Pos.y / 30);

	if(Map::getBlock(pos) == sf::Vector2i(1,1))
		return 0;
	else if(Map::getBlock(pos) == sf::Vector2i(0,1))
		return 0;
	else if(Map::getBlock(pos) == sf::Vector2i(2,1))
		return 0;
	else if(Map::getBlock(pos) == sf::Vector2i(2,0))
		return 2;
	else if(Map::getBlock(pos) == sf::Vector2i(2,2))
		return 3;
	return 1;

}

void Player::draw(sf::RenderTarget& tgt) 
{
	tgt.draw(m_sprite);
	for(int i = 0 ; i < antalBomber; i++)
		{	
			bombList[i].draw(tgt);
			if(bombList[i].exploded() == true)
			{
				antalBomber --;
				for(int d = i; d < antalBomber; d++)
				{
					bombList[d] = bombList[d+1];
				}
			}
		}
}
