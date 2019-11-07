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
#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;


//**********************ENUMS**********************//

//**********************FUNCTIONS**********************//

//**********************KLASSEN**********************//

//**********************Hilfsklassen für FPS-Berechnung**********************//

//**********************Hilfsklassen für FPS-Berechnung ENDE**********************//

//FPS
Fps fps;

class GameWindow : public Gosu::Window
{
	Gosu::Font fps_anzeige;

public:


	Player player;
	Background background;
	Blocks block_blue;
	//TEST
	std::list<Cloud> clouds;
	Animation cloud_anim;

	GameWindow() : Window(800, 600),fps_anzeige(20)
	{
		set_caption("Project Utopia");

		player.set_pos(100, 500);
		background.set_pos(300, 500);

		//TEST
		std::string filename = "clouds.png";
		cloud_anim = Gosu::load_tiles(filename, 666, 300);
		
	}

	void update() override //ca. 60x pro Sekunde
	{
		if (input().down(Gosu::KB_D) == true) //Taste D
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
			}

		}
		if (input().down(Gosu::KB_A) == true) //Taste A
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
			}

		}

		if (input().down(Gosu::KB_W) == true || player.actual_pos_y() < (height() - 101))
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
	
		//MERKER: Erstellen von Enum für Reihenfolge von Images/fonts
		fps_anzeige.draw("FPS: " + std::to_string(fps.get()), 15, 15, Z_UI,
			1, 1, Gosu::Color::YELLOW);
		
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


