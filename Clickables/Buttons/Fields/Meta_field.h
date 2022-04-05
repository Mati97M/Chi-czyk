#ifndef META_FIELD_H
#define META_FIELD_H

#include "../Pawn/Pawn.h"
//#include "Field.h"
//#include "../Fields/Field.h"

//#include "../../../Player/Player.h"
class Field;
class Pawn;

class Meta_field: public Field
{
	friend class Board;

	Meta_field(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered) : Field(name, x, y, w, h, normal, hoovered){}
	bool pawn_arrived(Pawn* pawn)
	{
		Field::pawn_arrived(pawn);
		pawn->on_meta = true;
		pawn->player->pawns_on_meta.push_back(pawn);
		//czy zresetowac
		return true;
	}

	public:
	virtual ~Meta_field() {}
	void OnClick()
	{
		Field::OnClick();
		//if (!is_clicked()) toggle_clicked(); to chyba nie jest potrzebne
		//przemiesc pionek, ale wczesniej sprawdz, czy pionek zostal zaznaczony
	}
	bool is_taken()
	{
		return Field::pawn ? true : false;
	}

};


#endif // !META_FIELD_H
