#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "ball.h"
#include "pad.h"

#define AI_ON true

int main()
{
	sf::Clock timer;
	sf::Time accumulator = sf::Time::Zero;
	sf::Time ups = sf::seconds(1.f / 60.f);

	int windowWidthX = 400;
	int windowHeightY = 600;

	Pad paletka(float(windowWidthX)/2, float(windowHeightY) - 50);
	Pad AIpal(float(windowWidthX)/2, float(windowHeightY) - 550);
	Ball pilka(float(windowWidthX) / 2, float(windowHeightY) /2);
	//Mein Loop
	sf::RenderWindow gameWindow(sf::VideoMode(windowWidthX, windowHeightY), "Classicus Pongus");
	while (gameWindow.isOpen())
	{
		//Event handler
		sf::Event action;
		while (gameWindow.pollEvent(action))
		{
			if (action.type == sf::Event::Closed)
				gameWindow.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				pilka.boostSpeed();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				gameWindow.close();

		}
		
		while (accumulator > ups)
		{
			accumulator -= ups;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				paletka.moveLeft();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				paletka.moveRight();
			}

			//Logic

			if (pilka.getPosition().y > windowHeightY) //bottomaut
			{
				pilka.hitBottom();
			}

			if (pilka.getPosition().x < 0 || pilka.getPosition().x + 10 > windowWidthX) //side bounce
			{
				pilka.sideBounce();
			}
			if (pilka.getPosition().y < 0) //topaut
			{
				pilka.hitBottom();
			}

			//AI movement
			if (pilka.getBallDirection() < 0.f)
			{
				if ((pilka.getPosition().x + 5) > AIpal.getPosition().x + 50 )
				{
					AIpal.moveRight();
				}
				if ((pilka.getPosition().x + 5) < AIpal.getPosition().x + 50)
				{
					AIpal.moveLeft();
				}
			}

			//AI takeover
			if (AI_ON && pilka.getBallDirection() > 0.f)
			{
				if ((pilka.getPosition().x + 5) > paletka.getPosition().x + 50)
				{
					paletka.moveRight();
				}
				if ((pilka.getPosition().x + 5) < paletka.getPosition().x + 50)
				{
					paletka.moveLeft();
				}
			}
			else if (AI_ON && paletka.getPosition().x != windowWidthX /2)
			{

			}


			if ((pilka.getPosition().y + 10) > paletka.getPosition().y) //hit the pad
			{
				if (pilka.getPosition().x + 10 > paletka.getPosition().x && pilka.getPosition().x < paletka.getPosition().x + 100)
				{		
					pilka.padBounce();
					pilka.boostSpeed();
				}
			}
			if (pilka.getPosition().y < AIpal.getPosition().y) //hit the AIpad
			{
				if (pilka.getPosition().x + 10 > AIpal.getPosition().x && pilka.getPosition().x < AIpal.getPosition().x + 100)
				{

					pilka.padBounce();
					pilka.boostSpeed();
				}
			}
			if (paletka.getPosition().x < 0)
			{
				paletka.moveRight();
			}
			if (paletka.getPosition().x + 95 > windowWidthX)
			{
				paletka.moveLeft();
			}

			if (AIpal.getPosition().x < 0)
			{
				AIpal.moveRight();
			}
			if (AIpal.getPosition().x + 95 > windowWidthX)
			{
				AIpal.moveLeft();
			}

			AIpal.updatePosition();
			paletka.updatePosition();
			pilka.updatePosition();

		}
		//Render
		gameWindow.clear();
		gameWindow.draw(paletka.getShape());
		gameWindow.draw(AIpal.getShape());
		gameWindow.draw(pilka.getShape());
		gameWindow.display();

		accumulator += timer.restart();
	}
}

