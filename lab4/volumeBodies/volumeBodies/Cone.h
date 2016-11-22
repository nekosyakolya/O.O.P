#pragma once
#include "Body.h"
class CCone final:
	public CBody
{
public:
	CCone(double height, double baseRadius, double density);
	double GetBaseRadius()const;
	double GetHeight()const;
	double GetVolume()const override;
	~CCone();
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_radius;
	double m_height;
};

