// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "../EquationRoot4/Solve4Facade.h"


BOOST_AUTO_TEST_SUITE(Equation)

	BOOST_AUTO_TEST_CASE(cant_have_a_negative_a)
	{
		BOOST_REQUIRE_THROW(CSolve4Facade(0, 14, 4, 1, 14), std::invalid_argument);
	}


	BOOST_AUTO_TEST_CASE(can_have)
	{
		BOOST_REQUIRE_THROW(CSolve4Facade(1, 1, 1, 1, 1), std::domain_error);
	}

	

BOOST_AUTO_TEST_SUITE_END()
