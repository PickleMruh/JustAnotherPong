#pragma once
#include <SFML/Graphics.hpp>

class Pad
{
	sf::Vector2f padPosition; 
	sf::RectangleShape padBody;
	float padSpeed = 10.0f;
	float xDir = 1;
public:
	Pad(float, float);
	sf::Vector2f getPosition();
	sf::RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void updatePosition();
};