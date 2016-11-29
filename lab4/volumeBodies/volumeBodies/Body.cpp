#include "stdafx.h"
#include "Body.h"
#include <iomanip>

CBody::CBody(const std::string & type, double density):
	m_type(type),
	m_density(density)
{
	if (density <= 0)
	{
		throw std::invalid_argument("Density must not be negative");
	}
}

double CBody::GetMass()const
{
	return GetDensity() * GetVolume();
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
	<< "\tdensity = " << GetDensity() << std::endl
	<< "\tvolume = " << GetVolume() << std::endl
	<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}



double CBody::GetDensity()const
{
	return m_density;
}

CBody::~CBody()
{
}
