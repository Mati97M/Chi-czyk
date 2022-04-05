#ifndef ANIMATION_H
#define ANIMATION_H

#include "../Clickables/Buttons/Pawn/Pawn.h"
class Dice;
class Pawn;
class Field;
class Clipboard;

class Animation	//manipulates positions of object. Animation is performed only for 1 obj at given moment
{
	friend class Board;

	static float speed;
	static bool in_progress;
	static float movement_speed;
	static sf::Vector2f moveable_position;
	static sf::Vector2f target_position;
	static float delta_x;
	static float delta_y;
	static float temp_x;
	static float temp_y;
	static bool pawn_animation;
	static bool dice_animation;
	static bool returning_pawn_anim;

	static Pawn* pawn;
	static Field* field;
	static Dice* dice;
	static Clipboard* clipboard;

	//before movement itself, first there is need to initialize it. Than updating.
	 
	static bool Update(sf::Time delta_time);
	static void Update_Pawn_anim(sf::Time delta_time);
	static void Update_Dice_anim(sf::Time delta_time);
	static void Update_returning_pawn(sf::Time delta_time);

	static void Reset();
public:
	static void Initialize_movement(Pawn* arg_pawn, Field* arg_field);
	static void Initialize_movement(Pawn* arg_pawn, Clipboard* arg_clipb);
	//static void Initialize_movement(Pawn* arg_pawn, sf::Vector2f coordinates);
	static void Initialize_rolling();
	static bool In_progress() { return in_progress; }
	
};


#endif // !ANIMATION_H
