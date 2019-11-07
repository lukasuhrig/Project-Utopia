#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
class Background
{
	Gosu::Image background_image;
	double pos_x;
	double pos_y;
	double shift = 0;
public:
	Background() : background_image("background_new.png")
	{
		pos_x = pos_y = 0;
	}
	void move_left()
	{
		pos_x = pos_x - 10;
	}
	void move_right()
	{
		pos_x = pos_x + 10;
	}

	void draw()
	{
		if (int32_t(pos_x) % (2 * background_image.width()) == 0 && pos_x != 0) {
			shift = -pos_x;
		}
		background_image.draw_rot(pos_x + shift - (3.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift - (2.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift - double(background_image.width()), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift, pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift + double(background_image.width()), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift + (2.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift + (3.0 * double(background_image.width())), pos_y, Z_BACKGROUND, 0.0, 0.5, 1);

	}
	void set_pos(double x, double y)
	{
		pos_x = x;
		pos_y = y;
	}
};