#pragma once
#include "FlyFish.h"

class Point
{

public:
	Vector3f	position;

	static Point		ToEnginePoint(const TriVector& tv);
	static TriVector	ToPGAPoint(const Point& p);

private:

};

