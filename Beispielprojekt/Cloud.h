#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include "ZOrder.h"
#include "Animation.h"

class Cloud
{
	Animation animation;
	double pos_x, pos_y;

public:
	explicit Cloud(Animation animation) : animation(animation)
	{
		pos_x = Gosu::random(100, 700);			//zuf�llige Zahl zwischen 100 und 700
		pos_y = Gosu::random(50, 450);			//zuf�llige Zahl zwischen 50 und 450
	}

	double x() const;
	double y() const;
	void draw() const;

};