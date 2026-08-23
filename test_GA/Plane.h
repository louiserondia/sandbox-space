#pragma once
#include "FlyFish.h"
#include "Vector3f.h"

class Plane
{

public:
	Vector3f	normal;
	float		distance;

	Plane	ToEnginePlane(const Vector& v) const;
	Vector	ToPGAPlane(const Plane& p) const;

private:

};

