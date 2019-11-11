#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <Gosu/GraphicsBase.hpp>

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>

#include "ZOrder.h"
#include "Player.h"
#include "Background.h"
#include "Block.h"
#include "FPS.h"
#include "Cloud.h"
//#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

//FPS
Fps fps;

class GameWindow : public Gosu::Window
{
	Gosu::Font fps_anzeige;

public:


	Player player;
	Background background;
	Blocks normal_block;
	//TEST
	std::list<Cloud> clouds;
	Animation cloud_anim;
	//Animation_Blocks Animation_Block;
	

	GameWindow() : Window(800, 600),fps_anzeige(20)
	{
		set_caption("Project Utopia");

		player.set_pos(100, 500);
		background.set_pos(300, 500);
		
		normal_block.set_pos(400, 300);
		//TEST
		std::string filename_block = "Brick_Blocks.png";
		std::string filename = "clouds.png";
		cloud_anim = Gosu::load_tiles(filename, 666, 300);

	}

	void update() override //ca. 60x pro Sekunde
	{
		if (input().down(Gosu::KB_D) == true&& input().down(Gosu::KB_A) == false) //Taste D
		{
			if (player.actual_pos_x() <= (width() - 100))
			{
				player.turn_right();
				player.tilt_right();
			}
			if (player.actual_pos_x() > (width() - 100))
			{
				background.move_left();
				player.tilt_right();
				normal_block.set_pos_left();
			}

		}
		if (input().down(Gosu::KB_A) == true&& input().down(Gosu::KB_D) == false) //Taste A
		{
			if (player.actual_pos_x() >= 100)
			{
				player.turn_left();
				player.tilt_left();
			}
			if (player.actual_pos_x() < 100)
			{
				background.move_right();
				player.tilt_left();
				normal_block.set_pos_right();
			}

		}
		if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == true) {
			player.stop();
		}
		if (input().down(Gosu::KB_W) == true || player.get_jump()==true)
		{
			player.jump();
		}
		if (input().down(Gosu::KB_A) == false && input().down(Gosu::KB_D) == false) //Taste A & D nicht gedrückt
		{
			player.reset_rot();
		}
		if (player.actual_pos_y() >= (height() - 101))
		{
			player.resetJumpTime();
		}
		if (player.actual_pos_y() > normal_block.y_pos() - 5.0 && 
			player.actual_pos_y() < (normal_block.y_pos() +5.0+ normal_block.height()) && 
			player.actual_pos_x() > normal_block.x_pos() - 5.0 && 
			player.actual_pos_x() < normal_block.x_pos() +normal_block.width()+ 5.0 &&
			player.get_jumptime() > 0.6)
		{
			player.set_pos(player.actual_pos_x(),normal_block.y_pos());
			player.resetJumpTime();
			player.jumpposition();
		}
		if ((player.actual_pos_x() < normal_block.x_pos() - 5.0 || player.actual_pos_x() > normal_block.x_pos() + normal_block.width() + 5.0) &&
			//|| 
			//(player.actual_pos_x() > normal_block.x_pos() - 5.0 && player.actual_pos_x() < normal_block.x_pos() + normal_block.width() + 5.0 &&player.actual_pos_y()> normal_block.y_pos() +normal_block.height() && player.actual_pos_y() <=500) &&
			player.get_jump()==false)
		{
			player.drop();
		}
		if (player.actual_pos_y() > 500) {
			player.set_pos(player.actual_pos_x(),500.0);
			player.jumpposition();
		}

		//TEST
		if (std::rand() % 25 == 0 && clouds.size() < 5) 
		{
			clouds.push_back(Cloud(cloud_anim));
		}

		//Berechnet FPS
		fps.update();
	}
	void draw() override //ca. 60x pro Sekunde
	{

		player.draw();
		background.draw();
		normal_block.draw_Blocks(0);
		//MERKER: Erstellen von Enum für Reihenfolge von Images/fonts
		fps_anzeige.draw("FPS: " + std::to_string(fps.get()), 15, 15, Z_UI,
			1, 1, Gosu::Color::RED);
		
		graphics().draw_quad(
			0, 500, Gosu::Color::GREEN,
			800, 500, Gosu::Color::WHITE,
			800, 600, Gosu::Color::WHITE,
			0, 600, Gosu::Color::GREEN,
			Z_BACKGROUND
		);
	
		//TEST
		for (Cloud& cloud : clouds) 
		{
			cloud.draw();
		}
	
	}

};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}


//*****************************Funktionen*****************************//


