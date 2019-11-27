#include "stdafx.h"
#include "Block.h"



//**************  DRAW  ***************
void Blocks::draw_Blocks(int a) {

	Animation_Block.at(a).draw_rot(pos_x, pos_y, Z_Blocks,
		// Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
		0,
		0,
		0,
		scale_x, //Skalierung Charakter X
		scale_y //Skalierung Charakter Y
	);

}

//****************  POSITION  ***********
void Blocks:: set_pos(double x, double y, double scal_x, double scal_y) {
	pos_x = urpos_x = x;
	pos_y = urpos_y = y;
	scale_x = scal_x;
	scale_y = scal_y;
};

void Blocks::set_pos_left()
{
	pos_x = pos_x - 10;
}

void Blocks::set_pos_right()
{
	pos_x = pos_x + 10;
}

double Blocks::x_pos() {
	return pos_x;
}

double Blocks::y_pos() {
	return pos_y;
}

void Blocks::reset() {
	pos_x = urpos_x;
	pos_y = urpos_y;
}

//****************  DIMENSIONS  ********
double Blocks::width() {
	return scale_x*250.0;
}

double Blocks::height() {
	return scale_y * 250.0;
}

