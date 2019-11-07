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

	double x() const
	{
		return pos_x;			//gibt die X Position der Wolke zur�ck
	}

	double y() const
	{
		return pos_y;			//gubt die Y Position der Wolke zur�ck
	}

	void draw() const
	{
		const Gosu::Image& image = animation.at(Gosu::milliseconds() / 100 % animation.size());  //HEXENWERK

		image.draw(pos_x - image.width() / 2.0, pos_y - image.height() / 2.0, Z_OBJECT,			//Zeichnen der Wolke
			0.3,
			0.3
		);
	}

};