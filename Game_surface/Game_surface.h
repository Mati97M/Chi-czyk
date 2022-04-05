#ifndef GAME_SURFACE_H
#define GAME_SURFACE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include<map>
#include "../Clickables/Buttons/Button.h"
#include <string>
#include "../audio/Audio.h"


class Number_Button;

struct Under_the_cursor {
	Button* what;
	bool hoovering;
	Under_the_cursor(Button* button, bool mouse_over) :what{ button }, hoovering{ mouse_over }{}
	~Under_the_cursor() {};

};
class Game_surface 
{

protected:
	//kursor i obsluga w zal od miejsca
	sf::Cursor cursor;
	bool cursor_Hand;

	std::string hoovered_button;
	Clickable* clicked;

	unsigned WIDTH;
	unsigned HEIGHT;
	sf::RenderWindow* window;

	void set_basic_Appearance(std::string);

	//jakas tekstura i  obrazek
	std::string texture_path;
	sf::Texture texture;
	sf::Sprite sprite;
	std::map<std::string, Button*> buttons;

public:
	//click
	Audio click;
	//
	Game_surface(unsigned w, unsigned h, std::string texture_path, std::string clicking_source = "audio/click.wav");
	virtual ~Game_surface();

	bool pollEvent(sf::Event& event) { return window->pollEvent(event); }
	void display() { window->display(); }
	void close() { window->close(); }
	bool isOpen() { return window->isOpen(); }
	bool create_sound(std::string source) { return click.create_sound(source); }
	//void update();
	const Under_the_cursor& mouse_over_clickable();	//dependes on wheather the clickale object is active
	void set_whats_clicked(Clickable* c) {if(clicked)	clicked->toggle_clicked(); 	clicked = c; }

	virtual void draw() = 0;
	virtual unsigned get_player_count() = 0;
	virtual void set_player_count(unsigned n) = 0;

	virtual void set_num_button(Number_Button* num_b) = 0;

	template <typename T>  T* add_Button(Game_surface* pointer, std::string name, int x, int y, int w, int h, std::string normal, std::string hoovered);
};

template <typename T>
T* Game_surface::add_Button(Game_surface* pointer, std::string name, int x, int y, int w, int h, std::string normal, std::string hoovered)
{
	T* new_button = new T(name, x, y, w, h, normal, hoovered);
	buttons[name] = new_button;
	new_button->set_hosting_surface(pointer);
	std::cout << "New button added" << std::endl;
	return new_button;
}


#endif