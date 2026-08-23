#pragma once
#include "FlyFish.h"

class Line
{
public:

	Vector3f	direction;
	Vector3f	origin;

	static Line		ToEngineLine(const BiVector& bv);
	static BiVector	ToPGALine(const Line& l);

private:

};
