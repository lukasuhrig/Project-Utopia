#pragma once
#include "Block.h"
typedef std::vector<Gosu::Image> Animation_Blocks;
class finish {
	std::vector<Gosu::Image> finish_image;
	double pos_x;
	double pos_y;
	double finish_look;
	double scale_x;
	double scale_y;
public:
	finish()
	{
		animation_finish.push_back(Gosu::Image("Normaler_Block.png"));
		
	};
	Animation_Blocks animation_finish;
	void set_pos(double x, double y, double scal_x, double scal_y);
	void draw_finish(int a);
	double x_pos();
	double y_pos();
	double width();
	double height();
	void set_pos_left();
	void set_pos_right();
	
};