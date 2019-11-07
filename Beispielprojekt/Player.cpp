#include "stdafx.h"
#include "Player.h"

	void Player:: stop() {
		pos_x = pos_x;
	}
	void Player:: turn_left()
	{
		lookingRight = false;
		pos_x = pos_x - 10;
	}
	void Player:: turn_right()
	{
		lookingRight = true;
		pos_x = pos_x + 10;
	}
	void Player:: tilt_left()
	{
		if (rot > -15.0) {
			rot = rot - 1.0;
		}
	}
	void Player:: tilt_right()
	{
		if (rot < 15.0) {
			rot = rot + 1.0;
		}
	}
	void Player:: reset_rot()
	{
		if (rot < 0) {
			rot = rot + 3;
		}
		if (rot > 0) {
			rot = rot - 3;
		}
	}
	void Player:: jump()
	{
		jumptime = jumptime + (1.0 / 60.0);

		if (pos_y != 200 && pos_y <= 500) {
			pos_y = 499 + jumptime * jumptime * 1000 - 900 * jumptime;
		};
	}
	void Player:: draw() const
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
	void Player:: set_pos(double x, double y)
	{
		pos_x = x;
		pos_y = y;
	}
	double Player:: actual_pos_x() const
	{
		return pos_x;
	}
	double Player:: actual_pos_y() const
	{
		return pos_y;
	}
	void Player:: resetJumpTime()
	{
		jumptime = 0;
	}
