#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include "ZOrder.h"
class Blocks
{
	std::vector<Gosu::Image> Block; // hier werden alle Images gespeichert, die Images sollten eine ähnliche größe haben.
	double pos_x;
	double pos_y;
	double block_look;		// Nummer des Images welches man aufrufen will

public:
	void set_pos_left()
	{
		pos_x = pos_x - 10;
	}
	void set_pos_right()
	{
		pos_x = pos_x + 10;
	}

	void draw_Blocks() {
		Block.at(block_look).draw_rot(pos_x, pos_y, Z_Blocks, // Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
			0,
			1,
			1,
			1, //Skalierung Charakter X
			1 //Skalierung Charakter Y
		);

	}

};