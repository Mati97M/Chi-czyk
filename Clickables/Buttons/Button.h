#ifndef BUTTON_H
#define BUTTON_H

#include <utility>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "../Clickable.h"

class Button : public Clickable
{

	bool hoovered;
	void toggle_texture();

protected:
	//jakas tekstura i  obrazek
	std::pair<sf::Texture, sf::Texture> textures;	//wyglad zmienia sie w zal od tego, czy myszka jest nad obiektem
	void setAppearence(std::string normal, std::string hoovered);
	

public:
	Button(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered);
	virtual ~Button() {
		// std::cout << __func__ << std::endl; 
	}
	bool is_hoovered() { return hoovered; }
	void toggle_hoovered() { hoovered = (!hoovered); toggle_texture(); }
	
};
#endif