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
	bool halfSecond()
	{
		if (interval1.value() > 500)
		{
			interval1 = interval();
			return true;
		}
		return false;
	}
	bool quarterSecond()
	{
		if (interval1.value() > 250)
		{
			interval1 = interval();
			return true;
		}
		return false;
	}
	bool milliSecond()
	{
		if (interval1.value() > 1)
		{
			interval1 = interval();
			return true;
		}
		return false;
	}
};


