#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
class Background : camera
{
	Gosu::Image background_image;
	double pos_x;
	double pos_y;
	double shift = 0;						//soll den Hintergrund je nach position des Players verschieben
public:
	Background() : background_image("background_v1.png")
	{
		pos_x = pos_y = 0;					//initiieren der Hintergrundposition
	}
	void move_left();
	void move_right();
	void draw();
	void set_pos(double x, double y);
};