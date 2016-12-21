#pragma once

#include <cmath>

struct EquationRoot4
{
	int numRoots;
	double roots[4];
};


struct EquationRoot2
{
	int numRoots;
	double roots[2];
};


class CSolve4Facade
{
public:
	CSolve4Facade(double a, double b, double c, double d, double e);

	void PrintRoots();
	~CSolve4Facade();
private:
	EquationRoot4 Solve4(double a, double b, double c, double d, double e);
	double GetRealRootOfCubicEquation(double p, double r, double q);
	double CountTheRootOfCubicEquation(double p, double q, double Q, double R);
	EquationRoot4 m_roots;
	double GetDiscriminant(double a, double b, double c);
	EquationRoot2 Solve2(double a, double b, double c, double k);
};

