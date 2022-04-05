#ifndef DICE_H
#define DICE_H


#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Button.h"
#include "../../../audio/Audio.h"
#include "../../../Game_surface/Board.h"


class Dice: public Button		
{
	friend class Board;
	friend class Animation;

	unsigned result;
	//wizualizacja i dzwiek
	using vector_of_textures = std::vector<sf::Texture>;
	vector_of_textures result_textures;	// [0 - 5]
	vector_of_textures passing_time_textures;	// tekstury do animacji, klepsydra z piaskiem
	
	Audio dice_rolling_sound;
	unsigned last_PT_texture;
	////
	
	Dice(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered);
	
	//void set_dice_textures(std::string one, std::string two, std::string three, std::string four, std::string five, std::string six) {}
//	void set_passing_time_textures(std::string phase_one, std::string phase_two, std::string phase_three, std::string phase_four, std::string phase_five, std::string phase_six) {}
	
	public:
		unsigned get_the_result() { return result; }
		void OnClick();

private:
	void set_result();
	void set_result_texture();
	bool next_PT_texture();
};

#endif // !DICE_H