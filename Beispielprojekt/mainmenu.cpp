#include "stdafx.h"
#include "mainmenu.h"


void Menu::Background() //drawt den Menühintergrund
{
	background_image.draw_rot(
		0, 0,Layer_background,
		0,
		0,
		0,
		1.8,
		1.9
	);
}
void Menu::Button(double x, double y)  //drawt den Button
{
	button_image.draw_rot(
		x, y, Layer_button,
		0, 
		0,
		0,
		0.2,
		0.2
	);
}
void Menu::Level(double x, double y, std::string lvl) //drawt die Levelbezeichnung
{
	Level_name.draw(lvl, x, y, Layer_text, 3, 3

	);
}


double Menu::Button_heigth() //returned die Höhe des Buttons
{
	return button_image.height();
};
double Menu::Button_width() // returned die Breite des Buttons
{
	return button_image.width();

};
bool Menu::pressedButton(Mouse mouse,bool ms_pressed, Menu menu) {
	return (mouse.mouse_x() > 200.0 && mouse.mouse_x() < 200.0 + menu.Button_width() && mouse.mouse_y() > 400.0 && mouse.mouse_y() < 400.0 + menu.Button_heigth() && ms_pressed);
}