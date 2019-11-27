#include "stdafx.h"
#include "character.h"

void character::set_pos(double& x, double& y)
{
	this->charPos.X = x;
	this->charPos.Y = y;
}

void character::spawn()
{
	set_pos(this->spawnPos.X, this->spawnPos.Y);
}

void character::turn_left(double& vel)
{
	this->idle = false;

	lookingRight = false;
	this->charPos.X = this->charPos.X - vel;
}

void character::turn_right(double& vel)
{
	this->idle = false;

	lookingRight = false;
	this->charPos.X = this->charPos.X + vel;
}

void character::set_idle(bool &state)
{
	this->idle = state;
}

bool character::isIdle() const
{
	return this->idle;
}

Vector2 character::getPos() const
{
	return this->charPos;
}

bool character::direction() const
{
	return this->lookingRight;
}

void character::update()
{

}

void character::reset() 
{
	spawn();
}