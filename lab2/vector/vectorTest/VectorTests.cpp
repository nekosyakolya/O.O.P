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

BOOST_AUTO_TEST_SUITE_END()
