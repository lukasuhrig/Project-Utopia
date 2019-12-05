#include "stdafx.h"
#include "finish.h"



//******************  DRAW  ********************
void finish::draw_finish() {
	animation_finish.at(0).draw_rot(pos_x, pos_y, Z_Blocks,
		// Blöcke sollen vor allem anderen auf dem Bildschirm angezeigt werden
		0,
		0,
		0.25,
		scale_x, //Skalierung Charakter X
		scale_y //Skalierung Charakter Y
	);

}

void finish::finished(int64_t score) {
	animation_finish.at(1).draw_rot(
		0, -100, Z_Menu_back, 0, 0, 0, 0.78, 0.78
	);
	std::string s = std::to_string(score);
	score_show.draw("Score: " + s, 230, 500, Z_Menu_Text, 3, 3, Gosu::Color::RED);
	menu.menu_button(375, 450);
}

//****************  POSITION  ****************
void finish::set_pos(double x, double y){
	pos_x = urpos_x=x;
	pos_y = urpos_y= y;

}

double finish::x_pos(){
	return pos_x;
}

double finish::y_pos(){
	return pos_y;
}

void finish::set_pos_left() {
	pos_x = pos_x - 10.0;
}

void finish::set_pos_right() {
	pos_x = pos_x + 10.0;
}

void finish::reset() {
	pos_x = urpos_x;
	pos_y = urpos_y;
}

//****************  DIMENSIONS  ****************
double finish::width(){
	return scale_x * 999;
}

double finish::height(){
	return scale_y *614 ;
}

//***************  FINISHED?  ******************
bool finish::reached_finish(double posx, double posy) {
	if ( (posx > pos_x) && (posy > pos_y) && (posx < (pos_x + width())) && (posy < (pos_y + height())) ) {
		
			return true;
		
	}
	else
	{
		return false;
	}
}

