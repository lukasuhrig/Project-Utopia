#include "stdafx.h"
#include "mouse.h"

void Mouse::mouse(double x,double y) //Mausposition
{
	pos_x = x;
	pos_y = y;
}
void Mouse::draw()  //drawt den Mauszeiger
{
	mouse_image.draw_rot(pos_x, pos_y, Z_Mouse, 0, 0.5, 0.5, 0.05, 0.05);
}
double Mouse::mouse_x() {
	return pos_x;
}
double Mouse::mouse_y() {
	return pos_y;
}