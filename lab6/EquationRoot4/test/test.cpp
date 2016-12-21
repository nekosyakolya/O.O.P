#include "stdafx.h"

#include "../EquationRoot4/Solve4Facade.h"


BOOST_AUTO_TEST_SUITE(Equation)

	BOOST_AUTO_TEST_CASE(could_not_have_null_first_coefficient)
	{
		BOOST_REQUIRE_THROW(CSolve4Facade(0, 1, 13, 1, 3), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(could_have_all_imaginary_roots)
	{
		BOOST_REQUIRE_THROW(CSolve4Facade(1, 1, 1, 1, 1), std::domain_error);
	}


	BOOST_AUTO_TEST_CASE(could_have_all_real_roots)
	{
		CSolve4Facade equation(2, 5, -11, -20, 12);
		BOOST_CHECK(equation.GetNumRoots() == 4);
		double roots[4] = {-3, 2, -2, 0.5};
		BOOST_CHECK(equation.GetRoots() == roots);
	}
	

BOOST_AUTO_TEST_SUITE_END()
