#pragma once
#include "SFML/Graphics.hpp"

class Ball
{
	sf::Vector2f ballPosition;
	sf::RectangleShape ballBody;
	float xspeed = 1.5f;
	float yspeed = 1.5f;
	int xDir;
	int yDir;
public:
	Ball(float, float);
	sf::Vector2f getPosition();
	sf::RectangleShape getShape();
	float getVelocityX();
	float getBallDirection();

	void boostSpeed();
	void sideBounce();
	void padBounce();
	void hitBottom();
	void updatePosition();

};