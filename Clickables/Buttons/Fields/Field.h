#ifndef FIELD_H
#define FIELD_H


#include "../Button.h"
#include "../../../Register/Register.h"
#include "../../../Animation/Animation.h"
#include "../Pawn/Pawn.h"


class Pawn;
class Meta_field;
//class Plain_field;
//class Start_field;

class Field: public Button	
{
	friend class Board;
	friend class Pawn;
	friend class Register;
	friend class Animation;
	friend class Plain_field;
	friend class Start_field;

	//w field nie ma potrzeby zniemiac stanu clicked, trzeba tylko sprawdzac, czy jakis pionek jest zaznaczony, i wywolywac funkcje przeieszczenia
   // czy na pole moze wejsc  jeszcze 1 pionek, bez zbicia poprzedniego
	
	static Field* active; //always one, or none
	static void set_active(Field*);

	protected:
		Pawn* pawn;
		bool vacancies;
		sf::Vector2f slot;
		Field(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered) : Button(name, x, y, w, h, normal, hoovered), vacancies{ true }, slot{ sf::Vector2i(x + 20,y + 20) }, pawn{ nullptr }{}
	//{if (!is_active()) toggle_active();}
		void highlight();
		void OnClick();
		static void turn_off_all(std::vector<Pawn*> & pawns);
		virtual bool pawn_arrived(Pawn* pawn);

 public: 
 //void set_pawn_safe(Pawn* p);  zamiast tego raczej toggle safe i to jeszcze tylko w klasie shelter
	 static void Update_active();
	 virtual ~Field() {};
	 bool are_vacancies() { return vacancies; }
	 void toggle_vacancies() { vacancies = !vacancies; }
	 sf::Vector2f get_slot() { return slot; }
	 
};

#endif // !FIELD_H