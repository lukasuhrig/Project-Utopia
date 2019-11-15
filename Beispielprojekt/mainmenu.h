#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "mouse.h"
class Menu{
	Gosu::Image background_image;
	Gosu::Image button_image;
	Gosu::Font Level_name;
	double button_pos_x=0;
	double button_pos_y=0;
	int Layer_background = Z_Menu_back;
	int Layer_button = Z_Menu_button;
	int Layer_text = Z_Menu_Text;

public:
	Menu() : background_image("Menu_Background.png"),button_image("button.png"),Level_name(20){};
	void Background();
	void Button(double,double);
	void Level(double,double,std::string);
	bool Menu::pressedButton(Mouse mouse, bool ms_pressed, Menu menu);
	double Button_heigth();
	double Button_width();

};