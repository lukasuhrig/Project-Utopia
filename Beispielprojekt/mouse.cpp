#include "stdafx.h"
#include "mouse.h"

void Mouse::mouse(double x,double y) {
	pos_x = x;
	pos_y = y;
}
void Mouse::draw() {
	mouse_image.draw_rot(pos_x, pos_y, Z_UI, 0, 0.5, 0.5, 0.05, 0.05);
}
void Mouse::noMouse() {
	pos_x = 1000;
}