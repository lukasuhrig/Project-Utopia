#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <ctime>
#include "interval.h"

class m_time
{
protected:

	interval interval1;

public:
	bool oneSecond()
	{
		if (interval1.value() > 1000)
		{
			interval1 = interval();
			return true;
		}
		return false;
	}
};



