#pragma once
#include <SFML/Graphics.hpp>

class Pad
{
	sf::Vector2f padPosition; 
	sf::RectangleShape padBody;
	float padSpeed = 15.0f;
public:
	Pad(float, float);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void updatePosition();
};