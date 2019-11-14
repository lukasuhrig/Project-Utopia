#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
class Ground {
	Gosu::Graphics gnd;
	const double ground = 590.0;
public:
	Ground() :gnd(0,0){};
	void draw();
	double get_Ground();
};