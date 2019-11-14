#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include "ZOrder.h"

typedef std::vector<Gosu::Image> Animation_Blocks;
class Blocks 
{
	std::vector<Gosu::Image> Block; // hier werden alle Images gespeichert, die Images sollten eine �hnliche gr��e haben.
	double pos_x;
	double pos_y;
	double block_look;		// Nummer des Images welches man aufrufen will
	int block_shift = 0;


public:
	Animation_Blocks Animation_Block;
	 Blocks()
	{
		Animation_Block.push_back(Gosu::Image("Brick_Block.png"));//Hier Bilder von Bl�cken einf�gen
	};
	

	void set_pos(double x, double y);
	void draw_Blocks(int a, int b, int c);
	double x_pos();
	double y_pos();
	double width();
	double height();
	void set_pos_left();
	void set_pos_right();
	void row_blocks(int a);
};