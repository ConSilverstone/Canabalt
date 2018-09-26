#include <SFML/Graphics.hpp>

#include "AssetManager.h"
int main()
{
	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack A Critter!",
		sf::Style::Titlebar | sf::Style::Close);

	sf::Clock gameClock;

	//Create AssetManager
	AssetManager assets;


	//Testing AssetManager
	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));
	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/music.ogg"));
	testSound.play();

	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		gameWindow.clear();

		// Draw Everything
		gameWindow.draw(testSprite);
		gameWindow.display();
	}

	return 0;
}
