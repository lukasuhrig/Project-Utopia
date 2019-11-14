#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include "ZOrder.h"

typedef std::vector<Gosu::Image> Animation_Blocks;
class Blocks : camera
{
	std::vector<Gosu::Image> Block; // hier werden alle Images gespeichert, die Images sollten eine ähnliche größe haben.
	double pos_x;
	double pos_y;
	double block_look;		// Nummer des Images welches man aufrufen will



public:
	Animation_Blocks Animation_Block;
	 Blocks()
	{
		Animation_Block.push_back(Gosu::Image("Brick_Block.png"));//Hier Bilder von Blöcken einfügen
	};
	

	void set_pos(double x, double y);
	void draw_Blocks(int a);
	double x_pos();
	double y_pos();
	double width();
	double height();
};