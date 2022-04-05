#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <SFML/Graphics.hpp>
#include <string>

class Board;


class Communicator			//zawijanie tekstu zrobi sie z wykorzystaniem sf::Text::findCharacterPos	
{
	friend class Board;
	friend class Register;

	class Section
	{
		int x, y, w, h;
		sf::Text text;
		friend class Communicator;
	};
	Board* hosting_surf;
	//coordinates
	int x, y, w,  h;

	//margins
	unsigned margin_left;
	unsigned margin_top;
	unsigned margin_right;
	unsigned margin_bottom;

	//content
	Section header;
	Section instruction;
	Section ranking;
	std::string whoose_turn;
	char result;
	///////////////////messages - do umiesczenia chyba gdzie indziej, moze w board
	std::string dice_clicking = "Click on the dice, to get Your result";
	std::string info_result = "Your result is: ";
	std::string introduce_the_pawn = "Click on Your clipboard, then on Your starting field, to introduce the pawn.";
	std::string pawn_moving = "Choose Your avaible pawn, then a field, where to move it.";
	std::string result_six_dice = "Move Your avaible pawn and roll the dice againg, or click on Your clipboard, then on Your starting field, to introduce the pawn.";

//appearance	
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	
	Communicator(Board* hosting_surface, std::string path, int x, int y, int w, int h);
	void draw(sf::RenderWindow* window);
	void setMessage(std::string section, std::string message);

};

#endif