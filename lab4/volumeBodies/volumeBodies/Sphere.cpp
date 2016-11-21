#include "stdafx.h"
#include "Sphere.h"

#define _USE_MATH_DEFINES
#include <math.h>

CSphere::CSphere(double radius, double density):
	m_radius(radius),
	CBody("sphere", density)
{
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

CSphere::~CSphere()
{
}

void CSphere::AppendProperties(std::ostream & strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl;
}
