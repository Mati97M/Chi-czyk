#ifndef PLAIN_FIELD_H
#define PLAIN_FIELD_H


//#include "Field.h"
#include "../../../Game_surface/Board.h"
#include "../Pawn/Pawn.h"

class Plain_field: public Field
{
	friend class Board;

	Plain_field(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered): Field(name, x, y, w, h, normal, hoovered)
	{}

	bool pawn_arrived(Pawn* pawn)
	{

		if (auto p_to_remov = Field::pawn; p_to_remov)
		{
			//zamien pionki. Stary do usunicia
			Field::pawn = pawn;
			dynamic_cast<Board*>(hosting_surface)->remove_the_pawn(p_to_remov);
			std::cout << "Plain field: Pawn " + p_to_remov->get_name() + " is beeing removed from fields\n";
			//nie resetujemy animation, bo pawn musi wrocic do clipboarb
			return false;
		}
		else
		{
			std::cout << "Plain_field: Dozo! dozo!\n";
			Field::pawn = pawn;
			//Field::pawn_arrived(pawn);
			//reset animation
			return true;
		}
	}

public:
	virtual ~Plain_field() {}

	void OnClick()
	{
		Field::OnClick();
		//if (!is_clicked()) toggle_clicked(); to chyba nie jest potrzebne
		//przemiesc pionek, 
	}
	//
	//class ActionRequest
	//{
	//	friend class Plain_Field;
	//	static void remove_pawn(Pawn* pawn)
	//	{
	//		Board::remove_the_pawn(pawn);
	//	}
	//};
};




#endif // !PLAIN_FIELD_H