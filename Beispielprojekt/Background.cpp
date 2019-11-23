#include "stdafx.h"
#include "Background.h"


//*****************************  DRAW  ********************
void Background::draw()
{
	if (int32_t(pos_x) % (2 * background_image.width()) == 0 && pos_x != 0) {
		shift = -pos_x;
	}									//soll shift nachdem zwei Hintergründe durchlaufen sind auf pos_x setzen und somit die Hintergründe verschieben
	background_image.draw_rot(pos_x + shift - (3.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	background_image.draw_rot(pos_x + shift - (2.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	background_image.draw_rot(pos_x + shift - double(background_image.width()), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	background_image.draw_rot(pos_x + shift, pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	background_image.draw_rot(pos_x + shift + double(background_image.width()), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	background_image.draw_rot(pos_x + shift + (2.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	background_image.draw_rot(pos_x + shift + (3.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	// verschiedene Hintergruünde, die die Lücken decken sollen
}

//***********************  POSITION  *********************
void Background::move_left()
{
	pos_x = pos_x - 10;					//Bewegen des HIntergrundes nach links -> wenn sich PLayer nach rechts bewegt
}

void Background::move_right()
{
	pos_x = pos_x + 10;					//Bewegen des HIntergrundes nach rechts -> wenn sich PLayer nach links bewegt
}

void Background::set_pos(double x, double y)
{
	pos_x = x;							//setzen der x Position des Hintergrundes 
	pos_y = y;							//setzen der y Position des Hintergrundes
}

//**********************  RESET  ************************
void Background::reset(double ground) {
	pos_x = 300;
	pos_y = ground;
}