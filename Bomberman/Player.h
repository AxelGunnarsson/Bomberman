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
	bool onBombOnce;
	int bombCollisionCounter;
	sf::Texture m_texture;
	float speed;
	int boxX,boxx,boxY,boxy,maxAntalBomber,range, antalBomber;
	sf::Keyboard::Key up,down,left,right,placeBomb;
	sf::Vector2f pos;
	sf::Vector2f staticPos;
	sf::Sprite m_sprite;
	sf::Texture death_texture;
	sf::Sprite death_sprite;
	Bomb bombList[20];	


public:
	bool Alive;
	Player();
	Player(sf::Vector2f,sf::Vector2f,std::string&,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key);
	~Player(void);
	void Player::update();
	void Player::draw(sf::RenderTarget& tgt);
	int Player::collision(sf::Vector2f);
	sf::Vector2f Player::getPos();
	sf::Vector2f Player::getStaticPos();
	sf::Sprite Player::getSprite();
	sf::IntRect Player::getTextureRect();
};

