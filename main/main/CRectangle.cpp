#include "stdafx.h"
#include "CRectangle.h"


CRectangle::CRectangle(int x0, int y0, int width, int height) :
	m_x0(x0),
	m_y0(y0),
	m_width(width),
	m_height(height)
{
	if (x0 < 0 || y0 < 0 || width < 0 || height < 0)
	{
		throw std::invalid_argument("Value must not be negative\n");
	}
}

std::string CRectangle::GetType() const
{
	return "Rectangle";
}


void CRectangle::Draw(ICanvas & canvas)const
{
	canvas.DrawLine(m_x0 + m_width, m_y0, m_x0, m_y0);
	canvas.DrawLine(m_x0 + m_width, m_y0 + m_height, m_x0, m_y0 + m_height);

	canvas.DrawLine(m_x0, m_y0 + m_height, m_x0, m_y0);
	canvas.DrawLine(m_x0 + m_width, m_y0 + m_height, m_x0 + m_width, m_y0);
}

CRectangle::~CRectangle()
{
}