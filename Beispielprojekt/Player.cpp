#include "stdafx.h"
#include "Player.h"
#include "interval.h"

interval interval_; //für Zeitberechnung

void Player::stopShooting()
{
	if (interval_.value() > 800) //alle 0,8s stoppt er
	{
		interval_ = interval();

		this->shooting = false;

	}
}

//**************************  DRAW  **********************
void Player::draw() const //drawt den Spieler
{
	if (lookingRight == true) //wenn Spieler nach rechts schaut
	{
		character.at(1).draw_rot(this->charPos.X, this->charPos.Y, Z_PLAYER,
			0,
			0.5,
			1,
			scale_x, //Skalierung Charakter X
			scale_y //Skalierung Charakter Y
		);
	}
	else if (lookingRight == false) //wenn Spieler nach links schaut
	{
		character.at(0).draw_rot(this->charPos.X, this->charPos.Y, Z_PLAYER,
			0,
			0.5,
			1,
			scale_x, //Skalierung Charakter X
			scale_y //Skalierung Charakter Y
		);
	}
	if (this->shooting == true)
	{
		if (lookingRight == true) //wenn Spieler nach rechts schaut
		{
			shoot_image.at(0).draw_rot((this->charPos.X + 22), (this->charPos.Y - 35), Z_PLAYER,
				0,
				0,
				0.5,
				0.7, //Skalierung X
				0.7 //Skalierung Y
			);
		}
		else if (lookingRight == false) //wenn Spieler nach links schaut
		{
			shoot_image.at(1).draw_rot((this->charPos.X - 22), (this->charPos.Y - 35), Z_PLAYER,
				0,
				1,
				0.5,
				0.7, //Skalierung X
				0.7 //Skalierung Y
			);
		}
	}
}

double Player::height() {
	return scale_y + character.at(0).height();
}

double Player::width() {
	return scale_x + character.at(0).width();
}

void Player::stop() //Spieler hält an
{
	this->charPos.X = charPos.X; //was auch immer das macht
	this->charPos.Y = charPos.Y;
}

//***************************  Y-CONTROL  ****************
void Player::jump() //Spieler springt
{
	set_idle(false);

	jumptime = jumptime + (1.0 / 60.0);

	this->charPos.Y = jump_y + jumptime * jumptime * gravity - 1000.0 * jumptime; //Sprungfunktion
	jumping = true;//Springen =wahr
}

void Player::jumpposition() //setzt die Sprungfunktion
{
	jump_y = this->charPos.Y;
}

double Player::get_jumpposition() //returned die Absprunghöhe
{
	return jump_y;
}

double Player::get_jumptime() //returned die Sprungzeit
{
	return jumptime;
}

void Player::resetJumpTime() //setzt die Sprungzeit wieder auf null
{
	jumptime = 0;
	droptime = 0;
	dropping = false;
	jumping = false;
	free = false;
}

bool Player::get_jump() //true, wenn der Spieler in der Luft ist
{
	return jumping;
}


void Player::drop() //Fallen
{
	droptime = droptime + (1.0 / 60.0); //Fallzeit in Sekunden
	if (this->charPos.Y < ground.get_Ground())  //wenn Spieler in der Luft
	{
		this->charPos.Y = jump_y + droptime * droptime * gravity; //Fallfunktion
	}
	dropping = true;
}

bool Player::get_drop() {
	return dropping;
}
void Player::set_drop(bool b) {
	dropping = b;
}

//***************************  COLLISION  ****************
bool Player::topBlock(std::vector<Blocks> blockvec, int16_t i) {

	return(this->getPos().Y > (blockvec.at(i).y_pos() - block_tolerance) && //Begrenzung nach oben
		this->getPos().Y < (blockvec.at(i).y_pos() + block_tolerance + blockvec.at(i).height()) && //Begrenzung nach unten
		this->getPos().X >(blockvec.at(i).x_pos() - block_tolerance) && //Begrenzun nach links
		this->getPos().X < (blockvec.at(i).x_pos() + blockvec.at(i).width() + block_tolerance));
}

//***************************  SHOOT  ********************
void Player::shoot()
{
	shooting = true;
}

//***************************  SCORE  ********************
void Player::score_draw() {
	std::string s = std::to_string(score);
	score_draw1.draw("Score: " + s, 660, 50, Z_PLAYER, 1, 1, Gosu::Color::RED, Gosu::AlphaMode::AM_DEFAULT);
}

void Player::score_set_down(double p_per_sec) //p_per_sec = wie viele punkte pro Sekunde abgezogen werden
{
	score = score - p_per_sec;
}

int64_t Player::get_score() {
	return score;
}

//**************************  RESET  ********************
void Player::reset(double ground) {
	rot = jumptime = droptime = 0;
	score = 20000;
	jump_y = ground;
	health = 100.0;
	lookingRight = true;
	idle = true;
	set_pos(400, ground);
}


void Player::update()
{
	stopShooting();

	//mehr sachen die bei update rein passen würden
}	