#pragma once
#include "SFML/Graphics.hpp"

class Ball
{
	sf::Vector2f ballPosition;
	sf::RectangleShape ballBody;
	float xspeed = 0.3f;
	float yspeed = 0.3f;
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