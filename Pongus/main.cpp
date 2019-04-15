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
	Pad enemyPal(float(windowWidthX)/2, float(windowHeightY) - 550);
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

			if (pilka.getPosition().y > windowHeightY) //bottomFail
			{
				pilka.hitBottom();
			}

			if (pilka.getPosition().x < 0 || pilka.getPosition().x + 10 > windowWidthX) //side bounce
			{
				pilka.sideBounce();
			}
			if (pilka.getPosition().y < 0) //topFail
			{
				pilka.hitBottom();
			}

			//AI movement
			if (pilka.getBallDirection() < 0)
			{
				if ((pilka.getPosition().x + 5) > enemyPal.getPosition().x + 50 )
				{
					enemyPal.moveRight();
				}
				if ((pilka.getPosition().x + 5) < enemyPal.getPosition().x + 50)
				{
					enemyPal.moveLeft();
				}
			}
			else if ((enemyPal.getPosition().x + 50) != windowWidthX / 2)
			{
				if (enemyPal.getPosition().x + 50 > windowWidthX / 2)
				{
					enemyPal.moveLeft();
				}
				if (enemyPal.getPosition().x + 50 < windowWidthX / 2)
				{
					enemyPal.moveRight();
				}
			}

			//AI takeover
			if (AI_ON && pilka.getBallDirection() > 0)
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
			else if (AI_ON && (paletka.getPosition().x +50) != windowWidthX /2)
			{
				if (paletka.getPosition().x + 50 > windowWidthX / 2)
				{
					paletka.moveLeft();
				}
				if (paletka.getPosition().x + 50 < windowWidthX / 2)
				{
					paletka.moveRight();
				}
			}


			if ((pilka.getPosition().y + 10) > paletka.getPosition().y) //hit the pad
			{
				if (pilka.getPosition().x + 10 > paletka.getPosition().x && pilka.getPosition().x < paletka.getPosition().x + 100)
				{		
					pilka.padBounce((pilka.getPosition().x + 5) - (paletka.getPosition().x + 50));
					pilka.boostSpeed();
				}
			}
			if (pilka.getPosition().y < enemyPal.getPosition().y) //hit the enemy pad
			{
				if (pilka.getPosition().x + 10 > enemyPal.getPosition().x && pilka.getPosition().x < enemyPal.getPosition().x + 100)
				{

					pilka.padBounce((pilka.getPosition().x + 5) - (enemyPal.getPosition().x + 50));
					
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

			if (enemyPal.getPosition().x < 0)
			{
				enemyPal.moveRight();
			}
			if (enemyPal.getPosition().x + 95 > windowWidthX)
			{
				enemyPal.moveLeft();
			}

			enemyPal.updatePosition();
			paletka.updatePosition();
			pilka.updatePosition();

		}
		//Render
		gameWindow.clear();
		gameWindow.draw(paletka.getShape());
		gameWindow.draw(enemyPal.getShape());
		gameWindow.draw(pilka.getShape());
		gameWindow.display();

		accumulator += timer.restart();
	}
}

