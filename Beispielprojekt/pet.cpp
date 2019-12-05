#include "stdafx.h"
#include "pet.h"
#include <math.h>
#include "vec2.h"

void normalize(Vector2& source);

const float animationSpeed = 3; //1.2
const float animationSpeedIdle = 0.25;

//********************  POSITION  ********************
Vector2 Pet::actual_pos() const
{
	return petPos;
}

double Pet::actual_pos_x() const
{
	return petPos.X;
}

double Pet::actual_pos_y() const
{
	return petPos.Y;
}

void Pet::set_pos(const double& x, const double& y)
{
	this->petPos.X = x;
	this->petPos.Y = y;
}

bool Pet::inCorrectPos(const double& player_x, const double& player_y, const bool& lookingRight) const
{
	if (lookingRight == true)
	{
		if ((this->petPos.X <= (player_x - 79.0)) && (this->petPos.X >= (player_x - 81.0)) && (this->petPos.Y >= (player_y - 85)) && (this->petPos.Y <= (player_y - 75)))
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
		if ((this->petPos.X >= (player_x + 79.0)) && (this->petPos.X <= (player_x + 81)) && (this->petPos.Y >= (player_y - 85)) && (this->petPos.Y <= (player_y - 75)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

//********************  MOVE  ************************
void Pet::moveTo(Vector2& direction_n) //Einheitsvektor, bewegt in Richtung X & Y mit animationSpeed
{
	this->petPos = (actual_pos() + (direction_n * float(animationSpeed)));
}

//********************  DRAW  ************************
void Pet::draw(const bool& lookingRight)
{
	if (lookingRight == true) //wenn Spieler nach rechts schaut
	{
		pet.at(0).draw_rot(petPos.X, petPos.Y, Z_PET,
			0,
			0.5,
			1,
			0.15, //Skalierung Pet X
			0.15 //Skalierung Pet Y
		);
	}
	else if (lookingRight == false) //wenn Spieler nach links schaut
	{
		pet.at(1).draw_rot(petPos.X, petPos.Y, Z_PET,
			0,
			0.5,
			1,
			0.15, //Skalierung Pet X
			0.15 //Skalierung Pet Y
		);
	}
}

//********************  RESET  ***********************
void Pet::reset(const bool& lookingRight, const  double& player_x, const double& player_y)
{
	if (lookingRight == true)
	{
		this->petPos.X = (player_x - 80);
		this->petPos.Y = (player_y - 80);
	}
	else if (lookingRight == false)
	{
		this->petPos.X = (player_x + 80);
		this->petPos.Y = (player_y - 80);
	}

	this->idle = true;

	this->movingUp = false;

}

//********************  UPDATE  **********************
void Pet::update(const bool& lookingRight, const Vector2& playerPos, const bool& playerIdle)
{
	if ((inCorrectPos(playerPos.X, playerPos.Y, lookingRight) == false)) //wenn Pos nicht korrekt dann bewegen
	{
		Vector2 playerPosition; //die Position oben rechts bzw. oben links

		if (lookingRight == true)
		{
			playerPosition.X = float(playerPos.X - 80);
			playerPosition.Y = float(playerPos.Y - 80);
		}
		else if (lookingRight == false)
		{
			playerPosition.X = float(playerPos.X + 80);
			playerPosition.Y = float(playerPos.Y - 80);
		}

		Vector2 direction = (playerPosition - petPos);
		normalize(direction);
		//direction.Normalize();


		moveTo(direction); //Bewegung in Richtung
	}

	//idleAnim(player_x, player_y, lookingRight); //Idle Animation funktioniert noch nicht

}

//********************  IDLE  ************************
void Pet::set_idle(const bool& state)
{
	this->idle = state;
}

void Pet::idleAnim(const double& player_x, const double& player_y, const bool& lookingRight)
{
	if (lookingRight == true)
	{
		if ((this->petPos.X <= (player_x - 79.0)) && (this->petPos.X >= (player_x - 81.0)) && (this->petPos.Y <= (player_y - 85)))
		{
			movingUp = false;
		}
		else if ((this->petPos.X <= (player_x - 79.0)) && (this->petPos.X >= (player_x - 81.0)) && (this->petPos.Y >= (player_y - 75)))
		{
			movingUp = true;
		}
	}
	else if (lookingRight == false)
	{
		if ((this->petPos.X <= (player_x + 79.0)) && (this->petPos.X >= (player_x + 81.0)) && (this->petPos.Y <= (player_y - 85)))
		{
			movingUp = false;
		}
		else if ((this->petPos.X <= (player_x + 79.0)) && (this->petPos.X >= (player_x + 81.0)) && (this->petPos.Y >= (player_y - 75)))
		{
			movingUp = true;
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

//********************  VECTOR  **********************
void normalize(Vector2& source) //Einheitsvektor bilden
{
	float length = sqrt((source.X * source.X) + (source.Y * source.Y));
	if (length != 0)
	{
		source.X = float(source.X / length);
		source.Y = float(source.Y / length);
	}
	else
	{
		return;
	}
}
