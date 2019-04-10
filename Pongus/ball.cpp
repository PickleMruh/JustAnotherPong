#include "ball.h"

Ball::Ball(float startX, float startY)
{
	ballPosition.x = startX;
	ballPosition.y = startY;

	ballBody.setSize(sf::Vector2f(10, 10));
	ballBody.setPosition(ballPosition);
}

sf::FloatRect Ball::getPosition()
{
	return ballBody.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return ballBody;
}

float Ball::getVelocityX()
{
	return xspeed;
}

void Ball::sideBounce()
{
	xspeed = xspeed * -1;
}

void Ball::padBounce()
{
	ballPosition.y -= (yspeed * 30);
	yspeed = yspeed * -1;
}

void Ball::hitBottom()
{
	ballPosition.y = 200;
	ballPosition.x = 200;
}

void Ball::updatePosition()
{
	ballPosition.x += xspeed;
	ballPosition.y += yspeed;

	ballBody.setPosition(ballPosition);
}
