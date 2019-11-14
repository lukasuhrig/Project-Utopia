#include "stdafx.h"
#include "Player.h"

bool Player::direction() const
{
	return this->lookingRight;
}
void Player::set_idle(bool state)
{
	this->idle = state;
}
void Player:: stop() //Spieler hält an
{
	pos_x = pos_x;
	pos_y = pos_y;
}
void Player:: turn_left() //Spieler dreht sich nach links, läuft nach links und Score zählt runter
{
	set_idle(false);

	lookingRight = false;
	pos_x = pos_x - 10;
		
}
void Player:: turn_right() //Spieler dreht sich nach rechts, läuft nach rechts und Score zählt hoch
{
	set_idle(false);

	lookingRight = true;
	pos_x = pos_x + 10;
	
}
void Player:: jump() //Spieler springt
{
	set_idle(false);

	jumptime = jumptime + (1.0 / 60.0);
	
		pos_y = jump_y + jumptime * jumptime * gravity - 1000.0 * jumptime; //Sprungfunktion
		jumping = true;//Springen =wahr
}
double Player::get_jumpposition() //returned die Absprunghöhe
{
	return jump_y;
}
void Player::drop() //Fallen
{
	droptime = droptime + (1.0 / 60.0); //Fallzeit in Sekunden
	if (pos_y < ground.get_Ground())  //wenn Spieler in der Luft
	{
		pos_y = jump_y + droptime * droptime * gravity; //Fallfunktion
	}
}
double Player:: get_jumptime() //returned die Sprungzeit
{
	return jumptime;
}
void Player::jumpposition() //setzt die Sprungfunktion
{
	jump_y = pos_y;
}
void Player:: draw() const //drawt den Spieler
{
	if (lookingRight == true) //wenn Spieler nach rechts schaut
	{
		character.at(1).draw_rot(pos_x, pos_y, Z_PLAYER,
			0,
			0.5,
			1,
			0.2, //Skalierung Charakter X
			0.2 //Skalierung Charakter Y
		);
	}
	else if (lookingRight == false) //wenn Spieler nach links schaut
	{
		character.at(0).draw_rot(pos_x, pos_y, Z_PLAYER,
			0,
			0.5,
			1,
			0.2, //Skalierung Charakter X
			0.2 //Skalierung Charakter Y
		);
	}
}
void Player:: set_pos(double x, double y) //setzt die Position vom Spieler
{
	pos_x = x;
	pos_y = y;
}
double Player:: actual_pos_x() const //returned die x Position des Spieler
{
	return pos_x;
}
double Player:: actual_pos_y() const //returned die y Position des Spieler
{
	return pos_y;
}
void Player:: resetJumpTime() //setzt die Sprungzeit wieder auf null
{
	jumptime = 0;
	droptime = 0;
	jumping = false;
}
bool Player::get_jump() //true, wenn der Spieler in der Luft ist
{
	return jumping;
}

void Player::score_draw() {
	score_draw1.draw(score_number, 600, 50, Z_PLAYER, 1, 1, Gosu::Color::RED, Gosu::AlphaMode::AM_DEFAULT);
	std::string s = std::to_string(score);
	score_draw1.draw(s, 660, 50, Z_PLAYER, 1, 1, Gosu::Color::RED, Gosu::AlphaMode::AM_DEFAULT);
}

void Player::score_set_up() {
	score++;
}
void Player::score_set_down() {
	score--;
}
bool Player::isIdle() const
{
	return this->idle;
}
