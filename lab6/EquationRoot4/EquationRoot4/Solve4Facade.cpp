#include "stdafx.h"
#include "Solve4Facade.h"
#include <iostream>
#include <math.h>
#include <algorithm>

CSolve4Facade::CSolve4Facade(double a, double b, double c, double d, double e)
try
	:m_roots(Solve4(a, b, c, d, e)) {}
catch (...)
{
	throw;
}


int CSolve4Facade::GetNumRoots()
{
	return m_roots.numRoots;
}

double * CSolve4Facade::GetRoots()
{
	return m_roots.roots;
}

void CSolve4Facade::PrintRoots()
{
	std::cout << m_roots.numRoots << " real roots:" << std::endl;
	for (int i = 0; i < m_roots.numRoots; ++i)
	{
		std::cout << "x" << i << " " << m_roots.roots[i] << std::endl;
	}
}

CSolve4Facade::~CSolve4Facade()
{
}




EquationRoot4 CSolve4Facade::Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw std::invalid_argument("First coefficient must not be equal 0\n");
	}

	b /= a;
	c /= a;
	d /= a;
	e /= a;

	EquationRoot4 roots;
	roots.numRoots = 0;


	double firstCoefficient = c - ((pow(b, 2) * 3) / 8);

	double thirdCoefficient = (pow(b, 3) /8)- ((b * c)/2) + d;

	double secondCoefficient = e + ((pow(b, 2) * c) / 16) - ((b *d) / 4) - ((pow(b, 4) * 3) / 256);

	double rootOfCubicEquation = GetRealRootOfCubicEquation(firstCoefficient, secondCoefficient, thirdCoefficient);


	firstCoefficient = sqrt((rootOfCubicEquation * 2) - firstCoefficient);


	thirdCoefficient = (thirdCoefficient / (firstCoefficient * 2));

	

	EquationRoot2 rootSquare = Solve2(1, -firstCoefficient, (thirdCoefficient + rootOfCubicEquation));
	roots.numRoots = rootSquare.numRoots;
	if (roots.numRoots != 0)
	{
		for (int i = 0; i < rootSquare.numRoots; ++i)
		{
			roots.roots[i] = rootSquare.roots[i] - b / 4;
		}
	}

	rootSquare = Solve2(1, firstCoefficient, (rootOfCubicEquation - thirdCoefficient));
	roots.numRoots += rootSquare.numRoots;
	if (rootSquare.numRoots != 0)
	{
		for (int i = 0; i < rootSquare.numRoots; ++i)
		{
			roots.roots[i + 2] = rootSquare.roots[i] - b / 4;
		}
	}
	if (roots.numRoots == 0)
	{
		throw std::domain_error("Equation has not real roots\n");
	}
	return roots;
}



double CSolve4Facade::CountTheRootOfCubicEquation(double a, double c, double q, double r)
{
	double x;
	double angle;
	double sgn = 0;

	if (r > 0) sgn = 1;
	if (r < 0) sgn = -1;
	if (q == 0)
	{
		x = (-a / 3) - cbrt(c - (pow(a, 3) / 27));
	}

	if (q > 0)
	{
		angle = (acosh(abs(r) / (sqrt(pow(q, 3)))) / 3);

		x = ((-2) * sgn * sqrt(q) * cosh(angle)) - (a / 3);
	}

	if (q < 0)
	{
		angle = (asinh(abs(r) / (sqrt(pow(abs(q), 3)))) / 3);

		x = ((-2) * sgn * sqrt(abs(q)) * sinh(angle)) - (a / 3);
	}

	return x;
}


double CSolve4Facade::GetRealRootOfCubicEquation(double a, double b, double c)
{
	c = (((a * b) - (pow(c, 2) / 4)) / 2) ;// c
	a /= 2;
	a = -a;
	b = -b;


	double q = ((pow(a, 2) - (b * 3)) / 9) ;

	double r = (((pow(a, 3) * 2) - (a * b * 9) + (c * 27)) / 54);

	double s = pow(q, 3) - pow(r, 2);

	double x;

	if (s == 0)
	{
		x = cbrt(r) - (a / 3);
	}

	if (s > 0)
	{
		double angle = acos((r / sqrt(pow(q, 3)) )) / 3;
		x = (-2)* sqrt(q) * cos(angle) - (a / 3);
	}

	if (s < 0)
	{

		x = CountTheRootOfCubicEquation(a, c, q, r);

	}
	return x;
}


double CSolve4Facade::GetDiscriminant(double a, double b, double c)
{
	return (pow(b, 2) - 4 * a * c);
}

EquationRoot2 CSolve4Facade::Solve2(double a, double b, double c)
{
	EquationRoot2 rootSquare;
	rootSquare.numRoots = 0;
	double d = GetDiscriminant(a, b, c);
	if (d >= 0)
	{
		rootSquare.roots[rootSquare.numRoots] = (-b - sqrt(d)) / (a * 2);
		++rootSquare.numRoots;
		rootSquare.roots[rootSquare.numRoots] = (-b + sqrt(d)) / (a * 2);
		++rootSquare.numRoots;

	}
	return rootSquare;
}

