#include "stdafx.h"
#include "../vector/vector.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}


BOOST_AUTO_TEST_SUITE(ProcessVectorTest)
	BOOST_AUTO_TEST_CASE(max_equ_min)
	{
		vector<double> numbers = { 1.1, 1.1, 1.1 };
		ChangeDigits(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, { 1.1, 1.1, 1.1 }));
	}

	BOOST_AUTO_TEST_CASE(empty_vector)
	{
		vector<double> numbers = {};
		ChangeDigits(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, {}));
	}

	BOOST_AUTO_TEST_CASE(min_is_zero)
	{
		vector<double> numbers = {0, 1.1, 9.9, 2.453, 8.32};
		ChangeDigits(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, {0, 0, 0, 0, 0}));
	}

	BOOST_AUTO_TEST_CASE(max_and_min_are_negative)
	{
		vector<double> numbers = {-32, -1, -3, -6.54};
		ChangeDigits(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, {-1, -0.204375, -0.09375, -0.03125}));
	}

	BOOST_AUTO_TEST_CASE(min_is_negative_and_max_is_positive)
	{
		vector<double> numbers = {-32, 3.1, 16};
		ChangeDigits(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers, {-8, -1.55, 16}));
	}

BOOST_AUTO_TEST_SUITE_END()
