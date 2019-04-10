#include <SFML/Graphics.hpp>
#include <cmath>
#include "ball.h"
#include "pad.h"

int main()
{
	float windowWidthX = 400.f;
	float windowHeightY = 600.f; 
	Pad paletka(windowWidthX/2, windowHeightY - 100.f);
	Ball pilka(windowWidthX / 2, windowHeightY /2);
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

		paletka.updatePosition();
		pilka.updatePosition();

		//Render
		gameWindow.clear();
		gameWindow.draw(paletka.getShape());
		gameWindow.draw(pilka.getShape());
		gameWindow.display();
	}
}
