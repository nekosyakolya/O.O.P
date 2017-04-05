#include "stdafx.h"


CTriangle::CTriangle(int x0, int x1, int x2, int y0, int y1, int y2)
{
	m_point1.x = x0;
	m_point1.y = y0;
	m_point2.x = x1;
	m_point2.y = y1;
	m_point3.x = x2;
	m_point3.y = y2;

	if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
	{
		throw std::invalid_argument("Value must not be negative\n");
	}
}

void CTriangle::Draw(ICanvas & canvas)const
{
	canvas.DrawLine(m_point1.x, m_point1.y, m_point2.x, m_point2.y);
	canvas.DrawLine(m_point2.x, m_point2.y, m_point3.x, m_point3.y);
	canvas.DrawLine(m_point3.x, m_point3.y, m_point1.x, m_point1.y);
}

Point CTriangle::GetFirstPoint() const
{
	return m_point1;
}

Point CTriangle::GetThirdPoint() const
{
	return m_point3;
}

Point CTriangle::GetSecondPoint() const
{
	return m_point2;
}


CTriangle::~CTriangle()
{
}