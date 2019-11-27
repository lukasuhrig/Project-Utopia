#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <Gosu/GraphicsBase.hpp>

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>

#include <thread>
#include <chrono>

#include "m_time.h"


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
#include "Game.h"
//#include "Vektor2d.h"
#include "pet.h"

// Simulationsgeschwindigkeit
double position_in_window=400; // hier wird die Breite des Bildschirms bestimmt in welchem sich der Spieler frei bewegen kann ohne das der Hintergrund mitbewegt wird.
const double DT = 100.0;
bool menuing =true;
bool backtomenu=false;


bool won = false;
bool won1= false;
bool won2 = false;
bool won3 = false;
bool won4 = false;
bool won5 = false;
bool won6 = false;
bool won7 = false;
bool won8 = false;
bool won9 = false;
int64_t frames=0;
int64_t playtime = 0;
//FPS
Fps fps;
//time
m_time zeit;

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
	Game game;
	Pet pet_1; //Erstellen Pet
	
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
	
	//Animation_Blocks Animation_Block;
	Menu menu;

	

	GameWindow() : Window(800, 600),fps_anzeige(20)
	{
		set_caption("Project Utopia");

		player.set_pos(400, ground.get_Ground());
		pet_1.set_pos((player.actual_pos_x() - 80), (player.actual_pos_y() - 80));

		background.set_pos(300, ground.get_Ground());
		//Auslagern sobald alles richtig funktioniert
		//Level1
		Block1_1.set_pos(100, 380, 0.3, 0.3);
		Block1_2.set_pos(100, 180, 0.3, 0.3);
		normal_block1.push_back(Block1_1);
		normal_block1.push_back(Block1_2);
		finish1_1.set_pos(500, 500);
		finish_1.push_back(finish1_1);
		//Level2
		Block2_1.set_pos(200, 380, 0.3, 0.3);
		Block2_2.set_pos(200, 180, 0.3, 0.3);
		normal_block2.push_back(Block2_1);
		normal_block2.push_back(Block2_2);
		finish2_1.set_pos(500, 500);
		finish_2.push_back(finish2_1);
		//Level3
		Block3_1.set_pos(300, 380, 0.3, 0.3);
		Block3_2.set_pos(300, 180, 0.3, 0.3);
		normal_block3.push_back(Block3_1);
		normal_block3.push_back(Block3_2);
		finish3_1.set_pos(500, 500);
		finish_3.push_back(finish3_1);
		//Level4
		Block4_1.set_pos(400, 380, 0.3, 0.3);
		Block4_2.set_pos(400, 180, 0.3, 0.3);
		normal_block4.push_back(Block4_1);
		normal_block4.push_back(Block4_2);
		finish4_1.set_pos(500, 500);
		finish_4.push_back(finish4_1);
		//Level5
		Block5_1.set_pos(500, 380, 0.3, 0.3);
		Block5_2.set_pos(500, 180, 0.3, 0.3);
		normal_block5.push_back(Block5_1);
		normal_block5.push_back(Block5_2);
		finish5_1.set_pos(500, 500);
		finish_5.push_back(finish5_1);
		//Level6
		Block6_1.set_pos(600, 380, 0.3, 0.3);
		Block6_2.set_pos(600, 180, 0.3, 0.3);
		normal_block6.push_back(Block6_1);
		normal_block6.push_back(Block6_2);
		finish6_1.set_pos(500, 500);
		finish_6.push_back(finish6_1);
		//Level7
		Block7_1.set_pos(700, 380, 0.3, 0.3);
		Block7_2.set_pos(700, 180, 0.3, 0.3);
		normal_block7.push_back(Block7_1);
		normal_block7.push_back(Block7_2);
		finish7_1.set_pos(500, 500);
		finish_7.push_back(finish7_1);
		//Level8
		Block8_1.set_pos(234, 280, 0.3, 0.3);
		Block8_2.set_pos(234, 280, 0.3, 0.3);
		normal_block8.push_back(Block8_1);
		normal_block8.push_back(Block8_2);
		finish8_1.set_pos(500, 500);
		finish_8.push_back(finish8_1);
		//Level9
		Block9_1.set_pos(400, 280, 0.3, 0.3);
		Block9_2.set_pos(400, 280, 0.3, 0.3);
		normal_block9.push_back(Block9_1);
		normal_block9.push_back(Block9_2);
		finish9_1.set_pos(500, 500);
		finish_9.push_back(finish9_1);
		

		std::string filename_block = "Brick_Blocks.png";

	}

	void update() override //ca. 60x pro Sekunde
	{
		mouse.mouse(input().mouse_x(), input().mouse_y());
		if (menuing == true) {
			backtomenu = false;
			if (menu.pressedButton(1, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(1, true);
				menuing = false;
			}
			if (menu.pressedButton(2, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(2, true);
				menuing = false;
			}
			if (menu.pressedButton(3, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(3, true);
				menuing = false;
			}
			if (menu.pressedButton(4, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(4, true);
				menuing = false;
			}
			if (menu.pressedButton(5, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(5, true);
				menuing = false;
			}
			if (menu.pressedButton(6, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(6, true);
				menuing = false;
			}
			if (menu.pressedButton(7, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(7, true);
				menuing = false;
			}
			if (menu.pressedButton(8, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(8, true);
				menuing = false;
			}
			if (menu.pressedButton(9, mouse, input().down(Gosu::MS_LEFT), menu)) {
				game.set_Level(9, true);
				menuing = false;
			}
		}
		if (menuing == false&&!won) {
			if (input().down(Gosu::KB_SPACE) == true) //Taste SPACE
			{
				player.shoot();
			}

			if (input().down(Gosu::KB_D) == true && input().down(Gosu::KB_A) == false) //Taste D und nicht Taste A
			{
				//***************RECHTS*******************
				if (player.actual_pos_x() <= (width() - position_in_window))//wenn spieler in dem Feld ist, in dem er sich bewegen kann
				{
					player.turn_right();
				}
				if (player.actual_pos_x() >= (width() - position_in_window))//wenn Spieler heruslaufen würde
				{
					background.move_left();
					for(size_t i=0;i<normal_block1.size();i++)
					{
						normal_block1.at(i).set_pos_left(); 
					}
					for (size_t i = 0; i < normal_block2.size(); i++)
					{
						normal_block2.at(i).set_pos_left();
					}
					for (size_t i = 0; i < normal_block3.size(); i++)
					{
						normal_block3.at(i).set_pos_left();
					}
					for (size_t i = 0; i < normal_block4.size(); i++)
					{
						normal_block4.at(i).set_pos_left();
					}
					for (size_t i = 0; i < normal_block5.size(); i++)
					{
						normal_block5.at(i).set_pos_left();
					for (size_t i = 0; i < normal_block6.size(); i++)
					{
						normal_block6.at(i).set_pos_left();
					}
					for (size_t i = 0; i < normal_block7.size(); i++)
					{
						normal_block7.at(i).set_pos_left();
					}
					for (size_t i = 0; i < normal_block8.size(); i++)
					{
						normal_block8.at(i).set_pos_left();
					}
					for (size_t i = 0; i < normal_block9.size(); i++)
					{
						normal_block9.at(i).set_pos_left();
					}
					}
					
					finish_1.at(0).set_pos_left();
					finish_2.at(0).set_pos_left();
					finish_3.at(0).set_pos_left();
					finish_4.at(0).set_pos_left();
					finish_5.at(0).set_pos_left();
					finish_6.at(0).set_pos_left();
					finish_7.at(0).set_pos_left();
					finish_8.at(0).set_pos_left();
					finish_9.at(0).set_pos_left();


				}

			}
			if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == false) //Taste A und nicht Taste D
			{
				//***************LINKS*******************
				if (player.actual_pos_x() >= position_in_window)//wenn spieler in dem Feld ist, in dem er sich bewegen kann
				{
					player.turn_left();
				}
				if (player.actual_pos_x() < position_in_window)//wenn Spieler heruslaufen würde
				{
					background.move_right();
					for (size_t i = 0; i < normal_block1.size(); i++)
					{
						normal_block1.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block2.size(); i++)
					{
						normal_block2.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block3.size(); i++)
					{
						normal_block3.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block4.size(); i++)
					{
						normal_block4.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block5.size(); i++)
					{
						normal_block5.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block6.size(); i++)
					{
						normal_block6.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block7.size(); i++)
					{
						normal_block7.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block8.size(); i++)
					{
						normal_block8.at(i).set_pos_right();
					}
					for (size_t i = 0; i < normal_block9.size(); i++)
					{
						normal_block9.at(i).set_pos_right();
					}
					

					finish_1.at(0).set_pos_right();
					finish_2.at(0).set_pos_right();
					finish_3.at(0).set_pos_right();
					finish_4.at(0).set_pos_right();
					finish_5.at(0).set_pos_right();
					finish_6.at(0).set_pos_right();
					finish_7.at(0).set_pos_right();
					finish_8.at(0).set_pos_right();
					finish_9.at(0).set_pos_right();

				}

			}
			if (input().down(Gosu::KB_A) == true && input().down(Gosu::KB_D) == true) // Wenn Taste A und D gedrückt werden, stoppt der Spieler
			{
				player.stop();
			}
			if ((input().down(Gosu::KB_W) == true || player.get_jump() == true)/* && player.get_drop()==false*/) //wenn Taste W gedrückt wurde, oder die Sprungfunktion noch nicht beendet wurde
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
			if (player.actual_pos_y() >= (ground.get_Ground() - 5)) //Wenn Spieler den Boden wieder berührt
			{
				player.resetJumpTime();//Resete die Sprungdauer
			}
			if (player.actual_pos_y() > ground.get_Ground() + 5) //wenn der Spieler durch den Boden glitcht setzt es ihn wieder auf den Boden
			{
				player.set_pos(player.actual_pos_x(), ground.get_Ground());
				player.jumpposition();

			}

			pet_1.update(player.direction(), player.actual_pos_x(), player.actual_pos_y(), player.isIdle()); //PET Animation

			if (game.get_Level(1) &&!finish_1.at(0).reached_finish(player.actual_pos_x(),player.actual_pos_y())) {

				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}

				menuing = false;
		
				
				if (player.topBlock(normal_block1, 0) && (player.get_jumptime() > 0.5 || player.get_drop()==true))//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block1.at(0).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes
				}
				if (player.topBlock(normal_block1, 1) && (player.get_jumptime() > 0.5 || player.get_drop() == true))//sodass er nicht gleich mit der Sprungfunktion ab dem block weitermacht, sondern erst landen muss
				{
					player.set_pos(player.actual_pos_x(), normal_block1.at(1).y_pos()); //setzt den Spieler ordentlich auf den Block
					player.resetJumpTime();//Resete die Sprungdauer
					player.jumpposition();//Setzt die Absrpunghöhe auf Höhe des Blockes

				}
				if (player.topBlock(normal_block1, 0) == false && player.topBlock(normal_block1, 1) == false && player.get_jump() == false && player.actual_pos_y()<ground.get_Ground()+3) //und der Spieler nicht abspringen will
				{
					player.drop(); //Spieler fällt
				}
			
			}
			if (game.get_Level(2) && !finish_2.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&&game.get_wonLevel(1)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}
				menuing = false;
				
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
			
			}
			if (game.get_Level(3) && !finish_3.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&& game.get_wonLevel(2)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}
				menuing = false;
				
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
				
			}
			if (game.get_Level(4) && !finish_4.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&& game.get_wonLevel(3)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}
				menuing = false;
				
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
				
			}
			if (game.get_Level(5) && !finish_5.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&& game.get_wonLevel(4)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}
				menuing = false;
				
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
				
			}
			if (game.get_Level(6) && !finish_6.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&& game.get_wonLevel(5)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}
				menuing = false;
				
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
			
			}
			if (game.get_Level(7) && !finish_7.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&& game.get_wonLevel(6)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}
				menuing = false;
			
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
			
			}
			if (game.get_Level(8) && !finish_8.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&& game.get_wonLevel(7)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
				}
				menuing = false;
				
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
			
			}
			if (game.get_Level(9) && !finish_9.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&& game.get_wonLevel(8)) {
				if ((zeit.milliSecond()) == true)
				{
					player.score_set_down(1);
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
				
			}
		}

		if ((menu.pressedMenuButton(mouse, input().down(Gosu::MS_LEFT)) || menu.pressedwinMenuButton(mouse, input().down(Gosu::MS_LEFT)))&& menuing == false) {
			menuing = true;
			won = false;
			backtomenu = true;
			for (int i = 1; i <= 9; i++) { game.set_Level(i, false); };
			player.reset(ground.get_Ground()-1);
			background.reset(ground.get_Ground());
			pet_1.set_pos((player.actual_pos_x() - 80), (player.actual_pos_y() - 80));
			{
			for (size_t i = 0; i < normal_block1.size(); i++) {
				normal_block1.at(i).reset();
			}
			for (size_t i = 0; i < normal_block2.size(); i++) {
				normal_block2.at(i).reset();
			}
			for (size_t i = 0; i < normal_block3.size(); i++) {
				normal_block3.at(i).reset();
			}
			for (size_t i = 0; i < normal_block4.size(); i++) {
				normal_block4.at(i).reset();
			}
			for (size_t i = 0; i < normal_block5.size(); i++) {
				normal_block5.at(i).reset();
			}
			for (size_t i = 0; i < normal_block6.size(); i++) {
				normal_block6.at(i).reset();
			}
			for (size_t i = 0; i < normal_block7.size(); i++) {
				normal_block7.at(i).reset();
			}
			for (size_t i = 0; i < normal_block8.size(); i++) {
				normal_block8.at(i).reset();
			}
			for (size_t i = 0; i < normal_block9.size(); i++) {
				normal_block9.at(i).reset();
			}
			for (size_t i = 0; i < finish_1.size(); i++) {
				finish_1.at(i).reset();
			}
			for (size_t i = 0; i < finish_2.size(); i++) {
				finish_2.at(i).reset();
			}
			for (size_t i = 0; i < finish_3.size(); i++) {
				finish_3.at(i).reset();
			}
			for (size_t i = 0; i < finish_4.size(); i++) {
				finish_4.at(i).reset();
			}
			for (size_t i = 0; i < finish_5.size(); i++) {
				finish_5.at(i).reset();
			}
			for (size_t i = 0; i < finish_6.size(); i++) {
				finish_6.at(i).reset();
			}
			for (size_t i = 0; i < finish_7.size(); i++) {
				finish_7.at(i).reset();
			}
			for (size_t i = 0; i < finish_8.size(); i++) {
				finish_8.at(i).reset();
			}
			for (size_t i = 0; i < finish_9.size(); i++) {
				finish_9.at(i).reset();
			}
			}//RESET
		}
	

		if (finish_1.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&&game.get_Level(1)) {
			game.set_wonLevel(1,true);
			won = true;
		}
		if (finish_2.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(2)) {
			game.set_wonLevel(2, true);
			won = true;
		}
		if (finish_3.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(3)) {
			game.set_wonLevel(3, true);
			won = true;
		}
		if (finish_4.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(4)) {
			game.set_wonLevel(4, true);
			won = true;
		}
		if (finish_5.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(5)) {
			game.set_wonLevel(5, true);
			won = true;
		}
		if (finish_6.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(6)) {
			game.set_wonLevel(6, true);
			won = true;
		}
		if (finish_7.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(7)) {
			game.set_wonLevel(7, true);
			won = true;
		}
		if (finish_8.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(8)) {
			game.set_wonLevel(8, true);
			won = true;
		}
		if (finish_9.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(9)) {
			game.set_wonLevel(8, true);
			won = true;
		}
		//Berechnet FPS
		fps.update();
		zeit.milliSecond();

		//update für player
		player.update();
	}
	void draw() override //ca. 60x pro Sekunde
	{	
		mouse.draw();
		player.draw(); //drawt den player
		player.score_draw();
		pet_1.draw(player.direction()); //draw pet_1
		background.draw(); //drawt den Background

		//*****Die Blöcke müssen beim zurücksetzen in das menü noch gelöscht werden und der spieler und die Punktzahl zurückgesetzt werden

		if (menuing == true) //wenn das Menü da sein soll
		{
			menu.Background();//drawt den Background
			menu.Level(1, "Level1"); //drawt den Text für das Level
			if (game.get_wonLevel(1)) {
				menu.Level(2, "Level2"); //drawt den Text für das Level
			}
			if (game.get_wonLevel(2)) {
				menu.Level(3, "Level3"); //drawt den Text für das Level
			}
			if (game.get_wonLevel(3)) {
				menu.Level(4, "Level4"); //drawt den Text für das Level
			}
			if (game.get_wonLevel(4)) {
				menu.Level(5, "Level5"); //drawt den Text für das Level
			}
			if (game.get_wonLevel(5)) {
				menu.Level(6, "Level6"); //drawt den Text für das Level
			}
			if (game.get_wonLevel(6)) {
				menu.Level(7, "Level7"); //drawt den Text für das Level
			}
			if (game.get_wonLevel(7)) {
				menu.Level(8, "Level8"); //drawt den Text für das Level
			}
			if (game.get_wonLevel(8)) {
				menu.Level(9, "Level9"); //drawt den Text für das Level
			}
			
		}
		

		
		if (menuing == false ) {
			menu.menu_button();
		}
		if (game.get_Level(1) && menuing == false) {
				for (size_t i = 0; i < normal_block1.size(); i++) {
					normal_block1.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_1.at(0).draw_finish();
		}
		if (game.get_Level(2) && menuing == false) {
				for (size_t i = 0; i < normal_block2.size(); i++) {
					normal_block2.at(i).draw_Blocks(1); //drawt einen Block
				}
				finish_2.at(0).draw_finish();
		}
		if (game.get_Level(3) && menuing == false) {
				for (size_t i = 0; i < normal_block3.size(); i++) {
					normal_block3.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_3.at(0).draw_finish();
		}
		if (game.get_Level(4) && menuing == false) {
				for (size_t i = 0; i < normal_block4.size(); i++) {
					normal_block4.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_4.at(0).draw_finish();
		}
		if (game.get_Level(5) && menuing == false) {
				for (size_t i = 0; i < normal_block5.size(); i++) {
					normal_block5.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_5.at(0).draw_finish();
		}
		if (game.get_Level(6) && menuing == false) {
				for (size_t i = 0; i < normal_block6.size(); i++) {
					normal_block6.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_6.at(0).draw_finish();
		}
		if (game.get_Level(7) && menuing == false) {
				for (size_t i = 0; i < normal_block7.size(); i++) {
					normal_block7.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_7.at(0).draw_finish();
		}
		if (game.get_Level(8) && menuing == false) {
				for (size_t i = 0; i < normal_block8.size(); i++) {
					normal_block8.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_8.at(0).draw_finish();
		}
		if (game.get_Level(9) && menuing == false) {
				for (size_t i = 0; i < normal_block9.size(); i++) {
					normal_block9.at(i).draw_Blocks(0); //drawt einen Block
				}
				finish_9.at(0).draw_finish();
			}
		
		if (finish_1.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y())&&game.get_Level(1)&&menuing==false)  {
			finish_1.at(0).finished(player.get_score());
			
		}
		if (finish_2.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(2) && menuing == false) {
			finish_2.at(0).finished(player.get_score());
		
		}
		if (finish_3.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(3) && menuing == false) {
			finish_3.at(0).finished(player.get_score());

		}
		if (finish_4.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(4) && menuing == false) {
			finish_4.at(0).finished(player.get_score());

		}
		if (finish_5.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(5) && menuing == false) {
			finish_5.at(0).finished(player.get_score());

		}
		if (finish_6.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(6) && menuing == false) {
			finish_6.at(0).finished(player.get_score());

		}
		if (finish_7.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(7)&&menuing == false) {
			finish_7.at(0).finished(player.get_score());

		}
		if (finish_8.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(8)&&menuing == false) {
			finish_8.at(0).finished(player.get_score());

		}
		if (finish_9.at(0).reached_finish(player.actual_pos_x(), player.actual_pos_y()) && game.get_Level(9) &&menuing==false ) {
			finish_9.at(0).finished(player.get_score());
		}
	
		fps_anzeige.draw("FPS: " + std::to_string(fps.get()), 15, 15, Z_UI, 1, 1, Gosu::Color::RED);
		ground.draw();
	
	}
	
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
	
}


//*****************************Funktionen*****************************//


