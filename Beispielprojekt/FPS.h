#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "interval.h"

class Fps
{
protected:
	unsigned int m_fps;
	unsigned int m_fpscount;
	interval m_fpsinterval;

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
			m_fpsinterval = interval();
		}
	}

	unsigned int get() const
	{
		return m_fps;
	}
};