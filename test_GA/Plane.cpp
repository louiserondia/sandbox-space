#include "pch.h"
#include "Plane.h"

Plane Plane::ToEnginePlane(const Vector& v) const
{
	return {
		.normal = { v.e1(), v.e2(), v.e3() },
		.distance = v.e0()
	};
}

Vector Plane::ToPGAPlane(const Plane& p) const
{
	return Vector{
		p.distance,
		p.normal.x,
		p.normal.y,
		p.normal.z
	};
}
