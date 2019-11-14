#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include "ZOrder.h"

typedef std::vector<Gosu::Image> Animation_Blocks;
class Blocks 
{
	std::vector<Gosu::Image> Block; // hier werden alle Images gespeichert, die Images sollten eine ähnliche größe haben.
	double pos_x=0.0;
	double pos_y=0.0;
	double block_look=0.0;		// Nummer des Images welches man aufrufen will
	double scale_x;
	double scale_y;
	int block_shift=0

public:
	Animation_Blocks Animation_Block;
	 Blocks()
	{
		Animation_Block.push_back(Gosu::Image("Brick_Block.png"));//Hier Bilder von Blöcken einfügen
	};
	

	void set_pos(double x, double y, double scal_x, double scal_y);
	void draw_Blocks(int a, int b, int c);
	double x_pos();
	double y_pos();
	double width();
	double height();
	void set_pos_left();
	void set_pos_right();
	void row_blocks(int a);
};