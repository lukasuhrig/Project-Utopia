#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>

#include <Gosu/GraphicsBase.hpp>

#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;


//**********************ENUMS**********************//

enum ZOrder //Reihenfolge von Elementen
{
	Z_BACKGROUND,
	Z_OBJECT,
	Z_PLAYER,
	Z_Blocks,
	Z_UI //Text etc.
};


//**********************FUNCTIONS**********************//





//**********************KLASSEN**********************//



//**********************Hilfsklassen für FPS-Berechnung**********************//
class Blocks
{
	std::vector<Gosu::Image> Block; // hier werden alle Images gespeichert, die Images sollten eine ähnliche größe haben.
	double pos_x;
	double pos_y;
	double block_look;		// Nummer des Images welches man aufrufen will

public:
	void set_pos_left()
	{
		pos_x = pos_x - 10; 
	}
	void set_pos_right()
	{
		pos_x = pos_x + 10;
	}
	//WIR WAREN HIER!!
	void draw_Blocks() {
		Block.at(block_look).draw_rot(pos_x, pos_y, Z_Blocks, // Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
			0,
			1,
			1,
			1, //Skalierung Charakter X
			1 //Skalierung Charakter Y
		);

	}

};
class Block_Look : Blocks {

public:
		
};
class Interval
{
private:
	unsigned int initial_;

public:
	inline Interval() : initial_(GetTickCount64())
	{
	}

	virtual ~Interval()
	{
	}

	inline unsigned int value() const
	{
		return GetTickCount64() - initial_;
	}
};
class Fps
{
protected:
	unsigned int m_fps;
	unsigned int m_fpscount;
	Interval m_fpsinterval;

public:

	Fps() : m_fps(0), m_fpscount(0)
	{
	}

	void update()
	{
		// increase the counter by one
		m_fpscount++;

		// one second elapsed? (= 1000 milliseconds)
		if (m_fpsinterval.value() > 1000)
		{
			// save the current counter value to m_fps
			m_fps = m_fpscount;

			// reset the counter and the interval
			m_fpscount = 0;
			m_fpsinterval = Interval();
		}
	}

	unsigned int get() const
	{
		return m_fps;
	}
};
//**********************Hilfsklassen für FPS-Berechnung ENDE**********************//



//TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST
typedef std::vector<Gosu::Image> Animation; //Das muss noch als eigene Klasse (Animation) programmiert werden, dazu müsste man sich jedoch mehr Gedanken machen
class Cloud
{
	Animation animation;
	double pos_x, pos_y;

public:
	explicit Cloud(Animation animation) : animation(animation)
	{
		pos_x = Gosu::random(100, 700);
		pos_y = Gosu::random(50, 450);
	}

	double x() const
	{
		return pos_x;
	}

	double y() const
	{
		return pos_y;
	}

	void draw() const
	{
		const Gosu::Image& image = animation.at(Gosu::milliseconds() / 100 % animation.size());

		image.draw(pos_x - image.width() / 2.0, pos_y - image.height() / 2.0, Z_OBJECT,
			0.3,
			0.3
		);
	}

};
//TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST_TEST

class Player
{
	std::vector<Gosu::Image> character;

	double pos_x;
	double pos_y;
	double rot;
	bool lookingRight;
	float health;
	unsigned score;
	double jumptime = 0;

public:
	Player()
	{
		pos_x = pos_y = score = rot  = 0;
		health = 100.0;
		lookingRight = true;
		character = Gosu::load_tiles("player_blue.png", 400, 483);
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
	void tilt_left() 
	{
		if (rot > -15.0) {
			rot = rot - 1.0;
		}
	}
	void tilt_right() 
	{
		if (rot < 15.0) {
			rot = rot + 1.0;
		}
	}
	void reset_rot() 
	{
		if (rot < 0) {
			rot = rot + 3;
		}
		if (rot > 0) {
			rot = rot - 3;
		}
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
		if (lookingRight == true)
		{
			character.at(1).draw_rot(pos_x, pos_y, Z_PLAYER,
				0, 
				1,
				1,
				0.2, //Skalierung Charakter X
				0.2 //Skalierung Charakter Y
			);
		}
		else if (lookingRight == false)
		{
			character.at(0).draw_rot(pos_x, pos_y, Z_PLAYER,
				0,
				1,
				1,
				0.2, //Skalierung Charakter X
				0.2 //Skalierung Charakter Y
			);
		}
	}
	void set_pos(double x, double y)
	{
		pos_x = x;
		pos_y = y;
	}
	double actual_pos_x() const
	{
		return pos_x;
	}
	double actual_pos_y() const
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
	Background() : background_image("background_new.png")
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
		background_image.draw_rot(pos_x, pos_y, Z_BACKGROUND,
			0.0, 0.5, 1);
		background_image.draw_rot(pos_x + 1024, pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x+2048, pos_y, Z_BACKGROUND,
			0.0, 0.5, 1);
		background_image.draw_rot(pos_x + 3072, pos_y, Z_BACKGROUND, 0.0, 0.5, 1);
	}
	void set_pos(double x, double y)
	{
		pos_x = x;
		pos_y = y;
	}
};

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


