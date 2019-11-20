#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
class Game {
	bool Level1, Level2, Level3, Level4, Level5, Level6, Level7, Level8, Level9;
	bool wonLevel1, wonLevel2, wonLevel3, wonLevel4, wonLevel5, wonLevel6, wonLevel7, wonLevel8, wonLevel9;

public:
	Game() {
		Level1 = Level2 = Level3 = Level4 = Level5 = Level6 = Level7 = Level8 = Level9 = false;
	}
	void set_Level(int16_t lvl, bool b);
	void set_wonLevel(int16_t lvl, bool b);
	bool get_Level(int16_t lvl);
	bool get_wonLevel(int64_t lvl);
};