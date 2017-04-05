#include "stdafx.h"


CRectangle::CRectangle(int x0, int y0, int width, int height) :
	m_width(width),
	m_height(height)
{
	m_point.x = x0;
	m_point.y = y0;
	if (x0 < 0 || y0 < 0 || width <= 0 || height <= 0)
	{
		throw std::invalid_argument("Value must not be negative\n");
	}
}


void CRectangle::Draw(ICanvas & canvas)const
{
	canvas.DrawLine(m_point.x + m_width, m_point.y, m_point.x, m_point.y);
	canvas.DrawLine(m_point.x + m_width, m_point.y + m_height, m_point.x, m_point.y + m_height);

	canvas.DrawLine(m_point.x, m_point.y + m_height, m_point.x, m_point.y);
	canvas.DrawLine(m_point.x + m_width, m_point.y + m_height, m_point.x + m_width, m_point.y);
}

int CRectangle::GetHeight() const
{
	return m_height;
}

int CRectangle::GetWidth() const
{
	return m_width;
}

Point CRectangle::GetPoint() const
{
	return m_point;
}

CRectangle::~CRectangle()
{
}