#ifndef BOARD_H
#define BOARD_H


#include <SFML/Window.hpp>
#include "Game_surface.h"
#include <vector>
#include <string>
#include <map>

#include "Game_surface.h"
#include "../Clickables/Buttons/Fields/Field.h"
#include "../Clickables/Buttons/Pawn/Pawn.h"
#include "../Player/Player.h"
#include "../Clickables/Buttons/Clipboard/Clipboard.h"
#include "../Clickables/Buttons/Button.h"
#include "../Clickables/Buttons/Dice/Dice.h"
#include "../Communicator/Communicator.h"
#include "../Register/Register.h"
#include "../Animation/Animation.h"

class Register;
class Player;
class Dice;
class Plain_Field; 

class Board: public Game_surface		
{
	friend class Dice;
	friend class Register;
	friend class Plain_field;
	friend class Start_field;

	//friend class ActionRequest;
	//friend void ActionRequest::remove_pawn(Pawn*);

	unsigned player_count;
	bool game_over;

	Button* hoovered_button;
	Communicator* communicator;
	Register* state_of_game;

	using Buttons_vector = std::vector<Button*>;
	using Named_buttons = std::map< std::string, Buttons_vector >;
	Named_buttons  elements;

	using FieldMap = std::map<std::string, Field*>;
	FieldMap fields;
	
	using Players_vector = std::vector<Player*>;
	Players_vector players;

	std::map<std::string, std::vector<Pawn*>> pawns_on_board;


	void remove_the_pawn(Pawn* pawn); // po zbiciu pionka, plansza sciaga go i umieszcza w schowku
	
	//over
	void set_game_over() {}	//jak zostanie tylko jeden gracz, albo jak ktos dojdzie do mety. Potem mozna grac dalej, lub zamknac okno
	
	
	public:
		Board(unsigned w, unsigned h, std::string texture_path, unsigned num_of_players);
		virtual ~Board();
		void update(sf::Clock& clock);
		void add_pawn_on_board( Pawn* pawn);
		const Under_the_cursor& mouse_over_clickable();

	void draw() override;
	unsigned get_player_count() { return player_count; }
	Field* get_field(std::string name){ return fields[name]; }
	Register* get_register() { return state_of_game; }
	unsigned get_dice_result();

	template <typename T>  void add_Element(std::string category, std::string name,  int x, int y, int w, int h, std::string normal, std::string hoovered);
	template <typename T>  T* add_Element(Player* player, std::string category, std::string name,  int x, int y, int w, int h, std::string normal, std::string hoovered);


private:	// z ponizszych nie korzystamy, ale musimy zdef, zeby klasa nie byla abstrakcyjna
	 void set_player_count(unsigned n) {}
	 void set_num_button(Number_Button* num_b) {}
	 //
	 void add_Players();
	 void add_Pawns();
	 void add_Pawn(Player* player, std::string category, std::string name, int x, int y, int w, int h, std::string normal, std::string hoovered);
	 void deactivate_all_elements();
	 void activate_all_elements();
	 Player* update_turn(Player* player);
	 Dice* get_dice_instance();
	 void activate_elements(std::string category);
	 void activate_pawns_on_board(Player* player);
	 bool player_can_move_pawn(Player* player);	
	 void disconnect_player(Player* player);

	 // testing
	 void setPawnsOn(Player* player, std::vector<int>&& coordinates);
};
template <typename T>  void Board::add_Element(std::string category, std::string name, int x, int y, int w, int h, std::string normal, std::string hoovered)
{
	if (category == "Pawn" || category == "Communicator") { std::cout << "Wrong function for adding a element: Pawn or Communicator!" << std::endl; return; }
	else {
		T* new_Element = new T(name, x, y, w, h, normal, hoovered);
		elements[category].push_back(new_Element);
		new_Element->set_hosting_surface(this);
		std::cout << "New " << category << " added. Its name is " << name << std::endl;
		if (category == "Fields") {
			auto dynamic_casting = dynamic_cast<Field*>(new_Element);
			if (!dynamic_casting) std::cout << "couldn`t match types" << std::endl;
			else
			{
				fields[name] = dynamic_casting; ;//reinterpret_cast<Field*>(new_Element); //dynamic_cast<Field*>(new_Element);
			}
		}
	}
}


//template <typename T>  void Board::add_Clipboard(std::string name, int x, int y, int w, int h, std::string normal, std::string hoovered)
//{
//	T* new_clipboard = new T(name, x, y, w, h, normal, hoovered);
//	clipboards[name] = new_clipboard;
//	new_clipboard->set_hosting_surface(this);
//	std::cout << "New field added" << std::endl;
//	
//}

#endif // !BOARD_H
