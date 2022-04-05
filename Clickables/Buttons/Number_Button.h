#ifndef NUMBER_BUTTON_H
#define NUMBER_BUTTON_H

#include <iostream>
#include <string>
#include "Button.h"


class Number_Button: public Button
{
	Number_Button(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered) : Button(name,x, y, w, h, normal, hoovered)
		{	
			std::cout << "creating a number button" << std::endl; 

		}

	void OnClick();
	~Number_Button() { 
		std::cout << __func__ << std::endl;
	}

	friend class Menu;
	friend class Game_surface;
};
#endif 