#include "stdafx.h"
#include "Player.h"

Player::Player(){};

Player::Player(sf::Vector2f position, std::string& bild, sf::Keyboard::Key uppK,sf::Keyboard::Key nerK,sf::Keyboard::Key leftK,sf::Keyboard::Key rightK,sf::Keyboard::Key bombK)	// Bomb - Exlopde - Position om block sprängs / Player dör
{
	up = uppK;
	down = nerK;
	left = leftK;
	right = rightK;
	placeBomb = bombK;
	antalBomber = 0;
	maxAntalBomber = 1;
	Alive = true;
	range = 2;
	pos = position;
	staticPos = position;
	animationPos = sf::Vector2i(0,Down);
	speed = 2;
	boxX = 22;
	boxx = 11;
	boxY = 22;
	boxy = 11;

	m_texture.loadFromFile(bild);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(pos.x,pos.y);

	death_texture.loadFromFile("Death.png");
	death_sprite.setTexture(death_texture);
	death_sprite.setPosition(staticPos.x - 180, staticPos.y - 150);
}	

Player::~Player(void)
{
}

void Player::update() 
{
	if(Alive)
	{
		if(Map::getBlock(sf::Vector2i(((int)pos.x+15)/30,((int)pos.y+15)/30)) != Block::Ground() &&
			Map::getBlock(sf::Vector2i(((int)pos.x+15)/30,((int)pos.y+15)/30)) != Block::Bomb())
		{
			Alive=false;
		}

		if(sf::Keyboard::isKeyPressed(right))
		{
			animationPos.y = Right;
			if(!collision(sf::Vector2f(pos.x + 28,pos.y + 12 )) && !collision(sf::Vector2f(pos.x + 22,pos.y + 21 )))
				pos.x += speed;
			else if (collision(sf::Vector2f(pos.x + 33,pos.y + boxy )) == 2 && collision(sf::Vector2f(pos.x + 33 ,pos.y + boxY)) == 2 )
			{
				Map::update(sf::Vector2i(((int)pos.x + 35 ) / 30, ((int)pos.y+10) / 30),Block::Ground());
				range+=1;
				pos.x += speed;
			}
			else if (collision(sf::Vector2f(pos.x + 33,pos.y + boxy )) == 3 && collision(sf::Vector2f(pos.x + 33 ,pos.y + boxY)) == 3 )
			{
				Map::update(sf::Vector2i(((int)pos.x + 35 ) / 30, ((int)pos.y+10) / 30),Block::Ground());
				maxAntalBomber+=1;
				pos.x += speed;
			}
			animationPos.x+=1;
		}
		if(sf::Keyboard::isKeyPressed(left))
		{
			animationPos.y = Left;
			if(!collision(sf::Vector2f(pos.x + 8,pos.y + 12 )) && !collision(sf::Vector2f(pos.x + 11,pos.y + 21)))
				pos.x -= speed;
			else if (collision(sf::Vector2f(pos.x - 2,pos.y + boxy )) == 2 && collision(sf::Vector2f(pos.x - 2 ,pos.y + boxY)) == 2 )
			{
				Map::update(sf::Vector2i(((int)pos.x - 2) / 30, ((int)pos.y+10) / 30),Block::Ground());
				range+=1;
				pos.x -= speed;
			}
			else if (collision(sf::Vector2f(pos.x - 2,pos.y + boxy )) == 3 && collision(sf::Vector2f(pos.x - 2 ,pos.y + boxY)) == 3 )
			{
				Map::update(sf::Vector2i(((int)pos.x - 2) / 30, ((int)pos.y+10) / 30),Block::Ground());
				maxAntalBomber+=1;
				pos.x -= speed;
			}
			animationPos.x+=1;
		}
		if(sf::Keyboard::isKeyPressed(up))
		{
			animationPos.y = Up;
			if(!collision(sf::Vector2f(pos.x + 12,pos.y + 8 )) && !collision(sf::Vector2f(pos.x + 21,pos.y + 11)))
				pos.y -= speed;
			else if (collision(sf::Vector2f(pos.x + boxx,pos.y - 4 )) == 2 && collision(sf::Vector2f(pos.x + boxX - 1,pos.y - 4)) == 2 )
			{
				Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y - 4) / 30),Block::Ground());
				range+=1;
				pos.y -= speed;
			}
			else if (collision(sf::Vector2f(pos.x + boxx,pos.y - 4 )) == 3 && collision(sf::Vector2f(pos.x + boxX - 1,pos.y - 4)) == 3 )
			{
				Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y - 4) / 30),Block::Ground());
				maxAntalBomber+=1;
				pos.y -= speed;
			}
			animationPos.x+=1;
		}

		if(sf::Keyboard::isKeyPressed(down))
		{
			animationPos.y = Down;
			if(!collision(sf::Vector2f(pos.x + 12,pos.y + 30)) && !collision(sf::Vector2f(pos.x + 21,pos.y + 30)))
				pos.y += speed;
			else if (collision(sf::Vector2f(pos.x + boxx,pos.y + 34 )) == 2 && collision(sf::Vector2f(pos.x + boxX,pos.y + 34 )) == 2 )
			{
				Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y+30) / 30),Block::Ground());
				range+=1;
				pos.y += speed;
			}
			else if (collision(sf::Vector2f(pos.x + boxx,pos.y + 34 )) == 3 && collision(sf::Vector2f(pos.x + boxX,pos.y + 34 )) == 3 )
			{
				Map::update(sf::Vector2i(((int)pos.x + 15) / 30, ((int)pos.y+34) / 30),Block::Ground());			
				maxAntalBomber+=1;
				pos.y += speed;
			}
			animationPos.x+=1;
		}

		if(sf::Keyboard::isKeyPressed(placeBomb))
		{
			if(antalBomber < maxAntalBomber && Map::getBlock(sf::Vector2i(((int)pos.x + 15)/30,((int)pos.y + 15)/30)) != Block::Bomb())
			{
				bombList[antalBomber] = Bomb(sf::Vector2i(((int)pos.x + 15) / 30,((int)pos.y + 15) /30),range);
				antalBomber+=1;
				onBombOnce = true;
				bombCollisionCounter = 0;
			}
		}
	}

	if(!sf::Keyboard::isKeyPressed(placeBomb) && !sf::Keyboard::isKeyPressed(left) && !sf::Keyboard::isKeyPressed(right) && !sf::Keyboard::isKeyPressed(up) && !sf::Keyboard::isKeyPressed(down))
	{
		animationPos.x = 6;
	}


	if(animationPos.x >= 12)
		animationPos.x = 0;
	m_sprite.setTextureRect(sf::IntRect((animationPos.x / 6) * 32, animationPos.y * 32,32,32));
	if(!Alive)
		m_sprite.setTextureRect(sf::IntRect(0,0,0,0));
	m_sprite.setPosition(staticPos.x,staticPos.y);
}

int Player::collision(sf::Vector2f Pos)
{
	sf::Vector2i pos = sf::Vector2i((int)Pos.x / 30, (int)Pos.y / 30);

	if(Map::getBlock(pos) == Block::Ground())
	{
		if( bombCollisionCounter == 20)
			onBombOnce = false;
		bombCollisionCounter++;
		return AllowedToWalk;
	}
	else if(Map::getBlock(pos) == Block::Bomb())
	{
		if(onBombOnce == true)
			return AllowedToWalk;
		else AllowedToWalk;
	}
	else if(Map::getBlock(pos) == Block::PowerUp1())
	{
		if( bombCollisionCounter == 20)
			onBombOnce = false;
		bombCollisionCounter++;
		return PowerUp1;
	}	
	else if(Map::getBlock(pos) == Block::PowerUp2())
	{
		if( bombCollisionCounter == 20)
			onBombOnce = false;
		bombCollisionCounter++;
		return PowerUp2;
	}
	else if(Map::getBlock(pos) == Block::Wall())
	{
		if( bombCollisionCounter == 20)
			onBombOnce = false;
		bombCollisionCounter++;
		return NotAllowedToWalk;
	}
	else if(Map::getBlock(pos) == Block::Box())
	{
		if( bombCollisionCounter == 20)
			onBombOnce = false;
		bombCollisionCounter++;
		return NotAllowedToWalk;
	}
	return NotAllowedToWalk;

}

void Player::draw(sf::RenderTarget& tgt) 
{
	if(Alive)
	{
		tgt.draw(m_sprite);
	}
	else
	{
		tgt.draw(death_sprite);
	}

	for(int Counter = 0 ; Counter < antalBomber; Counter++)
	{	
		bombList[Counter].draw(tgt);
		if(bombList[Counter].exploded() == true)
		{
			antalBomber --;
			for(int d = Counter; d < antalBomber; d++)
			{
				bombList[d] = bombList[d+1];
			}
		}
	}

}

sf::Vector2f Player::getPos()
{
	return pos;
}

sf::Vector2f Player::getStaticPos()
{
	return staticPos;
}

sf::Sprite Player::getSprite()
{
	return m_sprite;
}

sf::IntRect Player::getTextureRect()
{
	return m_sprite.getTextureRect();
}
