#include "pch.h"
#include "Cube.h"

Cube::Cube(const Point* p)
{
	for (size_t i{}; i < 8; i++)
	{
		points[i] = p[i];
		pointsGA[i] = Point::ToPGAPoint(p[i]);
	}
}

Cube::Cube(const TriVector* p)
{
	for (size_t i{}; i < 8; i++)
	{
		pointsGA[i] = p[i];
		points[i] = Point::ToEnginePoint(pointsGA[i]);
	}
}

Cube::Cube(const Point& start, float size)
{
	points[0] = start;
	points[1] = points[0] + Point{ size, 0, 0 };
	points[2] = points[0] + Point{ 0, size, 0 };
	points[3] = points[0] + Point{ 0, 0, size };
	points[4] = points[0] + Point{ size, size, 0 };
	points[5] = points[0] + Point{ size, 0, size };
	points[6] = points[0] + Point{ 0, size, size };
	points[7] = points[0] + Point{ size, size, size };

	UpdateGAPoints();
}


void Cube::UpdateGAPoints()
{
	for (size_t i{}; i < 8; i++)
	{
		pointsGA[i] = Point::ToPGAPoint(points[i]);
	}
}

void Cube::UpdatePoints()
{
	for (size_t i{}; i < 8; i++)
	{
		points[i] = Point::ToEnginePoint(pointsGA[i]);
	}
}

Cube RotateCube(const Cube& cube, const Vector& N, const Vector& M)
{
	Cube c{};
	for (size_t i{}; i < 8; i++)
	{
		c.pointsGA[i] = ((N * M) * cube.pointsGA[i] * GA::Inverse(N * M)).Grade3();
	}

	c.UpdatePoints();
	return c;
}

Cube RotateCube(const Cube& cube, const Motor& motor)
{
	Cube c{};
	for (size_t i{}; i < 8; i++)
	{
		c.pointsGA[i] = (motor * cube.pointsGA[i] * GA::Inverse(motor)).Grade3();
	}

	c.UpdatePoints();
	return c;
}

void RotateCube(const Cube& cube, Cube& projCube, const Motor& motor)
{
	for (size_t i{}; i < 8; i++)
	{
		projCube.pointsGA[i] = (motor * cube.pointsGA[i] * GA::Inverse(motor)).Grade3();
		//Motor m{ Motor::Rotation(90.f, BiVector{0, 0, 0, 0, 1, 0}) };
		//projCube.pointsGA[i] = (m * cube.pointsGA[i] * GA::Inverse(m)).Grade3();

	}

	projCube.UpdatePoints();
}
