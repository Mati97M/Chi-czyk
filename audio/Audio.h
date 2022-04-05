#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>
#include <string>

class Audio
{
	std::string source;
	sf::SoundBuffer sound_buffer;
	sf::Sound sound;

	int create_sound(std::string source)
	{

		if (!sound_buffer.loadFromFile(source))
		{
			std::cout << "While loading a sound_buffer, problem has appeared." << std::endl;
			return 0;
		} 
		std::cout<<"Sound loaded seuccesfully"<<std::endl;
		sound.setBuffer(sound_buffer);
		return 1;
	}
public:
	void play()  { sound.play(); }
	friend class Game_surface;
	friend class Dice;
};

#endif 

