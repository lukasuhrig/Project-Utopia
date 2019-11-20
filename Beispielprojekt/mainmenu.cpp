#include "stdafx.h"
#include "mainmenu.h"


void Menu::Background() //drawt den Menühintergrund
{
	background_image.draw_rot(
		0, 0,Z_Menu_back,
		0,
		0,
		0,
		1.8,
		1.9
	);
}

void Menu::Level(uint16_t lvl_num, std::string lvl) //drawt die Levelbezeichnung
{
	Level_name.draw(lvl, Position_x(lvl_num)+17, Position_y(lvl_num)+10, Z_Menu_Text, 3, 3

	);
	button_image.draw_rot(
		Position_x(lvl_num), Position_y(lvl_num), Z_Menu_button,
		0,
		0,
		0,
		0.2,
		0.2
	);
}
double Menu::Position_x(uint16_t lvl_num) {
	//switch (lvl_num) {
	//case 1: {return 100.0; break; }
	//case 2: {return 300.0; break; }
	//case 3: {return 500.0; break; }
	//case 4: {return 100.0; break; }
	//case 5: {return 300.0; break; }
	//case 6: {return 500.0; break; }
	//case 7: {return 100.0; break; }
	//case 8: {return 300.0; break; }
	//case 9: {return 500.0; break; }
	//default: {return 0; }
	//}
	if (lvl_num == 1) {
		return 100.0;
	}
	if (lvl_num == 2) {
		return 300.0;
	}
	if (lvl_num == 3) {
		return 500.0;
	}
	if (lvl_num == 4) {
		return 100.0;
	}
	if (lvl_num == 5) {
		return 300.0;
	}
	if (lvl_num == 6) {
		return 500.0;
	}
	if (lvl_num == 7) {
		return 100.0;
	}
	if (lvl_num == 8) {
		return 300.0;
	}
	if (lvl_num == 9) {
		return 500.0;
	}
	};
double Menu::Position_y(uint16_t lvl_num) {
	//switch (lvl_num) {
	//case 1: {return 150.0; break; }
	//case 2: {return 150.0; break; }
	//case 3: {return 150.0; break; }
	//case 4: {return 300.0; break; }
	//case 5: {return 300.0; break; }
	//case 6: {return 300.0; break; }
	//case 7: {return 450.0; break; }
	//case 8: {return 450.0; break; }
	//case 9: {return 450.0; break; }
	//default: {return 0; }
	//}
	if (lvl_num == 1) {
		return 150.0;
	}
	if (lvl_num == 2) {
		return 150.0;
	}
	if (lvl_num == 3) {
		return 150.0;
	}
	if (lvl_num == 4) {
		return 300.0;
	}
	if (lvl_num == 5) {
		return 300.0;
	}
	if (lvl_num == 6) {
		return 300.0;
	}
	if (lvl_num == 7) {
		return 450.0;
	}
	if (lvl_num == 8) {
		return 450.0;
	}
	if (lvl_num == 9) {
		return 450.0;
	}

};


double Menu::Button_heigth() //returned die Höhe des Buttons
{
	return button_image.height()*0.2;
};
double Menu::Button_width() // returned die Breite des Buttons
{
	return button_image.width()*0.2;

};
bool Menu::pressedButton(uint16_t lvl_num,Mouse mouse,bool ms_pressed,Menu menu) {
	return (mouse.mouse_x() > Position_x(lvl_num) && mouse.mouse_x() < Position_x(lvl_num) + menu.Button_width() && mouse.mouse_y() > Position_y(lvl_num) && mouse.mouse_y() < Position_y(lvl_num) + menu.Button_heigth() && ms_pressed);
}
void Menu::menu_button(double pos_x, double pos_y) {
	menu.draw("MENU", 360, 10, Z_UI, 1.5, 1.5

	);
}
bool Menu::pressedMenuButton(Mouse mouse, bool ms_pressed) {
	return (mouse.mouse_x() > 360.0 && mouse.mouse_x() < 360.0 +80 && mouse.mouse_y() >10.0 && mouse.mouse_y() < 10.0 +100 && ms_pressed);
}
bool Menu::pressedwinMenuButton(Mouse mouse, bool ms_pressed) {
	return (mouse.mouse_x() > 375.0 && mouse.mouse_x() < 375.0 + 50.0 && mouse.mouse_y() > 450.0 && mouse.mouse_y() < 450.0 + 70.0 && ms_pressed);
}