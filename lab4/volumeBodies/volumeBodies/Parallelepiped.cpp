#include "stdafx.h"
#include "Parallelepiped.h"


CParallelepiped::CParallelepiped(double density, double width, double height, double depth):
	CBody("parallelepiped", density),
	m_depth(depth),
	m_height(height),
	m_width(width)
{
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetVolume() const
{
	return GetHeight() * GetWidth() * GetDepth();
}

CParallelepiped::~CParallelepiped()
{
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	strm << "\tdepth = " << GetDepth() << std::endl
	<< "\theight = " << GetHeight() << std::endl
	<< "\twidth = " << GetWidth() << std::endl;
}
