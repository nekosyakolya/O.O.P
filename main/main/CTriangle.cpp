#include "stdafx.h"
#include "CTriangle.h"


CTriangle::CTriangle(int x0, int x1, int x2, int y0, int y1, int y2) :
	m_x0(x0),
	m_x1(x1),
	m_x2(x2),
	m_y0(y0),
	m_y1(y1),
	m_y2(y2)
{
	if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
	{
		throw std::invalid_argument("Value must not be negative\n");
	}
}

void CTriangle::Draw(ICanvas & canvas)const
{
	canvas.DrawLine(m_x0, m_y0, m_x1, m_y1);
	canvas.DrawLine(m_x1, m_y1, m_x2, m_y2);
	canvas.DrawLine(m_x2, m_y2, m_x0, m_y0);
}

std::string CTriangle::GetType() const
{
	return "Triangle";
}

CTriangle::~CTriangle()
{
}