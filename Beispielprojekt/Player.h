#pragma once
#include <vector>
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "ZOrder.h"
#include "Ground.h"
#include "Block.h"
#include "character.h"

class Player : public character
{
	std::vector<Gosu::Image> character_image;
	std::vector<Gosu::Image> shoot_image;


	double rot;
	const double scale_x=0.2;
	const double scale_y=0.2;
	bool shooting;
	double right;
	double left;

	bool free=true;


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
	Player() : score_draw1(20)
	{
		charPos.X = charPos.Y = 0;
		spawnPos.X = 0;
		spawnPos.Y = 0;
		lookingRight = true;
		idle = true;
		left = right = 0;
		rot =jumptime=droptime=0;
		score = 20000;
		jump_y = ground.get_Ground();
		health = 100.0;
		shooting = false;
		character_image = Gosu::load_tiles("player_blue.png", 400, 483);
		shoot_image = Gosu::load_tiles("shoot_v1.png", 100, 31);
		
	}
	void stop();

	void shoot();


	void jump();
	void draw() const;

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

	double width();
	double height();
	bool leftblockhit(std::vector<Blocks> blockvec, int16_t i);
	bool rightblockhit(std::vector<Blocks> blockvec, int16_t i);
	bool topblockhit(std::vector<Blocks> blockvec, int16_t i);
	bool bottomblockhit(std::vector<Blocks> blockvec, int16_t i);
	int64_t get_score();
	void reset(double ground);

	void update();
	void stopShooting();
};