#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "mouse.h"
class Menu{
	Gosu::Image background_image;
	Gosu::Image button_image;
	Gosu::Font Level_name;
	Gosu::Font menu;
	double button_pos_x=0;
	double button_pos_y=0;
	int Layer_background = Z_Menu_back;
	int Layer_button = Z_Menu_button;
	int Layer_text = Z_Menu_Text;
	int Layer_UI = Z_UI;

public:
	Menu() : background_image("Menu_Background.png"),button_image("button.png"),Level_name(20),menu(20){};
	void Background();
	void Level(uint16_t lvl_num,std::string);
	double Position_x(uint16_t lvl_num);
	double Position_y(uint16_t lvl_num);
	bool pressedButton(uint16_t lvl_num,Mouse mouse, bool ms_pressed, Menu menu);
	double Button_heigth();
	double Button_width();
	void menu_button();
	bool pressedMenuButton(Mouse mouse, bool ms_pressed);

};