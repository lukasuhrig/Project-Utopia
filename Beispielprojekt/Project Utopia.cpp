#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <ctime>

#include <Gosu/GraphicsBase.hpp>

#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;


//**********************FUNCTIONS**********************//





//**********************KLASSEN**********************//



//**********************Hilfsklassen für FPS-Berechnung**********************//
class Interval
{
private:
	unsigned int initial_;

public:
	// Ctor
	inline Interval() : initial_(GetTickCount64())
	{
	}

	// Dtor
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
	// Constructor
	Fps() : m_fps(0), m_fpscount(0)
	{
	}

	// Update
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

	// Get fps
	unsigned int get() const
	{
		return m_fps;
	}
};
//**********************Hilfsklassen für FPS-Berechnung ENDE**********************//



class Player
{
	Gosu::Image character;

	double pos_x;
	double pos_y;
	double rot;
	bool lookingRight;
	float health;
	unsigned score;
	double jumptime = 0;

public:
	Player() : character("player1.png")
	{
		pos_x = pos_y = score = rot = 0;
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
	void tilt_left() {
		if (rot > -15.0) {
			rot = rot - 1.0;
		}
	}
	void tilt_right() {
		if (rot < 15.0) {
			rot = rot + 1.0;
		}
	}
	void reset_rot() {
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
		character.draw_rot(pos_x, pos_y, 0.1,	//Position
			rot,					//rotation
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
	double shift = 0;
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
	void draw()
	{
		background_image.draw_rot(pos_x + shift, pos_y, 0.0, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift + 1025, pos_y, 0.0, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift + 2050, pos_y, 0.0, 0.0, 0.5, 1);
		background_image.draw_rot(pos_x + shift + 3075, pos_y, 0.0, 0.0, 0.5, 1);
			if (int32_t(pos_x)%2050==0 && pos_x!=0) {

				shift = shift - pos_x;
			}
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

	GameWindow() : Window(800, 600),fps_anzeige(20)
	{
		set_caption("Project Utopia");

		player.set_pos(100, 500);
		background.set_pos(300, 500);
	}

	void update() override //ca. 60x pro Sekunde
	{
		if (input().down(Gosu::KB_D) == true && player.actual_pos_x() <= (width() - 100))
		{
			player.turn_right();
			player.tilt_right();
		}

		if (input().down(Gosu::KB_D) == true && player.actual_pos_x() > (width() - 100))
		{
			background.move_left();
			player.tilt_right();
		}

		if (input().down(Gosu::KB_A) == true && player.actual_pos_x() >= 100)
		{
			player.turn_left();
			player.tilt_left();
		}

		if (input().down(Gosu::KB_A) == true && player.actual_pos_x() < 100)
		{
			background.move_right();
			player.tilt_left();
		}

		if (input().down(Gosu::KB_W) == true || player.actual_pos_y() < (height() - 101))
		{
			player.jump();
		}

		if (input().down(Gosu::KB_A) == false && input().down(Gosu::KB_D) == false) {
			player.reset_rot();
		}

		if (player.actual_pos_y() >= (height() - 101))
		{
			player.resetJumpTime();
		}

		//Berechnet FPS
		fps.update();
	}
	void draw() override //ca. 60x pro Sekunde
	{

		player.draw();
		background.draw();

		//MERKER: Erstellen von Enum für Reihenfolge von Images/fonts
		fps_anzeige.draw("FPS: " + std::to_string(fps.get()), 15, 15, 1, //Die 1 ist die Reihenfolge in diesem Fall
			1, 1, Gosu::Color::YELLOW);
		
		graphics().draw_quad(
			0, 500, Gosu::Color::GREEN,
			800, 500, Gosu::Color::WHITE,
			800, 600, Gosu::Color::WHITE,
			0, 600, Gosu::Color::GREEN,
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


