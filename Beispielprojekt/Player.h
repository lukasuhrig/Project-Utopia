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
	std::vector<Gosu::Image> shoot_image;

	double pos_x;
	double pos_y;
	double rot;

	bool shooting;

	bool idle;
	bool free=true;
	bool lookingRight;
	float health;
	int64_t score;
	Gosu::Font score_draw1;
	double jumptime;
	double jump_y;
	double gravity = 1000.0;
	bool jumping=false;
	bool dropping = false;
	double droptime;
	Ground ground;

	const double block_tolerance=10.0;

public:
	Player(): score_draw1(20)
	{
		pos_x = pos_y = rot =jumptime=droptime=0;
		score = 20000;
		jump_y = ground.get_Ground();
		health = 100.0;
		lookingRight = true;
		idle = true;
		shooting = false;
		character = Gosu::load_tiles("player_blue.png", 400, 483);
		shoot_image = Gosu::load_tiles("shoot_v1.png", 100, 31);
	}
	void stop();
	void turn_left();
	void turn_right();

	void shoot();

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
	bool get_drop();
	void set_drop(bool b);
	double get_jumpposition();
	bool get_jump();
	double get_jumptime();
	void score_draw();
	void score_set_down(double tiime);
	bool topBlock(std::vector<Blocks> blockvec, int16_t i);
	int64_t get_score();
	void reset(double ground);

	void update();
	void stopShooting();
};