#ifndef SHELTER_FIELD_H
#define SHELTER_FIELD_H


#include "Field.h"
//#include "../../../Animation/Animation.h"
class Pawn;

class Shelter_field: public Field
{
	friend class Board;
	//friend void Animation::Update_Pawn_anim(sf::Time delta_time);

	std::array<std::pair<float, float>, 4> slots;	//for placing pawns

	std::vector<Pawn*> safe_pawns;
	Shelter_field(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered);
	bool pawn_arrived(Pawn* pawn);


public:
	virtual ~Shelter_field() {}
	void OnClick()
	{
		Field::OnClick();
		//if (!is_clicked()) toggle_clicked(); to chyba nie jest potrzebne
		//przemiesc pionek, ale wczesniej sprawdz, czy pionek zostal zaznaczony
	}
	
};

#endif // !SHELTER_FIELD_H