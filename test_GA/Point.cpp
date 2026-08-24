#include "pch.h"
#include "Point.h"

Point Point::ToEnginePoint(const TriVector& tv) 
{
	const float w{ tv.e123() };
	return Point{ tv.e032() / w, tv.e013() / w, tv.e021() / w };
}

TriVector Point::ToPGAPoint(const Point& p) 
{
	return TriVector{
		p.position.x,
		p.position.y,
		p.position.z,
		1.0f
	};
}

Point Point::operator+ (const Point& p) const
{
	return Point{ p.position.x + position.x, p.position.y + position.y, p.position.z + position.z };
}