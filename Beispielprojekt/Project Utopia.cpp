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
#include "finish.h"
//#include "Vektor2d.h"
#include "pet.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;
bool menuing =true;
bool backtomenu=false;
bool Level1 = false;
bool Level2 = false;
bool Level3 = false;
bool Level4 = false;
bool Level5 = false;
bool Level6 = false;
bool Level7 = false;
bool Level8 = false;
bool Level9 = false;
int64_t frames=0;
int64_t playtime = -1;
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
	Mouse mouse;
	Ground ground;

	//Level1
	std::vector<Blocks>normal_block1;
	std::vector<finish>finish_1;
	Blocks Block1_1;
	Blocks Block1_2;
	finish finish1_1;

	//Level2
	std::vector<Blocks>normal_block2;
	std::vector<finish>finish_2;
	Blocks Block2_1;
	Blocks Block2_2;
	finish finish2_1;
	//Level3
	std::vector<Blocks>normal_block3;
	std::vector<finish>finish_3;
	Blocks Block3_1;
	Blocks Block3_2;
	finish finish3_1;
	//Level4
	std::vector<Blocks>normal_block4;
	std::vector<finish>finish_4;
	Blocks Block4_1;
	Blocks Block4_2;
	finish finish4_1;
	//Level5
	std::vector<Blocks>normal_block5;
	std::vector<finish>finish_5;
	Blocks Block5_1;
	Blocks Block5_2;
	finish finish5_1;
	//Level6
	std::vector<Blocks>normal_block6;
	std::vector<finish>finish_6;
	Blocks Block6_1;
	Blocks Block6_2;
	finish finish6_1;
	//Level7
	std::vector<Blocks>normal_block7;
	std::vector<finish>finish_7;
	Blocks Block7_1;
	Blocks Block7_2;
	finish finish7_1;
	//Level8
	std::vector<Blocks>normal_block8;
	std::vector<finish>finish_8;
	Blocks Block8_1;
	Blocks Block8_2;
	finish finish8_1;
	//Level9
	std::vector<Blocks>normal_block9;
	std::vector<finish>finish_9;
	Blocks Block9_1;
	Blocks Block9_2;
	finish finish9_1;

	//TEST
	std::list<Cloud> clouds;
	Animation cloud_anim;
	//Animation_Blocks Animation_Block;
	Menu menu;

	Pet pet_1; //Erstellen Pet

	GameWindow() : Window(800, 600),fps_anzeige(20)
	{
		set_caption("Project Utopia");

		player.set_pos(150, ground.get_Ground());
		pet_1.set_pos((player.actual_pos_x()-80),(player.actual_pos_y()-80));

		background.set_pos(300, ground.get_Ground());
		//Auslagern sobald alles richtig funktioniert
		//Level1
		Block1_1.set_pos(100, 380, 0.3, 0.3);
		Block1_2.set_pos(100, 180, 0.3, 0.3);
		normal_block1.push_back(Block1_1);
		normal_block1.push_back(Block1_2);
		finish1_1.set_pos(500, 500, 1, 1);
		finish_1.push_back(finish1_1);
		//Level2
		Block2_1.set_pos(200, 380, 0.3, 0.3);
		Block2_2.set_pos(200, 180, 0.3, 0.3);
		normal_block2.push_back(Block2_1);
		normal_block2.push_back(Block2_2);
		finish2_1.set_pos(500, 500, 1, 1);
		finish_2.push_back(finish2_1);
		//Level3
		Block3_1.set_pos(300, 380, 0.3, 0.3);
		Block3_2.set_pos(300, 180, 0.3, 0.3);
		normal_block3.push_back(Block3_1);
		normal_block3.push_back(Block3_2);
		finish3_1.set_pos(500, 500, 1, 1);
		finish_3.push_back(finish3_1);
		//Level4
		Block4_1.set_pos(400, 380, 0.3, 0.3);
		Block4_2.set_pos(400, 180, 0.3, 0.3);
		normal_block4.push_back(Block4_1);
		normal_block4.push_back(Block4_2);
		finish4_1.set_pos(500, 500, 1, 1);
		finish_4.push_back(finish4_1);
		//Level5
		Block5_1.set_pos(500, 380, 0.3, 0.3);
		Block5_2.set_pos(500, 180, 0.3, 0.3);
		normal_block5.push_back(Block5_1);
		normal_block5.push_back(Block5_2);
		finish5_1.set_pos(500, 500, 1, 1);
		finish_5.push_back(finish5_1);
		//Level6
		Block6_1.set_pos(600, 380, 0.3, 0.3);
		Block6_2.set_pos(600, 180, 0.3, 0.3);
		normal_block6.push_back(Block6_1);
		normal_block6.push_back(Block6_2);
		finish6_1.set_pos(500, 500, 1, 1);
		finish_6.push_back(finish6_1);
		//Level7
		Block7_1.set_pos(700, 380, 0.3, 0.3);
		Block7_2.set_pos(700, 180, 0.3, 0.3);
		normal_block7.push_back(Block7_1);
		normal_block7.push_back(Block7_2);
		finish7_1.set_pos(500, 500, 1,1);
		finish_7.push_back(finish7_1);
		//Level8
		Block8_1.set_pos(234, 280, 0.3, 0.3);
		Block8_2.set_pos(234, 280, 0.3, 0.3);
		normal_block8.push_back(Block8_1);
		normal_block8.push_back(Block8_2);
		finish8_1.set_pos(500, 500, 1, 1);
		finish_8.push_back(finish8_1);
		//Level9
		Block9_1.set_pos(400, 280, 0.3, 0.3);
		Block9_2.set_pos(400, 280, 0.3, 0.3);
		normal_block9.push_back(Block9_1);
		normal_block9.push_back(Block9_2);
		finish9_1.set_pos(500, 500, 1, 1);
		finish_9.push_back(finish9_1);
		
		//TEST
		std::string filename_block = "Brick_Blocks.png";
		std::string filename = "clouds.png";
		cloud_anim = Gosu::load_tiles(filename, 666, 300);

	}

	void update() override //ca. 60x pro Sekunde
	{
		mouse.mouse(input().mouse_x(), input().mouse_y());
		if (menuing == true) {
			backtomenu = false;
			if (menu.pressedButton(1, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level1 = true;
				menuing = false;
				graphics().draw_line(0, 0, Gosu::Color::RED, 800, 600, Gosu::Color::RED, Z_UI);
			}
			if (menu.pressedButton(1, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level1= true;
				menuing = false;
			}
			if (menu.pressedButton(2, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level2 = true;
				menuing = false;
			}
			if (menu.pressedButton(3, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level3 = true;
				menuing = false;
			}
			if (menu.pressedButton(4, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level4 = true;
				menuing = false;
			}
			if (menu.pressedButton(5, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level5 = true;
				menuing = false;
			}
			if (menu.pressedButton(6, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level6 = true;
				menuing = false;
			}
			if (menu.pressedButton(7, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level7 = true;
				menuing = false;
			}
			if (menu.pressedButton(8, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level8 = true;
				menuing = false;
			}
			if (menu.pressedButton(9, mouse, input().down(Gosu::MS_LEFT), menu)) {
				Level9 = true;
				menuing = false;
			}
		}
		if (menuing == false) {
			if (Level1 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block1.at(0).set_pos_left();
						normal_block1.at(1).set_pos_left();
						finish_1.at(0).set_pos_left();


					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block1.at(0).set_pos_right();
						normal_block1.at(1).set_pos_right();
						finish_1.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block1, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block1.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block1, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block1.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block1, 0) == false && player.topBlock(normal_block1, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level2 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block2.at(0).set_pos_left();
						normal_block2.at(1).set_pos_left();
						finish_2.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block2.at(0).set_pos_right();
						normal_block2.at(1).set_pos_right();
						finish_2.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block2, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block2.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block2, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block2.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block2, 0) == false && player.topBlock(normal_block2, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level3 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block3.at(0).set_pos_left();
						normal_block3.at(1).set_pos_left();
						finish_3.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block3.at(0).set_pos_right();
						normal_block3.at(1).set_pos_right();
						finish_3.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block3, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block3.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block3, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block3.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block3, 0) == false && player.topBlock(normal_block3, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level4 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block4.at(0).set_pos_left();
						normal_block4.at(1).set_pos_left();
						finish_4.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block4.at(0).set_pos_right();
						normal_block4.at(1).set_pos_right();
						finish_4.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block4, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block4.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block4, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block4.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block4, 0) == false && player.topBlock(normal_block4, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level5 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block5.at(0).set_pos_left();
						normal_block5.at(1).set_pos_left();
						finish_5.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block5.at(0).set_pos_right();
						normal_block5.at(1).set_pos_right();
						finish_5.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block5, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block5.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block5, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block5.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block5, 0) == false && player.topBlock(normal_block5, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level6 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block6.at(0).set_pos_left();
						normal_block6.at(1).set_pos_left();
						finish_6.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block6.at(0).set_pos_right();
						normal_block6.at(1).set_pos_right();
						finish_6.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block6, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block6.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block6, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block6.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block6, 0) == false && player.topBlock(normal_block6, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level7 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block7.at(0).set_pos_left();
						normal_block7.at(1).set_pos_left();
						finish_7.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block7.at(0).set_pos_right();
						normal_block7.at(1).set_pos_right();
						finish_7.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block7, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block7.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block7, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block7.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block7, 0) == false && player.topBlock(normal_block7, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level8 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block8.at(0).set_pos_left();
						normal_block8.at(1).set_pos_left();
						finish_8.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block8.at(0).set_pos_right();
						normal_block8.at(1).set_pos_right();
						finish_8.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block8, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block8.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block8, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block8.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block8, 0) == false && player.topBlock(normal_block8, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
			if (Level9 == true) {
				frames++;
				if (frames % 60 == 0) {
					playtime++;
				}
				menuing = false;
				player.score_set_down(playtime);
				if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
				{
					//***************RECHTS*******************
					if (player.actual_pos_x() <= (width() - 120))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_right();
					}
					if (player.actual_pos_x() > (width() - 120))//wenn Spieler heruslaufen würde
					{
						background.move_left();
						normal_block9.at(0).set_pos_left();
						normal_block9.at(1).set_pos_left();
						finish_9.at(0).set_pos_left();
					}

				}
				if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
				{
					//***************LINKS*******************
					if (player.actual_pos_x() >= 120)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
					{
						player.turn_left();
					}
					if (player.actual_pos_x() < 120)//wenn Spieler heruslaufen würde
					{
						background.move_right();
						normal_block9.at(0).set_pos_right();
						normal_block9.at(1).set_pos_right();
						finish_9.at(0).set_pos_right();
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
				if (player.actual_pos_y() >= (ground.get_Ground() - 1)) //Wenn Spieler den Boden wieder berührt
				{
					player.resetJumpTime();//Resete die Sprungdauer
				}
				if (player.topBlock(normal_block9, 0) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block9.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block9, 1) && player.get_jumptime() > 0.5)//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block9.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block9, 0) == false && player.topBlock(normal_block9, 1) == false && player.get_jump() == false) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
				if (player.actual_pos_y() > ground.get_Ground() + 2) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
				{
					player.set_pos(player.actual_pos_x(), ground.get_Ground());
					player.jumpposition();
				}

				//TEST
				if (std::rand() % 25 == 0 && clouds.size() < 5)
				{
					clouds.push_back(Cloud(cloud_anim));
				}

				pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation
			}
		}

		if (menu.pressedMenuButton(mouse, input().down(Gosu::MS_LEFT)) && menuing == false) {
			menuing = true;
			backtomenu = true;
		}
		//Berechnet FPS
		fps.update();
	}
	void draw() override //ca. 60x pro Sekunde
	{


		//*****Die Blöcke müssen beim zurücksetzen in das menü noch gelöscht werden und der spieler und die Punktzahl zurückgesetzt werden

		if (menuing == true) //wenn das Menü da sein soll
		{
			menu.Background();//drawt den Background
			menu.Level(1, "Level1"); //drawt den Text für das Level
			menu.Level(2, "Level2"); //drawt den Text für das Level
			menu.Level(3, "Level3"); //drawt den Text für das Level
			menu.Level(4, "Level4"); //drawt den Text für das Level
			menu.Level(5, "Level5"); //drawt den Text für das Level
			menu.Level(6, "Level6"); //drawt den Text für das Level
			menu.Level(7, "Level7"); //drawt den Text für das Level
			menu.Level(8, "Level8"); //drawt den Text für das Level
			menu.Level(9, "Level9"); //drawt den Text für das Level
		}
		mouse.draw();
		player.draw(); //drawt den player
		player.score_draw();
		pet_1.draw(player.direction()); //draw pet_1

		background.draw(); //drawt den Background
		if (menuing == false) {
			menu.menu_button();
		}
		if (Level1 == true && menuing == false) {
				for (size_t i = 0; i < normal_block1.size(); i++) {
					normal_block1.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_1.at(0).draw_finish(0);
		}
		if (Level2 == true && menuing == false) {
				for (size_t i = 0; i < normal_block2.size(); i++) {
					normal_block2.at(i).draw_Blocks(1); //drawt einen Block
				}
				finish_2.at(0).draw_finish(0);
		}
		if (Level3 == true && menuing == false) {
				for (size_t i = 0; i < normal_block3.size(); i++) {
					normal_block3.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_3.at(0).draw_finish(0);
		}
		if (Level4 == true && menuing == false) {
				for (size_t i = 0; i < normal_block4.size(); i++) {
					normal_block4.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_4.at(0).draw_finish(0);
		}
		if (Level5 == true && menuing == false) {
				for (size_t i = 0; i < normal_block5.size(); i++) {
					normal_block5.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_5.at(0).draw_finish(0);
		}
		if (Level6 == true && menuing == false) {
				for (size_t i = 0; i < normal_block6.size(); i++) {
					normal_block6.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_6.at(0).draw_finish(0);
		}
		if (Level7 == true && menuing == false) {
				for (size_t i = 0; i < normal_block7.size(); i++) {
					normal_block7.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_7.at(0).draw_finish(0);
		}
		if (Level8 == true && menuing == false) {
				for (size_t i = 0; i < normal_block8.size(); i++) {
					normal_block8.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_8.at(0).draw_finish(0);
		}
		if (Level9 == true && menuing == false) {
				for (size_t i = 0; i < normal_block9.size(); i++) {
					normal_block9.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_9.at(0).draw_finish(0);
			}
		
		
	

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


