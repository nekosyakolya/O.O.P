#include "stdafx.h"
#include "../GeneratePrimeNumbersSet/prime.h"

BOOST_AUTO_TEST_SUITE(TestGeneratePrimeNumbersSet)

	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_0)
	{
		std::set<unsigned> referenceSet = {};
		BOOST_CHECK(GeneratePrimeNumbersSet(0) == referenceSet);
	}

	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_2)
	{
		std::set<unsigned> referenceSet = { 2 };
		BOOST_CHECK(GeneratePrimeNumbersSet(2) == referenceSet);
	}

	BOOST_AUTO_TEST_CASE(creates_a_set_from_the_upper_bound_100)
	{
		std::set<unsigned> referenceSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23,
			29, 31, 37, 41, 43, 47, 53, 59,
			61, 67, 71, 73, 79, 83, 89, 97 };
		BOOST_CHECK(GeneratePrimeNumbersSet(100) == referenceSet);
	}

	BOOST_AUTO_TEST_CASE(upper_bound_is_equal_to_the_maximum_value)
	{
		BOOST_CHECK(GeneratePrimeNumbersSet(100000000).size() == 5761455);
	}

BOOST_AUTO_TEST_SUITE_END()