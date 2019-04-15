#include <stdlib.h>
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

float Ball::getVelocityY()
{
	return yspeed;
}

int Ball::getBallDirection()
{
	return yDir;
}

int Ball::getBallDirectionX()
{
	return xDir;
}

void Ball::boostSpeed()
{
	xspeed = xspeed + (float((rand()% 15 + 1)) / 10);
	yspeed = yspeed + (float((rand()% 15 + 1)) / 10);
}

void Ball::sideBounce()
{
	xDir = xDir * -1;
}

void Ball::padBounce(float value)
{
	float angle = value * float(xDir);
	if (angle <= -40.0f)
	{
		xspeed *= 0.4f;
	}
	else if (angle > -40.0f && angle < -20.0f )
	{
		xspeed *= 0.6f;
	}
	else if (angle >= -20.0f && angle < -5.0f)
	{
		xspeed *= 0.8f;
	}
	else if (angle >= -5.0f && angle <= 5.0f)
	{
		xspeed *= 1.0f;
	}
	else if (angle > 5.0f && angle < 20.0f)
	{
		xspeed *= 1.2f;
	}
	else if (angle >= 20.0f && angle < 40.0f)
	{
		xspeed *= 1.4f;
	}
	else if (angle >= 40.0f)
	{
		xspeed *= 1.6f;
	}
	yDir = yDir * -1;
}

void Ball::hitBottom()
{
	ballPosition.y = 300;
	ballPosition.x = 200;
	xspeed = 1.5f;
	yspeed = 1.5f;
	
}

void Ball::updatePosition()
{
	ballPosition.x += xDir * xspeed;
	ballPosition.y += yDir * yspeed;

	ballBody.setPosition(ballPosition);
}
