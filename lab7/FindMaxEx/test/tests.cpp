#include "stdafx.h"
#include "../FindMaxEx/findMax.h"


BOOST_AUTO_TEST_SUITE(FindMaxEx_function)


	BOOST_AUTO_TEST_CASE(returns_max_when_vector_has_a_size_equal_1)
	{
		{
			int maxValue = 0;
			std::vector<int> arr = {1};
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == 1);
		}

		{
			std::string maxValue = "";
			std::vector<std::string> arr = { "new year" };
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == "new year");
		}
	}
BOOST_AUTO_TEST_SUITE_END()
