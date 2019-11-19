#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "vec2.h"

class Pet
{
	std::vector<Gosu::Image> pet;

	double pos_x;
	double pos_y;

	bool movingUp;

	bool idle;

public:
	Pet()
	{
		movingUp = false;
		idle = true;
		pet = Gosu::load_tiles("pet_1.png", 500, 500);
	}

	double actual_pos_x() const;
	double actual_pos_y() const;

	void set_pos(double x, double y);

	void set_idle(bool state);

	bool inCorrectPos(double player_x, double player_y, bool lookingRight);

	void idleAnim(double player_x, double player_y, bool lookingRight);

	void moveTo(Vector2 direction);

	void draw(bool lookingRight);

	void update(bool lookingRight, double player_x, double player_y);

};

