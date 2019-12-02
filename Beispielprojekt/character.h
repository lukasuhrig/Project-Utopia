#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "vec2.h"

class character
{

protected:

	Vector2 charPos;

	Vector2 spawnPos;

	bool idle;
	bool lookingRight;

	float health;

public:
	character()
	{
		spawnPos.X = 0;
		spawnPos.Y = 0;		
		health = 100.0;
		charPos.X = charPos.Y = 0;
		idle = true;
		lookingRight = true;
	}

	void set_pos(double x, double y);

	void spawn();

	void turn_left(double vel);
	void turn_right(double vel);
	void set_idle(bool state);
	bool isIdle() const;

	Vector2 getPos() const;

	bool direction() const;

	void update();

	void reset();

};

