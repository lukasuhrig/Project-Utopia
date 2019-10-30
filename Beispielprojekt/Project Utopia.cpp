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

//FPS
Fps fps;

class GameWindow : public Gosu::Window
{
	Gosu::Font fps_anzeige;

public:


	Player player;
	Background background;

	GameWindow() : Window(800, 600), fps_anzeige(20)
	{
		set_caption("Project Utopia");

		player.set_pos(100, 500);
		background.set_pos(100, 200);
	}

	void update() override //ca. 60x pro Sekunde
	{
		if (input().down(Gosu::KB_D) == true && player.actual_pos_x() <= (width() - 100))
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

		if (input().down(Gosu::KB_W) == true || player.actual_pos_y() < (height() - 101))
		{
			player.jump();
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


