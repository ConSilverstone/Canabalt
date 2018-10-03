#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Player.h"

int main()
{
	//////////////
	// Game Setup

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack A Critter!",
		sf::Style::Titlebar | sf::Style::Close);

	//Time tracker in game
	sf::Clock gameClock;

	//Create AssetManager
	AssetManager assets;

	// Create player
	Player myPlayer;
	myPlayer.Spawn();

	//Testing AssetManager
	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));
	
	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	testSound.play();
	
	sf::Text testText;
	testText.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	testText.setString("Test text.");

	// end game setup
	/////////////////


	/////////////
	// Game loop
	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// Pass input to game objects
			myPlayer.Input(event);

			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			} // End if (closed)
		}
		gameWindow.clear();

		// -------
		// Update
		sf::Time frameTime = gameClock.restart();

		// Process all game objects
		myPlayer.Update(frameTime);

		// end update
		// ----------

		///////////////////
		// Draw Everything


		// Clear window to a single color
		gameWindow.clear();

		// Draw everything
		myPlayer.Draw(gameWindow);

		// Display game contents
		gameWindow.display();

		// end draw
		////////////
	}
	// end game loop
	/////////////////

	return 0;
}
