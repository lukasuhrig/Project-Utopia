#pragma once
#include <vector>
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"


class Pet
{
	std::vector<Gosu::Image> pet;

	double pos_x;
	double pos_y;

	bool movingUp;

	bool idle;

	bool inCorrectPos;

public:
	Pet()
	{
		movingUp = false;
		idle = true;
		inCorrectPos = false;
		pet = Gosu::load_tiles("pet_1.png", 500, 500);
	}

	double actual_pos_x() const;
	double actual_pos_y() const;

	void set_pos(double x, double y);

	void set_idle(bool state);

	void draw(bool lookingRight);

	void animation(bool lookingRight, double player_x, double player_y, bool player_idle);

};

