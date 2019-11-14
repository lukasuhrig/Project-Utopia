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
#include "mainmenu.h"
#include "mouse.h"
#include "Ground.h"
//#include "Vektor2d.h"
#include "pet.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;
bool menuing =true;
//FPS
Fps fps;

//VOLUME/SOUND
float master_vol = 1;

class GameWindow : public Gosu::Window
{
	Gosu::Font fps_anzeige;

public:


	Player player;
	Background background;
	Blocks normal_block;
	Blocks normal_block2;
	Mouse mouse;
	Ground ground;
	//TEST
	std::list<Cloud> clouds;
	Animation cloud_anim;
	//Animation_Blocks Animation_Block;
	Menu menu;

	Pet pet_1; //Erstellen Pet

	GameWindow() : Window(800, 600),fps_anzeige(20)
	{
		set_caption("Project Utopia");

		player.set_pos(150, 500);
		pet_1.set_pos((player.actual_pos_x()-80),(player.actual_pos_y()-80));

		background.set_pos(300, ground.get_Ground());
		
		normal_block.set_pos(400, 380,0.3,0.3);
		normal_block2.set_pos(0,500,0.3,0.3);
		//TEST
		std::string filename_block = "Brick_Blocks.png";
		std::string filename = "clouds.png";
		cloud_anim = Gosu::load_tiles(filename, 666, 300);

	}

	void update() override //ca. 60x pro Sekunde
	{
		mouse.mouse(input().mouse_x(), input().mouse_y());
		if ((input().mouse_x() > 200.0 && input().mouse_x() < 200.0 + menu.Button_width() && input().mouse_y() > 400.0 && input().mouse_y() < 400.0 + menu.Button_heigth() && input().down(Gosu::MS_LEFT))||menuing==false) {
			menuing = false;
	
			mouse.noMouse();
			if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
			{
				player.score_set_up();
				//***************RECHTS*******************
				if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
				{
					player.turn_right();
				}
				if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
				{
					background.move_left();
					normal_block.set_pos_left();
					normal_block2.set_pos_left();
				}

			} 
			if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
			{
				player.score_set_down();
				//***************LINKS*******************
				if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
				{
					player.turn_left();
				}
				if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
				{
					background.move_right();
					normal_block.set_pos_right();
					normal_block2.set_pos_right();
				}

			}
			if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == true) // Wenn Taste A und D gedrückt werden, stoppt der Spieler
			{
				player.stop();
			}
			if (input().down(Gosu::KB_W) == true || player.get_jump() == true) //wenn Taste W gedrückt wurde, oder die Sprungfunktion noch nicht beendet wurde
			{
				player.jump();//Spieler läuft Sprungfunktion ab
			}


			if (input().down(Gosu::KB_D) == false && input().down(Gosu::KB_A) == false && player.get_jumptime() == 0) //****************W und D NICHT gedrückt und Spieler im IDLE-Zustand****************
			{
				player.set_idle(true);
			}
			if (player.get_jump() == true)
			{
				player.set_idle(false);
			}
			if (player.actual_pos_y() >= (ground.get_Ground()-1)) //Wenn Spieler den Boden wieder berührt
			{
				player.resetJumpTime();//Resete die Sprungdauer
			}
			if //Spieler in Kasten, der die Oberfläche des Blockes umrahmt
				(player.actual_pos_y() > normal_block.y_pos() - 5.0 && //Begrenzung nach oben
				player.actual_pos_y() < (normal_block.y_pos() + 5.0 + normal_block.height()) && //Begrenzung nach unten
				player.actual_pos_x() > normal_block.x_pos() - 5.0 && //Begrenzun nach links
				player.actual_pos_x() < normal_block.x_pos() + normal_block.width() + 5.0 &&//Begrenzung nach rechts
				player.get_jumptime() > 0.6)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss

			{
				player.set_pos(player.actual_pos_x(), normal_block.y_pos()); //setzt den Spieler ordentlich auf den Block
				player.resetJumpTime();//Resete die Sprungdauer
				player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
			}
			if ((player.actual_pos_x() < normal_block.x_pos() - 5.0 || //Spieler befindet sich links vom Block
				player.actual_pos_x() > normal_block.x_pos() + normal_block.width() + 5.0) &&//Spieler befindet sich rechts vom Block
				//|| 
				///(player.actual_pos_x() > normal_block.x_pos() - 5.0 && player.actual_pos_x() < normal_block.x_pos() + normal_block.width() + 5.0 &&player.actual_pos_y()> normal_block.y_pos() +normal_block.height() && player.actual_pos_y() <=500) &&
				player.get_jump() == false) //und der Spieler nicht abspringen will
			{
				player.drop(); //Spieler fällt
			}
			if (player.actual_pos_y() > ground.get_Ground()+2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
			{
				player.set_pos(player.actual_pos_x(), ground.get_Ground());
				player.jumpposition();
			}

			//TEST
			if (std::rand() % 25 == 0 && clouds.size() < 5)
			{
				clouds.push_back(Cloud(cloud_anim));
			}

			pet_1.update(player.direction(),player.actual_pos_x(),player.actual_pos_y(),player.isIdle()); //PET Animation
		}
		//Berechnet FPS
		fps.update();
	}
	void draw() override //ca. 60x pro Sekunde
	{
		mouse.draw();
		if (menuing == true) //wenn das Menü da sein soll
		{
			menu.Background();//drawt den Background
			menu.Button(200, 400);//drawt den Button
			menu.Level(217, 410, "Level1"); //drawt den Text für das Level
		}
		
		player.draw(); //drawt den player
		player.score_draw();
		pet_1.draw(player.direction()); //draw pet_1

		background.draw(); //drawt den Background
		normal_block.draw_Blocks(0,0,0); //drawt einen Block
		normal_block.draw_Blocks(0,100,100);
		normal_block2.draw_Blocks(0,0, 0);
		normal_block2.draw_Blocks(0, 75, 0);
		normal_block2.draw_Blocks(0, 75*2, 0);
		normal_block2.draw_Blocks(0, 75*3, 0);
		normal_block2.draw_Blocks(0, 75*4, 0);
		normal_block2.draw_Blocks(0, 75 * 5, 0);
		normal_block2.draw_Blocks(0, 75 * 6, 0);
		normal_block2.draw_Blocks(0, 75 * 7, 0);
		normal_block2.draw_Blocks(0, 75 * 8, 0);
		normal_block2.draw_Blocks(0, 75 * 9, 0);
		normal_block2.draw_Blocks(0, 75 * 10, 0);
		normal_block2.draw_Blocks(0, 75 * 11, 0);
		normal_block2.draw_Blocks(0, 75 * 12, 0);
		normal_block2.draw_Blocks(0, 75 * 13, 0);
		normal_block2.draw_Blocks(0, 75 * 14, 0);
		normal_block2.draw_Blocks(0, 75 * 15, 0);
		normal_block2.draw_Blocks(0, 75 * 16, 0);
		normal_block2.draw_Blocks(0, 75 * 17, 0);
		normal_block2.draw_Blocks(0, 75 * 18, 0);
		normal_block2.draw_Blocks(0, 75 * 19, 0);
		//MERKER: Erstellen von Enum für Reihenfolge von Images/fonts
		fps_anzeige.draw("FPS: " + std::to_string(fps.get()), 15, 15, Z_UI,
			1, 1, Gosu::Color::RED);
		ground.draw();
		
	
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


