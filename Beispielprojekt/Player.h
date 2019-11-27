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
	std::vector<Gosu::Image> character;
	std::vector<Gosu::Image> shoot_image;


	double rot;
	const double scale_x=0.2;
	const double scale_y=0.2;
	bool shooting;

	bool free=true;


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
	explicit Player() : score_draw1(20)
	{
		charPos.X = charPos.Y = 0;
		spawnPos.X = 0; //hier noch beim konstruktor werte �bergeben
		spawnPos.Y = 0; //hier noch beim konstruktor werte �bergeben
		lookingRight = true;
		idle = true;

		rot =jumptime=droptime=0;
		score = 20000;
		jump_y = ground.get_Ground();
		health = 100.0;
		shooting = false;
		character = Gosu::load_tiles("player_blue.png", 400, 483);
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
	bool blockhit(std::vector<Blocks> blockvec, int16_t i);
	int64_t get_score();
	void reset(double ground);

	void update();
	void stopShooting();
};