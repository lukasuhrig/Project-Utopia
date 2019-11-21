#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "vec2.h"

class Pet
{
	std::vector<Gosu::Image> pet;

	Vector2 petPos;

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
	Vector2 actual_pos() const;

	void set_pos(const double &x, const double &y);

	void set_idle(const bool &state);

	bool inCorrectPos(const double &player_x, const double &player_y, const bool &lookingRight) const;

	void idleAnim(const double &player_x, const double &player_y, const bool &lookingRight);

	void moveTo(Vector2 &direction_n);

	void draw(const bool &lookingRight);

	void update(const bool &lookingRight, const  double &player_x, const double &player_y, const bool &playerIdle);

	void reset(const bool& lookingRight, const  double& player_x, const double& player_y);

};

