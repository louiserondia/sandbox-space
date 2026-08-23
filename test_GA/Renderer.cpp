#include "pch.h"
#include "Renderer.h"

void Renderer::DrawLine(const BiVector& bv, float lineWidth) const
{
	DrawLine(Line::ToEngineLine(bv), lineWidth);
}

void Renderer::DrawLine(const Line& l, float lineWidth) const
{
	Vector2f origin{
		l.origin.x + l.origin.z * offsetX3D,
		l.origin.y + l.origin.z * offsetY3D
	};
	Vector2f direction{
		l.direction.x + l.direction.z * offsetX3D,
		l.direction.y + l.direction.z * offsetY3D
	};

	utils::DrawLine(origin, origin + direction, lineWidth);
}

void Renderer::DrawPoint(const TriVector& tv, float pointSize) const
{
	DrawPoint(Point::ToEnginePoint(tv), pointSize);
}

void Renderer::DrawPoint(const Point& p, float pointSize) const
{
	utils::DrawPoint(
		p.position.x + p.position.z * offsetX3D,
		p.position.y + p.position.z * offsetY3D, pointSize
	);
}
