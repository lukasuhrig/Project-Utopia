#include "stdafx.h"
#include "Block.h"
void Blocks:: set_pos(double x, double y) {
	pos_x = x;
	pos_y = y;
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
double Blocks::width() {
	return 0.3*250.0;
}
double Blocks::height() {
	return 0.3 * 250.0;
}
void Blocks::draw_Blocks(int a,int b, int c) {

	Animation_Block.at(a).draw_rot(pos_x+b, pos_y-c, Z_Blocks, // Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
		0,
		0,
		0,
		0.3, //Skalierung Charakter X
		0.3 //Skalierung Charakter Y
	);

}
