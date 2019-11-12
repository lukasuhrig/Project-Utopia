#include "stdafx.h"
#include "mainmenu.h"



void Menu::Background() {
	background_image.draw_rot(
		0, 0,Layer_background,
		0,
		0,
		0,
		1.8,
		1.9
	);
}
void Menu::Button(double x, double y) {
	button_image.draw_rot(
		x, y, Layer_button,
		0, 
		0,
		0,
		0.2,
		0.2
	);
}
void Menu::Level(double x, double y, std::string lvl) {
	Level_name.draw(lvl, x, y, Layer_text, 3, 3

	);
}
void Menu::noMenu() {
	Layer_background = Z_Menu_back_2;
	Layer_text = Z_Menu_Text_2;
	Layer_button = Z_Menu_button_2;
}
double Menu::Button_heigth() {
	return button_image.height();
};
double Menu::Button_width() {
	return button_image.width();

};