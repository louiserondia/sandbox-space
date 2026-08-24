#pragma once
#include "Point.h"
#include "FlyFish.h"

class Cube
{
public:
	Point points[8]{};
	TriVector pointsGA[8]{};

	Cube() = default;
	Cube(const Point* p);
	Cube(const TriVector* p);
	Cube(const Point& start, float size);

	void UpdateGAPoints();
	void UpdatePoints();

private:

};

Cube RotateCube(const Cube& cube, const Motor& motor);
void RotateCube(const Cube& cube, Cube& projCube, const Motor& motor);
