#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
class Mouse {
	Gosu::Image mouse_image;
	double pos_x = 0;
	double pos_y = 0;
public:
	Mouse() : mouse_image("pointerimg.png") {};
	void mouse(double, double);
	void draw();
	void noMouse();
};