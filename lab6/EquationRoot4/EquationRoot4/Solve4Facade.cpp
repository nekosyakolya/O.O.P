#include "stdafx.h"
#include "Solve4Facade.h"
#include <iostream>

CSolve4Facade::CSolve4Facade(double a, double b, double c, double d, double e)
try
	:m_roots(Solve4(a, b, c, d, e)) {}
catch (...)
{
	throw;
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
	return EquationRoot4();
}
