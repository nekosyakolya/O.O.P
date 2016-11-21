#pragma once
#include "Body.h"
class CSphere final:
	public CBody
{
public:
	CSphere(double radius, double density);
	double GetRadius()const;
	double GetVolume() const override;
	~CSphere();
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_radius;
};
