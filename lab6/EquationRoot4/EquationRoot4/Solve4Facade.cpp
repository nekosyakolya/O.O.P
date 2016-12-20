#include "stdafx.h"
#include "Solve4Facade.h"
#include <iostream>
#include <math.h>

CSolve4Facade::CSolve4Facade(double a, double b, double c, double d, double e)
try
	:m_roots(Solve4(a, b, c, d, e)) {}
catch (...)
{
	throw;
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



	Solve2(1, -firstCoefficient, (thirdCoefficient + rootOfCubicEquation), roots, b);
	Solve2(1, firstCoefficient, (-thirdCoefficient + rootOfCubicEquation), roots, b);


	if (roots.numRoots == 0)
	{
		throw std::domain_error("Equation has not real roots\n");
	}
	return roots;
}

double CSolve4Facade::GetRealRootOfCubicEquation(double p, double r, double q)
{
	q = (((p * r) - (pow(q, 2) / 4)) / 2) ;// c
	p /= 2;
	p = -p;
	r = -r;

	double Q;
	double R;
	double S;

	Q = ((pow(p, 2) - (r * 3)) / 9) ;

	R = (((pow(p, 3) * 2) - (p * r * 9) + (q * 27)) / 54);

	S = pow(Q, 3) - pow(R, 2);

	double x;
	double w;

	if (S == 0)
	{
		x = cbrt(R) - (p/3);
	}

	if (S > 0)
	{
		w = acos((R / sqrt(pow(Q, 3)) ))/ 3;
		x = (-2)* sqrt(Q) * cos(w) - (p/3);
	}

	if (S < 0)
	{

		double sgn = 0;

		if (R > 0) sgn = 1;
		if (R < 0) sgn = -1;
		if (Q == 0)
		{
			x = (-p / 3) - cbrt(q - (pow(p, 3) /27));
		}

		if (Q > 0)
		{
			w = (acosh(abs(R) / (sqrt(pow(Q, 3)))) / 3) ;

			x = ((-2) * sgn * sqrt(Q) *cosh(w)) - (p / 3);
		}

		if (Q < 0)
		{
			w = (asinh(abs(R) / (sqrt(pow(abs(Q), 3)))) / 3);

			x = ((-2) * sgn * sqrt(abs(Q)) *sinh(w)) - (p / 3);
		}

	}
	return x;
}

double CSolve4Facade::GetDiscriminant(double a, double b, double c)
{
	return (pow(b, 2) - 4 * a * c);
}

void CSolve4Facade::Solve2(double a, double b, double c, EquationRoot4 &roots, double k)
{
	double d = GetDiscriminant(a, b, c);
	if (d >= 0)
	{
		++roots.numRoots;
		roots.roots[roots.numRoots - 1] = (-b - sqrt(d)) / (a * 2) - k /4;
		++roots.numRoots;
		roots.roots[roots.numRoots - 1] = (-b + sqrt(d)) / (a * 2) - k / 4;
	}
}

