#ifndef TOOLS_H
#define TOOLS_H
#include <vector>
#include "Game_surface/Board.h"
//#include "Clickables/Buttons/Fields/Field.h"
#include "Clickables/Buttons/Fields/Plain_field.h"
#include "Clickables/Buttons/Fields/Shelter_field.h"
#include "Clickables/Buttons/Fields/Start_field.h"
#include "Clickables/Buttons/Fields/Meta_field.h"

void add_Fields(Board* board)
{
    auto plan_of_fields = std::vector<std::vector<short> >({
        {0,0,0,0,5,10,10,10,6,10,5,0,0,0,0},
        {0,0,0,0,10,0,0,1,0,0,10,0,0,0,0},
        {0,0,0,0,10,0,0,1,0,0,10,0,0,0,0},
        {0,0,0,0,10,0,0,1,0,0,10,0,0,0,0},
        {5,10,10,10,0,0,0,1,0,0,0,10,10,10,5},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {9,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,4,4,4,4,0,0,0,0,0,2,2,2,2,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {5,10,10,10,0,0,0,3,0,0,0,10,10,10,5},
        {0,0,0,0,10,0,0,3,0,0,10,0,0,0,0},
        {0,0,0,0,10,0,0,3,0,0,10,0,0,0,0},
        {0,0,0,0,10,0,0,3,0,0,10,0,0,0,0},
        {0,0,0,0,5,10,8,10,10,10,5,0,0,0,0}
        }
    );

    for (unsigned y = 0; y < plan_of_fields.size(); y++) {
        for (unsigned x = 0; x < plan_of_fields[y].size(); x++)
            if (unsigned i = plan_of_fields[y][x]; i != 0) {

                switch (i)
                {
                case 0:
                    break;

                case 5:
                {
                    board->add_Element<Shelter_field>("Fields", "shelter_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/shelter48.png", "images/48x48/shelter48_krycie20.png");
                    //std::cout << field->get_name() << std::endl;
                    break;
                }
                case 10:
                {
                    board->add_Element<Plain_field>("Fields", "plain_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/plain48.png", "images/48x48/plain48_krycie40.png");
                    // std::cout << field->get_name() << std::endl;
                    break;
                }
                case 6:
                {
                    board->add_Element<Start_field>("Fields", "yellow_start_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/y48_start.png", "images/48x48/y48_start_jasny_bez_przez.png");
                    //std::cout << field->get_name() << std::endl;
                    break;
                }
                case 1:
                {     board->add_Element<Meta_field>("Fields", "yellow_meta_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/y48_finish.png", "images/48x48/y48_finish_jasny_bez_przezr.png");
                // std::cout << field->get_name() << std::endl;
                break;
                }
                case 9:
                {     board->add_Element<Start_field>("Fields", "red_start_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/r48_start.png", "images/48x48/r48_start_jasny_bez_przez.png");
                //std::cout << field->get_name() << std::endl;
                break;
                }
                case 4:
                {    board->add_Element<Meta_field>("Fields", "red_meta_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/r48_finish.png", "images/48x48/r48_finish_krycie40.png");
                //std::cout << field->get_name() << std::endl;
                break;
                }
                case 2:
                {   board->add_Element<Meta_field>("Fields", "blue_meta_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/b48_finish.png", "images/48x48/b48_finish_krycie40.png");
                //std::cout << field->get_name() << std::endl;
                break;
                }
                case 7:
                {   board->add_Element<Start_field>("Fields", "blue_start_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/b48_start.png", "images/48x48/b48_start_jasny_bez_przez.png");
                //std::cout << field->get_name() << std::endl;
                break;
                }
                case 3:
                {     board->add_Element<Meta_field>("Fields", "green_meta_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/g48_finish.png", "images/48x48/g48_finish_krycie40.png");
                //std::cout << field->get_name() << std::endl;
                break;
                }
                case 8:
                {   board->add_Element<Start_field>("Fields", "green_start_field_" + std::to_string(x) + ";" + std::to_string(y), x * 45.f + 170.f, y * 45.f + 45.f, 45, 45, "images/48x48/g48_start.png", "images/48x48/g48_start_jasny_bez_przez.png");
                //std::cout << field->get_name() << std::endl;
                break;
                }
                default:
                    std::cout << "Couldn`t match number to field" << std::endl;
                    break;
                }

            }
    }
}





#endif // !TOOLS_H

