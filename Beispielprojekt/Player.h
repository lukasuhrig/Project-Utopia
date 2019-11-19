#pragma once
#include <vector>
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "Ground.h"
#include "Block.h"

class Player
{
	std::vector<Gosu::Image> character;

	double pos_x;
	double pos_y;
	double rot;

	bool idle;
	bool free=true;
	bool lookingRight;
	float health;
	int64_t score;
	Gosu::Font score_draw1;
	double jumptime = 0;
	double jump_y;
	double gravity = 1000.0;
	bool jumping=false;
	double droptime = 0;
	Ground ground;

	const double block_tolerance=10.0;

public:
	Player(): score_draw1(20)
	{

		pos_x = pos_y = rot =0;
		score = 20000;
		jump_y = ground.get_Ground();
		health = 100.0;
		lookingRight = true;
		idle = true;
		character = Gosu::load_tiles("player_blue.png", 400, 483);
	}
	void stop();
	void turn_left();
	void turn_right();

	void set_idle(bool state);
	bool isIdle() const;

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
	void score_set_down(double tiime);
	bool topBlock(std::vector<Blocks> Blockvec, uint16_t i);
	int64_t get_score();
};