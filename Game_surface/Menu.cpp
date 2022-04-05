#include "Menu.h"
#include "../Clickables/Buttons/Number_Button.h"
#include "../Clickables/Buttons/Ok.h"

void Menu::draw()
{
	window->clear();
	window->draw(sprite);
	for (const auto& [key, value] : buttons) {
		value->draw(window);
	}
	window->draw(number_image);
}

Menu::Menu(unsigned w, unsigned h, std::string texture_path) : Game_surface(w, h, texture_path), player_count{ 0 }, num_button{ nullptr }
{
	std::cout << __func__ << std::endl;
	sf::Texture* temp = new sf::Texture;
	if (!temp->loadFromFile("images/number_background.png"))
	{
		std::cout << "couldn`t load number_background.png for menu" << std::endl;
	}
	number_textures['0'] = temp;

	temp = new sf::Texture;
	if (!temp->loadFromFile("images/number_background_2.png"))
	{
		std::cout << "couldn`t load number_background_2.png for menu" << std::endl;
	}
	number_textures['2'] = temp;

	temp = new sf::Texture;
	if (!temp->loadFromFile("images/number_background_3.png"))
	{
		std::cout << "couldn`t load number_background_3.png for menu" << std::endl;
	}
	number_textures['3'] = temp;

	temp = new sf::Texture;
	if (!temp->loadFromFile("images/number_background_4.png"))
	{
		std::cout << "couldn`t load number_background_4.png for menu" << std::endl;
	}
	number_textures['4'] = temp;


	number_image.setTexture(*number_textures['0']);
	number_image.setPosition(350.f, 210.f);

	Game_surface::add_Button<Number_Button>(this, "2", 170.f, 300.f, 78, 38, "images/buttons/2/2_button_ciemny.png", "images/buttons/2/2_button_jasny.png");
	Game_surface::add_Button<Number_Button>(this, "3", 290.f, 300.f, 78, 38, "images/buttons/3/3_button_ciemny.png", "images/buttons/3/3_button_jasny.png");
	Game_surface::add_Button<Number_Button>(this, "4", 410.f, 300.f, 78, 38, "images/buttons/4/4_button_ciemny.png", "images/buttons/4/4_button_jasny.png");
	Game_surface::add_Button<Ok>(this, "Ok", 280.f, 370.f, 130, 37, "images/buttons/Ok/ciemny_ok.png", "images/buttons/Ok/jasny_ok.png");

	if (auto button = buttons["2"]; !button->is_active()) button->toggle_active();
	if (auto button = buttons["3"]; !button->is_active()) button->toggle_active();
	if (auto button = buttons["4"]; !button->is_active()) button->toggle_active();
	if (auto button = buttons["Ok"]; !button->is_active()) button->toggle_active();
}
void Menu::set_num_button(Number_Button* num_b) {
	if (num_button != num_b)
	{
		num_button = num_b;
		number_image.setTexture(*number_textures[num_button->get_name().at(0)]);
	}
}