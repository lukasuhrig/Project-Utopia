#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include "ZOrder.h"

typedef std::vector<Gosu::Image> Animation_Blocks;
class Blocks
{
	std::vector<Gosu::Image> Block; // hier werden alle Images gespeichert, die Images sollten eine ähnliche größe haben.
	double pos_x;
	double pos_y;
	double block_look;		// Nummer des Images welches man aufrufen will

	
public:
	Animation_Blocks Animation_Block;
	 Blocks()
	{
		Animation_Block.push_back(Gosu::Image("Brick_Block.png"));//Hier Bilder von Blöcken einfügen
	};
	

	void set_pos(double x, double y) {
		pos_x = x;
		pos_y = y;
	};
	void set_pos_left()
	{
		pos_x = pos_x - 10;
	}
	void set_pos_right()
	{
		pos_x = pos_x + 10;
	}
	
	void draw_Blocks(int a) {
		
		Animation_Block.at(a).draw_rot(pos_x, pos_y, Z_Blocks, // Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
			0,
			1,
			1,
			0.3, //Skalierung Charakter X
			0.3 //Skalierung Charakter Y
		);

	}

};