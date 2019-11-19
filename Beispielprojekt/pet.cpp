#include "stdafx.h"
#include "pet.h"
#include <math.h>

const double animationSpeed = 3; //1.2
const double animationSpeedIdle = 0.25;


Vector2 normalize(const Vector2& source) //Einheitsvektor bilden
{
	float length = sqrt((source.X * source.X) + (source.Y * source.Y));
	if (length != 0)
		return Vector2(source.X / length, source.Y / length);
	else
		return source;
}

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

bool Pet::inCorrectPos(double player_x, double player_y, bool lookingRight)
{
	if (lookingRight == true)
	{
		if ((this->pos_x == (player_x - 80.0)) && (this->pos_y >= (player_y - 85)) && (this->pos_y <= (player_y - 75)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (lookingRight == false)
	{
		if ((this->pos_x == (player_x + 80.0)) && (this->pos_y >= (player_y - 85)) && (this->pos_y <= (player_y - 75)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Pet::idleAnim(double player_x, double player_y, bool lookingRight)
{
	if (inCorrectPos(player_x, player_y, lookingRight))
	{
		if (lookingRight == true)
		{
			if ((this->pos_x == (player_x - 80)) && (this->pos_y == (player_y - 85)))
			{
				movingUp = false;
			}
			else if ((this->pos_x == (player_x - 80)) && (this->pos_y == (player_y - 75)))
			{
				movingUp = true;
			}
		}
		else if (lookingRight == false)
		{
			if ((this->pos_x == (player_x + 80)) && (this->pos_y == (player_y - 85)))
			{
				movingUp = false;
			}
			else if ((this->pos_x == (player_x + 80)) && (this->pos_y == (player_y - 75)))
			{
				movingUp = true;
			}
		}
	}

	Vector2 up;
	up.X = 0;
	up.Y = -1;
	Vector2 down;
	down.X = 0;
	down.Y = 1;

	if (movingUp == true) //hoch
	{
		moveTo(up);
	}
	else if (movingUp == false) //runter
	{
		moveTo(down);
	}
}

void Pet::moveTo(Vector2 direction_n) //Einheitsvektor, bewegt in Richtung X & Y mit animationSpeed
{
	this->pos_x = (actual_pos_x() + (direction_n.X * animationSpeed));
	this->pos_y = (actual_pos_y() + (direction_n.Y * animationSpeed));
}

void Pet::update(bool lookingRight, double player_x, double player_y)
{
	Vector2 playerPosition;

	if (lookingRight == true)
	{
		playerPosition.X = player_x - 80;
		playerPosition.Y = player_y - 80;
	}
	else if (lookingRight == false)
	{
		playerPosition.X = player_x + 80;
		playerPosition.Y = player_y - 80;
	}

	Vector2 petPos;
	petPos.X = this->pos_x;
	petPos.Y = this->pos_y;

	Vector2 direction = normalize(playerPosition - petPos); //Einheitsvektor


	if (inCorrectPos(player_x, player_y, lookingRight) == false) //wenn Pos nicht korrekt dann bewegen
	{
		moveTo(direction); //Bewegung in Richtung
	}

	//idleAnim(player_x, player_y, lookingRight); //Idle Animation funktioniert noch nicht

}
