#pragma once

#include <cmath>


static const int BASE = 2;


struct EquationRoot4
{
	int numRoots = 0;
	double roots[BASE * 2] = {0, 0, 0, 0};
};


struct EquationRoot2
{
	int numRoots = 0;
	double roots[BASE] = {0, 0};
};


class CSolve4Facade
{
public:
	CSolve4Facade(double a, double b, double c, double d, double e);
	void PrintRoots();
	int GetNumRoots();
	double* GetRoots();
	~CSolve4Facade();
private:
	EquationRoot4 Solve4(double a, double b, double c, double d, double e);
	double GetRealRootOfCubicEquation(double p, double r, double q);
	double CountTheRootOfCubicEquation(double a, double c, double q, double r);
	double GetDiscriminant(double a, double b, double c);
	EquationRoot2 Solve2(double a, double b, double c);

	EquationRoot4 m_roots;
};

