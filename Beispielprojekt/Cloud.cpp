#include "stdafx.h"
#include "Cloud.h"
double Cloud:: x() const
{
	return pos_x;			//gibt die X Position der Wolke zurück
}

double Cloud::y() const
{
	return pos_y;			//gubt die Y Position der Wolke zurück
}

void Cloud::draw() const
{
	const Gosu::Image& image = animation.at(Gosu::milliseconds() / 100 % animation.size());  //HEXENWERK

	image.draw(pos_x - image.width() / 2.0, pos_y - image.height() / 2.0, Z_OBJECT,			//Zeichnen der Wolke
		0.3,
		0.3
	);
}