#include "stdafx.h"
#include "pet.h"

double Pet::actual_pos_x() const
{
	return pos_x;
}

double Pet::actual_pos_y() const
{
	return pos_y;
}

void Pet::draw(bool lookingRight, double player_x, double player_y)
{
	if (lookingRight == true) //wenn Spieler nach rechts schaut
	{
		pos_x = player_x - 80;
		pos_y = player_y - 80;
		pet.at(0).draw_rot(pos_x, pos_y, Z_PET,
			0,
			0.5,
			1,
			0.15, //Skalierung Pet X
			0.15 //Skalierung Pet Y
		);
	}
	else if (lookingRight == false) //wenn Spieler nach links schaut
	{
		pos_x = player_x + 80;
		pos_y = player_y - 80;
		pet.at(1).draw_rot(pos_x, pos_y, Z_PET,
			0,
			0.5,
			1,
			0.15, //Skalierung Pet X
			0.15 //Skalierung Pet Y
		);
	}
}
