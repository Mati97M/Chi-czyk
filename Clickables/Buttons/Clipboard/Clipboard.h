#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <SFML/Graphics.hpp>
#include "../Button.h"
#include <array>
#include <vector>
#include "../Pawn/Pawn.h"

class Player;
class Pawn;
class Clipboard: public Button
{
	friend class Board;
	friend class Register;

	//jakas tekstura i  obrazek
	sf::Texture texture;
	sf::Sprite sprite;
	std::array<std::pair<int, int>, 4> slots;	//for placing pawns
	std::vector<Pawn*> pawns_vector;

	void introduce_the_pawn();

	void OnClick();

	Clipboard(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered);
	~Clipboard(){ std::cout << __func__ << std::endl; }

public:
	short get_X_from_slot(short which) { return slots.at(which).first; }
	short get_Y_from_slot(short which) { return slots.at(which).second; }
	int pawns_number();
	sf::Vector2f get_free_slot_coord();
};

#endif
