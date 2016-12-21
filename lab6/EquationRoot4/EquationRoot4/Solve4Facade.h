#pragma once

#include <cmath>

static const int BASE = 2;

struct EquationRoot4
{
	int numRoots = 0;
	double roots[BASE * BASE] = {0, 0, 0, 0};
};


struct EquationRoot2
{
	int numRoots = 0;
	double roots[BASE] = {0, 0};
};


class CSolve4Facade
{
public:
	CSolve4Facade(double, double, double, double, double);
	void PrintRoots() const;
	int GetNumRoots() const;
	const double* GetRoots()const;
	~CSolve4Facade();
private:
	EquationRoot4 Solve4(double, double, double, double, double)const;
	double GetRealRootOfCubicEquation(double, double, double)const;
	double CountTheRootOfCubicEquation(double, double, double, double)const;

	void CountTheRootsOfFourthEquation(EquationRoot4 &, const EquationRoot2 &, double)const;
	double GetDiscriminant(double, double, double)const;
	EquationRoot2 Solve2(double, double, double)const;

	EquationRoot4 m_roots;
};

