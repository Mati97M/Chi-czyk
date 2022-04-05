#ifndef REGISTER_H
#define REGISTER_H
#include <vector>
#include <string>
#include "../Game_surface/Board.h"
class Player;
class Board;
class Register	//remember player actions on his turn. Updates info about who is current active player
{
	friend class Board;

	Register() : current_player{ nullptr }, moving_in_progres{}, board{ nullptr }, fields_highlighted{}{}
	Player* current_player;
	static bool dice_rolled;
	bool fields_highlighted;
	static std::vector<std::string> player_actions;	//potrzebny ten static?, chyba tak, bo kazdy zaprzyjasniony obiekt bezie mogl po prostu siegnac do klasy, a przechowujemy tylko 1 ture na raz
	bool moving_in_progres;
	Board* board;
public:
	static void register_clicked(std::string name);
	//void execute() {}	//jak dac znac board, zeby cos zrobil? czysci player actions .... chyba nieporzebne, niech sam obiekt klikalny to sprawdza ireaguje odpowiednio
	Player* get_player() { return current_player; }

	static std::string get_last_clicked() 
	{ 
		if (!player_actions.empty()) return player_actions.back();
		else { return "nothing was clicked so far"; }
	}
	bool was_dice_rolled() { return dice_rolled; }
private:
	void update(sf::Time time);	//do zrobienia! tu analiza tego, czy player juz zakonczyl swoja ture. 
	//jesli tak, kolej nastepnego
	bool wait(float seconds, float interval = 1.f);
	bool can_move_pawn(unsigned n);
	void clear();

};

#endif // !REGISTER_H

