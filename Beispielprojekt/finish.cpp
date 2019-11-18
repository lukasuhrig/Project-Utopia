#include "stdafx.h"
#include "finish.h"

void finish::set_pos(double x, double y, double scal_x, double scal_y){
	pos_x = x;
	pos_y = y;
	scale_x = scal_x;
	scale_y = scal_y;
}
void finish::draw_finish(int a){
	animation_finish.at(a).draw_rot(pos_x, pos_y, Z_Blocks,
		// Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
		0,
		0,
		0,
		scale_x, //Skalierung Charakter X
		scale_y //Skalierung Charakter Y
	);

}
double finish::x_pos(){
	return pos_x;
}
double finish::y_pos(){
	return pos_y;
}
double finish::width(){
	return scale_x * 250.0;
}
double finish::height(){
	return scale_y * 250.0;
}
void finish::set_pos_left(){
	pos_x = pos_x - 10;
}
void finish::set_pos_right(){
	pos_x = pos_x + 10;
}