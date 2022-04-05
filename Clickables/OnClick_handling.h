#ifndef ONCLICK_HANDLING_H
#define ONCLICK_HANDLING_H
								////// niepotrzebne ... na razie, raczej do zastosowania przy funkcjach globalnych, albo statycznych
#include <string>
#include <map>
#include <functional>
#include"Buttons/Ok.h"

class OnClick_handling 
{
	OnClick_handling();

public:
	static std::map < std::string, std::function<void()> > handle;
};

std::map < std::string, std::function<void()> > OnClick_handling::handle{};

//["Ok"] = Ok::Onclick;


#endif 


