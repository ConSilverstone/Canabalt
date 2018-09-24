#include <SFML/Graphics.hpp>

#include "AssetManager.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Canabalt");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock gameClock;

	//Create AssetManager
	AssetManager assets;


	//Testing AssetManager
	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		// Draw Everything
		window.draw(testSprite);

		window.draw(shape);
		window.display();
	}

	return 0;
}
