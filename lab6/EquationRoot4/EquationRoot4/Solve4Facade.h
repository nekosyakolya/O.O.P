#pragma once

#include <cmath>

struct EquationRoot4
{
	int numRoots;
	double roots[4];
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
	EquationRoot4 m_roots;
	double GetDiscriminant(double a, double b, double c);
	void Solve2(double a, double b, double c, EquationRoot4 &roots, double k);
};

