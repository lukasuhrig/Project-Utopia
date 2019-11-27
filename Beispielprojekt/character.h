#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "vec2.h"

class character
{
	Vector2 charPos;

	Vector2 spawnPos;

	bool idle;
	bool lookingRight;

public:
	character(double spawn_X, double spawn_Y)
	{
		spawnPos.X = spawn_X;
		spawnPos.Y = spawn_Y;		
		charPos.X = charPos.Y = 0;
		idle = true;
		lookingRight = true;
	}

	void set_pos(double &x, double &y);

	void spawn();

	void turn_left(double &vel);
	void turn_right(double& vel);
	void set_idle(bool &state);
	bool isIdle() const;

	Vector2 getPos() const;

	bool direction() const;

	void update();

	void reset();

};

