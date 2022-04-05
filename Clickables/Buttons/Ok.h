#ifndef OK_H
#define OK_H

#include <iostream>
#include <string>
#include "Button.h"

class Ok: public Button		//zamyka menu na zdarzenie onclick
{
	Ok(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered): Button(name, x, y, w, h, normal, hoovered)
	{
		std::cout << "creating a Ok button" << std::endl;
	}
	void OnClick();
	~Ok() { std::cout << __func__ << std::endl; }


	friend class Menu;	
	friend class Game_surface;	//add_button i konstruktor Ok
};
#endif 