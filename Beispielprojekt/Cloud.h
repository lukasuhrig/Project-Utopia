#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>

typedef std::vector<Gosu::Image> Animation; //Das muss noch als eigene Klasse (Animation) programmiert werden, dazu müsste man sich jedoch mehr Gedanken machen
class Cloud
{
	Animation animation;
	double pos_x, pos_y;

public:
	explicit Cloud(Animation animation) : animation(animation)
	{
		pos_x = Gosu::random(100, 700);
		pos_y = Gosu::random(50, 450);
	}

	double x() const
	{
		return pos_x;
	}

	double y() const
	{
		return pos_y;
	}

	void draw() const
	{
		const Gosu::Image& image = animation.at(Gosu::milliseconds() / 100 % animation.size());

		image.draw(pos_x - image.width() / 2.0, pos_y - image.height() / 2.0, Z_OBJECT,
			0.3,
			0.3
		);
	}

};