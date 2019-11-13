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

public:
	Pet()
	{
		pos_x = pos_y = 0;
		pet = Gosu::load_tiles("pet_1.png", 500, 500);
	}

	double actual_pos_x() const;
	double actual_pos_y() const;

	void draw(bool lookingRight, double player_x, double player_y);
};

