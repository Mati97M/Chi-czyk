#ifndef PAWN_H
#define PAWN_H
#include "../Button.h"
#include <string>
#include <map>
#include <list>
#include "../../../Game_surface/Board.h"
//#include "../Fields/Meta_field.h"
//#include "../Fields/Field.h" nic nie da³o :/

class Board;//potrzeba? tak, bo protestuje kompilator
class Player;
class Field;


class Pawn: public Button
{
	friend class Board;
	friend class Clipboard;
	friend class Animation;
	friend class Register;
	friend class Field;
	friend class Meta_field;
	friend class Shelter_field;
	friend class Plain_field;
	friend class Start_field;
	
	bool on_meta;
	static Pawn* clicked;
	Field* current_field;
	Field* available_field;
	void highlight_available_field(unsigned n);	//sets available field and highlights them
	void deactivate_others();
	static void update();
	Player* player;
	Pawn(Player* player,std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered);
	~Pawn() {}
	bool safe;
	//sf::Vector2f Origin_Coords;
	
	bool move(unsigned field_number); //zwraca false jezeli nie mozna ruszyc pionkiem, a byl rzut kostka. np na starcie - trzeba wyrzucic 6, zeby wejsc; 
	// albo: stoimy przed meta, ale nie mozemy ruszyc pionkiem, bo nie wyrzucilismy tyle oczek, zeby wejsc na mete -> jescze do przemyslenia
	
	
	void toggle_safe() { safe = !safe; };		//bedzie korzystala z tego klasa shelter
	static void turn_off_all(std::vector<Pawn*>& pawns);
	
public:
	bool is_safe() { return safe; }	//skorzysta z tego funkcja z klasy board (remove)
	void OnClick();
	bool has_avaible_field() { return available_field ? true : false; }
	sf::Vector2f get_Origin_Coords() { return	sprite.getOrigin() + sf::Vector2f(x,y); }
	static bool is_clicked();
	
};

#endif