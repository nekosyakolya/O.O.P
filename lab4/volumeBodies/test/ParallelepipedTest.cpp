//

#include "stdafx.h"
#include "../volumeBodies/Parallelepiped.h"



struct Parallelepiped_
{
	const double expectedDepth = 2.4;
	const double expectedDensity = 2.8;
	const double expectedWidth = 8.8;
	const double expectedHeight = 8.4;
	const double expectedVolume = expectedHeight * expectedWidth * expectedDepth;
	const CParallelepiped parallelepiped;
	Parallelepiped_()
		: parallelepiped(expectedDensity, expectedWidth, expectedHeight, expectedDepth)
	{}
};
BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
	}
	BOOST_AUTO_TEST_CASE(has_a_depth)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), expectedDepth);
	}
	BOOST_AUTO_TEST_CASE(has_a_width)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), expectedWidth);
	}
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), expectedHeight);
	}
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).GetDensity(), expectedDensity);
	}
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetVolume(), expectedVolume, 1e-7);
	}
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(parallelepiped:
	density = 2.8
	volume = 177.408
	mass = 496.7424
	depth = 2.4
	height = 8.4
	width = 8.8
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).ToString(), expectedString);
	}


BOOST_AUTO_TEST_SUITE_END()

