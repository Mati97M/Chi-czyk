#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string> 
#include <iostream>


class Game_surface;

class Clickable
{
	friend class Register;
		friend class Menu;
public:
	virtual void OnClick() = 0;
	std::string get_name() { return name; }
	
	void set_hosting_surface(Game_surface* surface);	//moze lepiej zrobic ja protected?
	
	bool is_active() { return active; }
	void toggle_active() { active = (!active); }
	bool is_clicked() { return clicked; }
	void toggle_clicked() { clicked = (!clicked); }
	void draw(sf::RenderWindow* window);
	sf::Vector2f getCoordinates() { return {x,y}; }
	sf::Vector2i getWidth_Height() { return {width,height}; }
	
	Clickable(std::string n, float x, float y,int w,int h): x{x}, y{y}, width{w}, height{h}, active{ false }, clicked{false}, hosting_surface{nullptr}, name{n}
		{
			//std::cout << "creating a clickable" << std::endl;
			sprite.setPosition(x, y);
		}
	virtual ~Clickable()
		{
			//std::cout << __func__ << std::endl;
		}
	protected:
	//wymiary i polozenie
	float  x, y;
	int width, height;
	// na ktorym obiekcie go zakotwiczamy
	Game_surface* hosting_surface;
	//sprajt
	sf::Sprite sprite;
	
	std::string name;
	
	private:
	bool active;	//moze nie byc, jezeli np jest kolej gracza czerwonego, a chcemy kliknac w pionek zielony, albo wyrzucilismy 2 a chcemy isc 3 pola
	bool clicked; 
	void reset() { active = false; clicked = false; }
	void activate() { reset(); active = true; }
	

};
#endif 