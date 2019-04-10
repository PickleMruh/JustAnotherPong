#pragma once
#include "SFML/Graphics.hpp"

class Ball
{
	sf::Vector2f ballPosition;
	sf::RectangleShape ballBody;
	float xspeed = 0.3f;
	float yspeed = 0.3f;
public:
	Ball(float, float);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	float getVelocityX();

	void sideBounce();
	void padBounce();
	void hitBottom();
	void updatePosition();

};