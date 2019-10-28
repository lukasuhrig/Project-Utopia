#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include <Gosu/GraphicsBase.hpp>

#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;


//**********************FUNCTIONS**********************//




//**********************CLASS**********************//

class Player
{
	Gosu::Image character;

	double pos_x;
	double pos_y;
	bool lookingRight;
	float health;
	unsigned score;
	double jumptime = 0;

public:
	Player() : character("Held.png")
	{
		pos_x = pos_y = score = 0;
		health = 100.0;
		lookingRight = true;
	}

	void turn_left()
	{
		lookingRight = false;
		pos_x = pos_x - 10;
	}
	void turn_right()
	{
		lookingRight = true;
		pos_x = pos_x + 10;
	}
	void jump()
	{
		jumptime = jumptime + (1.0 / 60.0);

		if (pos_y != 200 && pos_y <= 500) {
			pos_y = 499 + jumptime * jumptime * 1000 - 900 * jumptime;
		};
	}
	void draw() const
	{
		character.draw_rot(pos_x, pos_y, 0.0,	//Position
			0.0,					//rotation
			0.5, 1					//Position in relation zu der angegebenen POsition
		);
	}
	void set_pos(double x, double y)
	{
		pos_x = x;
		pos_y = y;
	}
	double actual_pos_x()
	{
		return pos_x;
	}
	double actual_pos_y()
	{
		return pos_y;
	}
	void resetJumpTime()
	{
		jumptime = 0;
	}

};

class Background
{
	Gosu::Image background_image;
	double pos_x;
	double pos_y;

public:
	Background() : background_image("Background.png")
	{
		pos_x = pos_y = 0;
	}
	void move_left()
	{
		pos_x = pos_x - 10;
	}
	void move_right()
	{
		pos_x = pos_x + 10;
	}
	void draw() const
	{
		background_image.draw_rot(pos_x, pos_y, 0.0,
			0.0, 0.5, 1);
	}
	void set_pos(double x, double y)
	{
		pos_x = x;
		pos_y = y;
	}
};

class GameWindow : public Gosu::Window
{
public:
		

	Player player;
	Background background;

	GameWindow() : Window(800, 600)
	{
		set_caption("Project Utopia");

		player.set_pos(100,500);
		background.set_pos(100,200);
	}

	void update() override //ca. 60x pro Sekunde
	{
		if (input().down(Gosu::KB_D) == true &&player.actual_pos_x()<=(width()-100)) 
		{
			player.turn_right();
		}

		if (input().down(Gosu::KB_D) == true && player.actual_pos_x() > (width() - 100))
		{
			background.move_left();
		}

		if (input().down(Gosu::KB_A) == true && player.actual_pos_x() >= 100) 
		{
			player.turn_left();
		}

		if (input().down(Gosu::KB_A) == true && player.actual_pos_x() < 100) 
		{
			background.move_right();
		}

		if (input().down(Gosu::KB_W) == true||player.actual_pos_y()< (height()-101)) 
		{
			player.jump();
		}

		if (player.actual_pos_y() >= (height() - 101))
		{
			player.resetJumpTime();
		}


		
	}
	void draw() override //ca. 60x pro Sekunde
	{
	
		player.draw();
		background.draw();
			
		graphics().draw_quad(
			0, 500, Gosu::Color::WHITE,
			800, 500, Gosu::Color::WHITE,
			800, 600, Gosu::Color::WHITE,
			0, 600, Gosu::Color::WHITE,
			0.0
		);
	}
	
};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}


//*****************************Funktionen*****************************//