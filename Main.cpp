#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Animation.h"
#include "AnimationSystem.h"

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

	//Testing AssetManager
	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));
	
	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	testSound.play();
	
	sf::Text testText;
	testText.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	testText.setString("Test text.");

	// Animation Testing Section
	AnimationSystem testAnimationSystem;
	testAnimationSystem.SetSprite(testSprite);

	Animation& testAnimation = testAnimationSystem.CreateAnimation("run");
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/PlayerRun1.png"));
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/PlayerRun2.png"));
	testAnimation.SetLoop(true);
	testAnimation.SetPlayBackSpeed(10.0f);

	Animation& jumpAnimation = testAnimationSystem.CreateAnimation("jump");
	jumpAnimation.AddFrame(AssetManager::GetTexture("graphics/playerJump.png"));

	testAnimationSystem.Play("run");

	// end game setup
	/////////////////


	/////////////
	// Game loop
	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		gameWindow.clear();

		// -------
		// Update
		sf::Time frameTime = gameClock.restart();

		// Update our animation
		testAnimationSystem.Update(frameTime);

		// end update
		// ----------

		///////////////////
		// Draw Everything
		gameWindow.draw(testSprite);
		gameWindow.draw(testText);
		gameWindow.display();

		// end draw
		////////////
	}
	// end game loop
	/////////////////

	return 0;
}
