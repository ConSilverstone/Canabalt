#pragma once

// Library includes
#include <vector>
#include <SFML/Graphics.hpp>

class Animation 
{
public:

	//Constructor
	Animation();

	void Update(sf::Time _frameTime);

	void Play();
	void Pause();
	void Stop();

	bool IsPlaying();

	void AddFrame(sf::Texture& _newFrame);
	void SetSprite(sf::Sprite& _sprite);
	void SetPlayBackSpeed(float _framesPerSecond);
	void SetLoop(bool _loop);

private:

	// Settings
	std::vector<sf::Texture*> m_frames;
	sf::Sprite* m_sprite;
	float m_playBackSpeed;
	bool m_loop;

	// State
	sf::Time m_nextFrameChange;
	int m_currentFrame;
	bool m_playing;
};