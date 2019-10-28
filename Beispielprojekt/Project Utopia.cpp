#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(800, 600)
		,bild("HELD.png")

	{
		set_caption("Project Utopia");
	}
	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	double x = 100;
	double hintergrund_x = 100;
	double y = 500;
	double jumptime = 0;
	void update() override
	{
		if (input().down(Gosu::KB_D) == true &&x<=700) {
			x = x + 10;
		}
		if (input().down(Gosu::KB_D) == true && x > 700) {
			hintergrund_x = hintergrund_x - 10;
		}
		if (input().down(Gosu::KB_A) == true && x >= 100) {
			x = x - 10;
		}
		if (input().down(Gosu::KB_A) == true && x < 100) {
			hintergrund_x = hintergrund_x + 10;
		}
		if (input().down(Gosu::KB_W) == true||y<499) {

			jumptime=jumptime+(1.0/60.0);
	
				if (y != 200&&y<=500) {
					y = 499+jumptime*jumptime*1000-900*jumptime;
				};

		}
		if (y >= 499) {
			jumptime = 0;
		}

		
	}
	void draw() override
	{
	
			bild.draw_rot(x, y, 0.0,	//Position
				0.0,					//rotation
				0.5, 1					//Position in relation zu der angegebenen POsition
			); 
			
		Gosu::Image("Background.png").draw_rot(hintergrund_x, 200, 0.0,
				0.0,
				0.5,1
				

			);
		
			
		graphics().draw_quad(
			0, 500, Gosu::Color::WHITE,
			800, 500, Gosu::Color::WHITE,
			800, 600, Gosu::Color::WHITE,
			0, 600, Gosu::Color::WHITE,
			0.0
		);
	}

	// Wird 60x pro Sekunde aufgerufen
	
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
