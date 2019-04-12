#pragma once
#include "SFML/Graphics.hpp"

class Ball
{
	sf::Vector2f ballPosition;
	sf::RectangleShape ballBody;
	float xspeed = 1.2f;
	float yspeed = 1.2f;
	int xDir;
	int yDir;
public:
	Ball(float, float);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	float getVelocityX();

	void boostSpeed();
	void sideBounce();
	void padBounce();
	void hitBottom();
	void updatePosition();

};