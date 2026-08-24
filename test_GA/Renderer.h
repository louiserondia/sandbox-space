#pragma once
#include "FlyFish.h"
#include "Plane.h"
#include "Line.h"
#include "Point.h"
#include "Cube.h"

class Renderer
{
public:

	void DrawLine(const BiVector& bv, float lineWidth = 1.f) const;
	void DrawLine(const Line& l, float lineWidth = 1.f) const;
	void DrawPoint(const TriVector& tv, float pointSize = 1.f) const;
	void DrawPoint(const Point& p, float pointSize = 1.f) const;
	void DrawCube(const Cube& cube, bool asPoints = false, float lineWidth = 1.f) const;

private:

	const float offsetX3D{ -0.6f };
	const float offsetY3D{ -0.3f };

};
