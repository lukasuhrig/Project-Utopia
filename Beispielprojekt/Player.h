#pragma once
#include <vector>
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "Ground.h"

class Player
{
	std::vector<Gosu::Image> character;

	double pos_x;
	double pos_y;
	double rot;
	bool lookingRight;
	float health;
	unsigned score;
	Gosu::Font score_draw1;
	double jumptime = 0;
	double jump_y;
	double gravity = 1000.0;
	bool jumping=false;
	double droptime = 0;
	Ground ground;
	std::string score_number = "Score : ";

public:
	Player(): score_draw1(20)
	{

		pos_x = pos_y = score = rot =0;
		jump_y = ground.get_Ground();
		health = 100.0;
		lookingRight = true;
		character = Gosu::load_tiles("player_blue.png", 400, 483);
	}
	void stop();
	void turn_left();
	void turn_right();
	void jump();
	void draw() const;
	void set_pos(double x, double y);
	double actual_pos_x() const;
	double actual_pos_y() const;
	bool direction() const;
	void resetJumpTime();
	void jumpposition();
	void drop();
	double get_jumpposition();
	bool get_jump();
	double get_jumptime();
	void score_draw();
};