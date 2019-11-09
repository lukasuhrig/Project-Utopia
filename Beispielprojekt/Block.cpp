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

void Blocks::draw_Blocks(int a) {

	Animation_Block.at(a).draw_rot(pos_x, pos_y, Z_Blocks, // Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
		0,
		1,
		1,
		0.3, //Skalierung Charakter X
		0.3 //Skalierung Charakter Y
	);

}