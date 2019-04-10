#include <SFML/Graphics.hpp>
#include <cmath>
#include "ball.h"
#include "pad.h"

int main()
{
	int windowWidthX = 400;
	int windowHeightY = 600; 
	Pad paletka(float(windowWidthX)/2, float(windowHeightY) - 100);
	Ball pilka(float(windowWidthX) / 2, float(windowHeightY) /2);
	sf::RenderWindow gameWindow(sf::VideoMode(windowWidthX, windowHeightY), "Classicus Pongus");
	while (gameWindow.isOpen())
	{
		//Event handler
		sf::Event action;
		while (gameWindow.pollEvent(action))
		{
			if (action.type == sf::Event::Closed)
				gameWindow.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				paletka.moveLeft();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				paletka.moveRight();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				gameWindow.close();

		}
		//Logic

		if (pilka.getPosition().top > windowHeightY)
			pilka.hitBottom();
		
		if (pilka.getPosition().left < 0 || pilka.getPosition().left + 10 > windowWidthX)
			pilka.sideBounce();

		if (pilka.getPosition().top < 0)
			pilka.padBounce();

		if (pilka.getPosition().intersects(paletka.getPosition()))
			pilka.padBounce();

		if (paletka.getPosition().left < 0)
			paletka.moveRight();
		if (paletka.getPosition().left + 100 > windowWidthX)
			paletka.moveLeft();

		paletka.updatePosition();
		pilka.updatePosition();

		//Render
		gameWindow.clear();
		gameWindow.draw(paletka.getShape());
		gameWindow.draw(pilka.getShape());
		gameWindow.display();
	}
}
