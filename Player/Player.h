#ifndef PLAYER_H
#define PLAYER_H


//const char* players [] = {"red","yellow","green" ,"blue"};
#include <string>
#include <vector>
#include <list>
#include<iostream>
#include "../Clickables/Buttons/Pawn/Pawn.h"


class Clipboard;
class Board;
class Pawn;
using ListsMap = std::map<std::string, std::list<Field*>>;
using FieldList = std::list<Field*>;
class Player
{
	friend class Board;
	friend class Pawn;
	friend class Register;
	friend class Meta_field;

private:
	void add_path(Board* board);
	static ListsMap paths;
	FieldList path;
	static void view_paths();
	
	std::string name;
	std::vector<Pawn*> pawns;	// board przydziela kazdemu graczowi pionki
	std::vector<Pawn*> pawns_on_meta;
	Clipboard* clipboard;
	bool has_pawn_on_board;
	bool has_pawn_in_clipboard();
	bool can_move_pawn(Pawn* pawn);
	
	Player(std::string, Board* board);
	~Player() { std::cout << __func__ << std::endl; }
	static int added_players;
	static Player* add_Player(std::string name, Board* board);

	void set_Clipboard(Clipboard* c) { clipboard = c;  }
public:
	std::string get_name() { return name; };
	int pawns_on_meta_num() { return pawns_on_meta.size(); }
	bool is_mission_accomplished() { return (pawns_on_meta.size() == pawns.size()) ? true : false; } //wysyla informacje do Register, ze: pora unieruchomic wszystko, wyswietlic wynik,  zakonczyc gre (jezeli gracze nie zdecydowali sie na kontynuowanie gry do upadlego), 
};

#endif // !PLAYER_H