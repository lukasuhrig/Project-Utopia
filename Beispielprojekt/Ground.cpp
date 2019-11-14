#include "stdafx.h"
#include "Ground.h"

void Ground::draw() {
	gnd.draw_quad//drawt Boden
	(
		0, ground, Gosu::Color::GREEN,
		800, ground, Gosu::Color::GREEN,
		800, 600, Gosu::Color::WHITE,
		0, 600, Gosu::Color::WHITE,
		Z_BACKGROUND
	);
}
double Ground::get_Ground() {
	return ground;
}

