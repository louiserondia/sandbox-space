#pragma once
#include "FlyFish.h"

class Point
{

public:
	Point() = default;
	Point(float x, float y, float z) : position(Vector3f{ x, y, z }) {}
	Point(const Vector3f pos) : position(pos) {}

	Vector3f	position;

	static Point		ToEnginePoint(const TriVector& tv);
	static TriVector	ToPGAPoint(const Point& p);

	Point operator+ (const Point& p) const;
private:

};

