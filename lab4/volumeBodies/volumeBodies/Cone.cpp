#include "stdafx.h"
#include "Cone.h"


CCone::CCone(double height, double baseRadius, double density):
	CBody("cone", density),
	m_height(height),
	m_radius(baseRadius)
{
	if (baseRadius <= 0 || height <= 0)
	{
		throw std::invalid_argument("Height or radius must not be negative\n");
	}
}

double CCone::GetBaseRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (pow(m_radius, 2) * M_PI) * GetHeight() / 3;
}

CCone::~CCone()
{
}

void CCone::AppendProperties(std::ostream & strm) const
{
	strm << "\theight = " << GetHeight() << std::endl
		<< "\tradius = " << GetBaseRadius() << std::endl;
}
