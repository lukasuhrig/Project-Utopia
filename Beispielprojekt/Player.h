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
	void stop() {
		pos_x = pos_x;
	}
	void turn_left()
	{
		lookingRight = false;
		pos_x = pos_x - 10;
	}
	void turn_right()
	{
		lookingRight = true;
		pos_x = pos_x + 10;
	}
	void tilt_left()
	{
		if (rot > -15.0) {
			rot = rot - 1.0;
		}
	}
	void tilt_right()
	{
		if (rot < 15.0) {
			rot = rot + 1.0;
		}
	}
	void reset_rot()
	{
		if (rot < 0) {
			rot = rot + 3;
		}
		if (rot > 0) {
			rot = rot - 3;
		}
	}
	void jump()
	{
		jumptime = jumptime + (1.0 / 60.0);

		if (pos_y != 200 && pos_y <= 500) {
			pos_y = 499 + jumptime * jumptime * 1000 - 900 * jumptime;
		};
	}
	void draw() const
	{
		if (lookingRight == true)
		{
			character.at(1).draw_rot(pos_x, pos_y, Z_PLAYER,
				0,
				0.5,
				1,
				0.2, //Skalierung Charakter X
				0.2 //Skalierung Charakter Y
			);
		}
		else if (lookingRight == false)
		{
			character.at(0).draw_rot(pos_x, pos_y, Z_PLAYER,
				0,
				0.5,
				1,
				0.2, //Skalierung Charakter X
				0.2 //Skalierung Charakter Y
			);
		}
	}
	void set_pos(double x, double y)
	{
		pos_x = x;
		pos_y = y;
	}
	double actual_pos_x() const
	{
		return pos_x;
	}
	double actual_pos_y() const
	{
		return pos_y;
	}
	void resetJumpTime()
	{
		jumptime = 0;
	}

};