#include "stdafx.h"
#include "Cylinder.h"


CCylinder::CCylinder(double height, double baseRadius, double density):
	CBody("cylinder", density),
	m_height(height),
	m_radius(baseRadius)
{
	if (baseRadius <= 0 || height <= 0)
	{
		throw std::invalid_argument("Height or radius must not be negative\n");
	}
}

double CCylinder::GetBaseRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return (pow(m_radius, 2) * M_PI) * GetHeight();
}

CCylinder::~CCylinder()
{
}

void CCylinder::AppendProperties(std::ostream & strm) const
{
	strm << "\theight = " << GetHeight() << std::endl
		<< "\tradius = " << GetBaseRadius() << std::endl;
}
