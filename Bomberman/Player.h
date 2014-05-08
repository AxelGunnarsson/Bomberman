#pragma once
#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Map.h"
#include "Block.h"

class Player
{
private:
	
	enum Direction { Down , Left , Right , Up };
	enum Walk { AllowedToWalk , NotAllowedToWalk, PowerUp1, PowerUp2 }; 
	sf::Vector2i animationPos;

	float speed;
	int boxX,boxx,boxY,boxy,maxAntalBomber,range, antalBomber;
	sf::Keyboard::Key up,down,left,right,placeBomb;
	sf::Texture m_texture;
	sf::Vector2f pos;
	sf::Sprite m_sprite;
	Bomb bombList[20];	


public:
	bool Alive;
	Player(sf::Vector2f,std::string&,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key);
	~Player(void);
	void Player::update();
	void Player::draw(sf::RenderTarget& tgt);
	int Player::collision(sf::Vector2f);
	sf::Vector2i Player::getPos();
};

