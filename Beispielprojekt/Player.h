#pragma once
#include <vector>
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"

class Player
{
	std::vector<Gosu::Image> character;

	double pos_x;
	double pos_y;
	double rot;
	bool lookingRight;
	float health;
	unsigned score;
	double jumptime = 0;

public:
	Player()
	{
		pos_x = pos_y = score = rot = 0;
		health = 100.0;
		lookingRight = true;
		character = Gosu::load_tiles("player_blue.png", 400, 483);
	}
	void stop();
	void turn_left();
	void turn_right();
	void tilt_left();
	void tilt_right();
	void reset_rot();
	void jump();
	void draw() const;
	void set_pos(double x, double y);
	double actual_pos_x() const;
	double actual_pos_y() const;
	void resetJumpTime();
};