#ifndef START_FIELD_H
#define START_FIELD_H


//#include "Field.h"
#include "../../../Game_surface/Board.h"
#include "../Pawn/Pawn.h"

class Start_field: public Field
{
	friend class Board;

	Start_field(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered): Field(name, x, y, w, h, normal, hoovered)
	{}
	bool pawn_arrived(Pawn* pawn)
	{
		if (pawn == nullptr) std::cout << "sended pawn is nullptr!\n";
		if (auto p_to_remov = Field::pawn; p_to_remov)
		{
			//swiezo dodany pionek
			if (p_to_remov == pawn)
				return true;

			//zamien pionki. Stary do usuniêcia
			Field::pawn = pawn;
			if (Field::pawn == nullptr) std::cout << "Field::pawn  is nullptr!\n";
			dynamic_cast<Board*>(hosting_surface)->remove_the_pawn(p_to_remov);
			std::cout << "Start_field: Pawn " + p_to_remov->get_name() + " is beeing removed from fields\n";
			std::cout << "Start_field`s Field::pawn  is: " << Field::pawn << std::endl;
			std::cout << "Start_field: Current pawn is: " << Field::pawn->get_name() << std::endl;  
			//nie resetujemy animation, bo pawn musi wrocic do clipboard
			return false;
		}
		else  //puste pole
		{
			std::cout << "Do tej pory, Field::pawn = " << Field::pawn << std::endl;
			std::cout << "Start_field: Dozo! dozo!\n";
			Field::pawn = pawn;
			std::cout << "Start_field: teraz Field::pawn = " << Field::pawn << std::endl;
			
			//Field::pawn_arrived(pawn);
			return true;
		}
	}
public:
	virtual ~Start_field() {}
	void OnClick()
	{
		Field::OnClick();
		//if (!is_clicked()) toggle_clicked(); to chyba nie jest potrzebne
		//przemiesc pionek, ale wczesniej sprawdz, czy pionek zostal zaznaczony
	}
	
};

#endif // !START_FIELD_H