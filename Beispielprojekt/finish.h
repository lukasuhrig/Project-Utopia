#pragma once
#include "Block.h"
typedef std::vector<Gosu::Image> Animation_Blocks;
class finish {
	std::vector<Gosu::Image> finish_image;
	double pos_x;
	double pos_y;
	double finish_look;
	double scale_x=0.1;
	double scale_y=0.1;
public:
	finish()
	{
		animation_finish.push_back(Gosu::Image("checkered-flag-309862_1280.png"));
		
	};
	Animation_Blocks animation_finish;
	void set_pos(double x, double y);
	void draw_finish(int a);
	double x_pos();
	double y_pos();
	double width();
	double height();
	void set_pos_left();
	void set_pos_right();
	bool reached_finish(double posx, double posy);
	
};