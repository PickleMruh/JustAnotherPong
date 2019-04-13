#include "ball.h"

Ball::Ball(float startX, float startY)
	:xDir(1), yDir(1)
{
	ballPosition.x = startX;
	ballPosition.y = startY;

	ballBody.setSize(sf::Vector2f(10, 10));
	ballBody.setPosition(ballPosition);
}

sf::Vector2f Ball::getPosition()
{
	return ballPosition;
}

sf::RectangleShape Ball::getShape()
{
	return ballBody;
}

float Ball::getVelocityX()
{
	return xspeed;
}

int Ball::getBallDirection()
{
	return yDir;
}

void Ball::boostSpeed()
{
	xspeed = xspeed + 0.5f;
	yspeed = yspeed + 0.5f;
}

void Ball::sideBounce()
{
	xDir = xDir * -1;
}

void Ball::padBounce()
{
	yDir = yDir * -1;
}

void Ball::hitBottom()
{
	ballPosition.y = 300;
	ballPosition.x = 200;
	xspeed = 1.5f;
	yspeed = 1.5f;
	yDir = 1;
}

void Ball::updatePosition()
{
	ballPosition.x += xDir * xspeed;
	ballPosition.y += yDir * yspeed;

	ballBody.setPosition(ballPosition);
}
