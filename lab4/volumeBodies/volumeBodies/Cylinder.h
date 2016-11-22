#pragma once
#include "Body.h"
class CCylinder final:
	public CBody
{
public:
	CCylinder(double height, double baseRadius, double density);
	double GetBaseRadius()const;
	double GetHeight()const;
	double GetVolume()const override;
	~CCylinder();
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_radius;
	double m_height;
};

