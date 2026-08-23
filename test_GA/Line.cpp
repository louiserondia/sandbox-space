#include "pch.h"
#include "Line.h"

Line Line::ToEngineLine(const BiVector& bv)
{
	return {
		.direction = Vector3f{ bv.e01(), bv.e02(), bv.e03() },
		.origin = Vector3f{ bv.e23(), bv.e31(),  bv.e12() }
	};
}

BiVector Line::ToPGALine(const Line& l)
{
	return BiVector{
		l.direction.x,
		l.direction.y,
		l.direction.z,
		l.origin.x,
		l.origin.y,
		l.origin.z,
	};
}