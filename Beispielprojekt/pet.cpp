#include "stdafx.h"
#include "pet.h"

double animationSpeed = 2.5; //1.2
double animationSpeedIdle = 0.25;

double Pet::actual_pos_x() const
{
	return pos_x;
}

double Pet::actual_pos_y() const
{
	return pos_y;
}

void Pet::set_pos(double x, double y)
{
	pos_x = x;
	pos_y = y;
	inCorrectPos = true;
}

void Pet::draw(bool lookingRight)
{
	if (lookingRight == true) //wenn Spieler nach rechts schaut
	{
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
		pet.at(1).draw_rot(pos_x, pos_y, Z_PET,
			0,
			0.5,
			1,
			0.15, //Skalierung Pet X
			0.15 //Skalierung Pet Y
		);
	}
}

void Pet::set_idle(bool state)
{
	this->idle = state;
}

void Pet::update(bool lookingRight, double player_x, double player_y, bool player_idle)
{

	if (lookingRight == true) //wenn Spieler nach rechts schaut
	{
		this->pos_x = player_x - 80; //links vom Spieler setzen


		if ((this->pos_y >= (player_y - 85)) && (this->pos_y <= (player_y - 75)))//wenn über Spieler links dann...
		{
			this->inCorrectPos = true; //dann ist in korrekter pos.
			this->idle = true; //dann zustand idle setzen
		}
	}	
	else if (lookingRight == false) //wenn Spieler nach links schaut
	{

		this->pos_x = player_x + 80; //rechts vom Spieler setzen

		if ((this->pos_y >= (player_y - 85)) && (this->pos_y <= (player_y - 75))) //wenn über Spieler rechts dann...
		{
			this->inCorrectPos = true; //dann ist in korrekter pos.
			this->idle = true; //dann zustand idle setzen
		}
	}
	if (player_idle == true) //wenn Spieler untätig
	{
		if (inCorrectPos == true) //und pet in correct position
		{
			if (movingUp == false)
			{
				this->pos_y = this->pos_y + animationSpeedIdle; //Animation im Idle-Modus
			}
			else if (movingUp == true)
			{
				this->pos_y = this->pos_y - animationSpeedIdle; //Animation im Idle-Modus
			}
		}
		else if (inCorrectPos == false) //und pet in falscher position
		{
			if (movingUp == false)
			{
				this->pos_y = this->pos_y + animationSpeed; //Animation im Schnell-Modus, da nicht in korretker Pos.
			}
			else if (movingUp == true)
			{
				this->pos_y = this->pos_y - animationSpeed; //Animation im Schnell-Modus, da nicht in korretker Pos.
			}
		}

	}
	else if(player_idle == false) //spieler bewegt sich
	{
		inCorrectPos = false; //pet falsche position setzen

		if (movingUp == false)
		{
			this->pos_y = this->pos_y + animationSpeed; //spieler bewegt sich, also hat pet falsche position und muss spieler im Schnell-Modus hinterher
		}
		else if (movingUp == true)
		{
			this->pos_y = this->pos_y - animationSpeed; //spieler bewegt sich, also hat pet falsche position und muss spieler im Schnell-Modus hinterher
		}
	}

	if (this->pos_y <= (player_y - 85))
	{
		movingUp = false;
	}
	else if (this->pos_y >= (player_y - 75))
	{
		movingUp = true;
	}
}
