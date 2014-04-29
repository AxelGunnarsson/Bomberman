#pragma once
#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Map.h"

class Player
{
private:
	
	enum Direction { Down , Left , Right , Up };
	sf::Vector2i source;
	bool death;
	float speed;
	int boxX,boxx,boxY,boxy,maxAntalBomber,range;
	sf::Keyboard::Key upp,ner,left,right,bom;
	sf::Texture m_texture;
	sf::Vector2f pos;
	sf::Sprite m_sprite;
	sf::VertexArray m_vertices;
	Bomb bombList[20];	
	int antalBomber;

public:


	Player(sf::Vector2f,std::string&,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key,sf::Keyboard::Key);
	~Player(void);
	void Player::update();
	void Player::draw(sf::RenderTarget& tgt);
	int Player::collision(sf::Vector2f);
};

