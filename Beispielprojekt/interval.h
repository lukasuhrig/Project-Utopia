#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class interval
{
private:
	unsigned int initial_;

public:
	inline interval() : initial_(GetTickCount64())
	{
	}

	virtual ~interval()
	{
	}

	inline unsigned int value() const
	{
		return GetTickCount64() - initial_;
	}
};

