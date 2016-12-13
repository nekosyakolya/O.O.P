#pragma once

struct EquationRoot4
{
	int numRoots;
	double roots[4];
};


class CSolve4Facade
{
public:
	CSolve4Facade(double a, double b, double c, double d, double e);

	//void PrintRoots();
	~CSolve4Facade();
private:
	EquationRoot4 Solve4(double a, double b, double c, double d, double e);
	EquationRoot4 m_roots;
};

