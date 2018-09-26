//Library Includes
#include <assert.h>

//Project Includes
#include "AssetManager.h"

// Initialise the static reference to our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

// Constructor
AssetManager::AssetManager()
	: m_textures ()
	, m_soundBuffer ()
	, m_font ()
{
	// Throw an error and stop execution (in debug mode) if a copy,
	// of this class has already been created
	assert(s_instance == nullptr);

	// Assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created
	s_instance = this;
}

sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	//Create an iterator to hold a key and value pair
	// and search for the required key
	// using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_fileName);
	// "auto" is this case is equivelent to writing 
	//  std::map<std::string,sf::Texture>::iterator
	// the keyword (auto) can be used in cases where the compiler can figure
	// out the type of a variable for you
	// YOU ARE NOT ALLOWED TO USE THIS KEYWORD OUTSIDE OF ITERATORS
	
	// Did we find the texture? (aka was it already loaded?)
	// (iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_textures.end())
	{
		//YES we found it!
		return keyValuePair->second;
	}
	else 
	{
		// NO! We didn't find it!

		// Let's create it then!

		// Create a key value pair using the filename
		// The subscript [] operator creates an entry in the map,
		// if there is not already one there.

		sf::Texture& texture = s_instance->m_textures[_fileName];
		// blank texture has been created
		// Now just load it from file using SFML

		texture.loadFromFile(_fileName);

		//Return the texture to the calling code
		return texture;
	}
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string _fileName)
{
	//Create an iterator to hold a key and value pair
	// and search for the required key
	// using the passed in file name
	auto keyValuePair = s_instance->m_soundBuffer.find(_fileName);
	// "auto" is this case is equivelent to writing 
	//  std::map<std::string,sf::Texture>::iterator
	// the keyword (auto) can be used in cases where the compiler can figure
	// out the type of a variable for you
	// YOU ARE NOT ALLOWED TO USE THIS KEYWORD OUTSIDE OF ITERATORS

	// Did we find the texture? (aka was it already loaded?)
	// (iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_soundBuffer.end())
	{
		//YES we found it!
		return keyValuePair->second;
	}
	else
	{
		// NO! We didn't find it!

		// Let's create it then!

		// Create a key value pair using the filename
		// The subscript [] operator creates an entry in the map,
		// if there is not already one there.

		sf::SoundBuffer& soundBuffer = s_instance->m_soundBuffer[_fileName];
		// blank texture has been created
		// Now just load it from file using SFML

		soundBuffer.loadFromFile(_fileName);

		//Return the texture to the calling code
		return soundBuffer;
	}
}