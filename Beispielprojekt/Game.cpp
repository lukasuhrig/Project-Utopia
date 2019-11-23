#include "stdafx.h"
#include "Game.h"

//**********************  LEVELMANAGMENT  ***************
void Game::set_Level(int16_t lvl, bool b) {
	switch (lvl) {
	case 1: {Level1 = b; break; }
	case 2: {Level2 = b; break; }
	case 3: {Level3 = b; break; }
	case 4: {Level4 = b; break; }
	case 5: {Level5 = b; break; }
	case 6: {Level6 = b; break; }
	case 7: {Level7 = b; break; }
	case 8: {Level8 = b; break; }
	case 9: {Level9 = b; break; }
	}
}

bool Game::get_Level(int16_t lvl) {
	switch (lvl) {
	case 1: {return Level1; break; }
	case 2: {return Level2; break; }
	case 3: {return Level3; break; }
	case 4: {return Level4; break; }
	case 5: {return Level5; break; }
	case 6: {return Level6; break; }
	case 7: {return Level7; break; }
	case 8: {return Level8; break; }
	case 9: {return Level9; break; }
	}
}

void Game::set_wonLevel(int16_t lvl, bool b) {
	switch (lvl) {
	case 1: {wonLevel1 = b; break; }
	case 2: {wonLevel2 = b; break; }
	case 3: {wonLevel3 = b; break; }
	case 4: {wonLevel4 = b; break; }
	case 5: {wonLevel5 = b; break; }
	case 6: {wonLevel6 = b; break; }
	case 7: {wonLevel7 = b; break; }
	case 8: {wonLevel8 = b; break; }
	case 9: {wonLevel9 = b; break; }
	}
}

bool Game::get_wonLevel(int64_t lvl) {
	switch (lvl) {
	case 1: {return wonLevel1; break; }
	case 2: {return wonLevel2; break; }
	case 3: {return wonLevel3; break; }
	case 4: {return wonLevel4; break; }
	case 5: {return wonLevel5; break; }
	case 6: {return wonLevel6; break; }
	case 7: {return wonLevel7; break; }
	case 8: {return wonLevel8; break; }
	case 9: {return wonLevel9; break; }
	}
}