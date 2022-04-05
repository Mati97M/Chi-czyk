#ifndef MENU_H
#define MENU_H


#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "Game_surface.h"

#include "../Clickables/Buttons/Number_Button.h"


class Menu final : public Game_surface
{
private:

	//
	unsigned player_count; //liczba graczy
	Number_Button* num_button;			// po to, aby zapamietac jaki klawisz zostal wcisiniety, zeby ciagle byl podstwitlony, az do klikniecia na inny

	sf::Sprite number_image;
	std::map< const char, sf::Texture*> number_textures;

public:
	Menu(unsigned w, unsigned h, std::string texture_path); 
	~Menu() { std::cout << __func__ << std::endl; }

	void set_player_count(unsigned n) { player_count = n; }
	void set_num_button(Number_Button* num_b);
	unsigned get_player_count() { std::cout<<"Number of players: " << player_count << std::endl; return player_count; }
	void draw() override;
	 	
};


#endif 