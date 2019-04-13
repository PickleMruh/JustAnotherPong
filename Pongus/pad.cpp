#include "pad.h"

Pad::Pad(float startX, float startY)
{
	padPosition.x = startX;
	padPosition.y = startY;

	padBody.setSize(sf::Vector2f(100, 10));
	padBody.setPosition(padPosition);
}

sf::Vector2f Pad::getPosition()
{
	return padPosition;
}

sf::RectangleShape Pad::getShape()
{
	return padBody;
}

void Pad::moveLeft()
{
	padPosition.x -= padSpeed * xDir;
}

void Pad::moveRight()
{
	padPosition.x += padSpeed * xDir;
}

void Pad::updatePosition()
{
	padBody.setPosition(padPosition);
}
