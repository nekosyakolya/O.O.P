// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../volumeBodies/Cone.h"



struct Cone_
{
	const double expectedDensity = 2.8;
	const double expectedBaseRadius = 8.8;
	const double expectedHeight = 8.4;
	const double expectedVolume = (pow(expectedBaseRadius, 2) * M_PI) * expectedHeight / 3;
	const CCone cone;
	Cone_()
		: cone(expectedHeight, expectedBaseRadius, expectedDensity)
	{}
};
// Конус
BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cone));
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		BOOST_CHECK_EQUAL(cone.GetBaseRadius(), expectedBaseRadius);
	}
	// имеет высоту
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cone).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cone).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// имеет строковое представление
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(cone:
	density = 2.8
	volume = 681.1978183
	mass = 1907.353891
	height = 8.4
	radius = 8.8
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).ToString(), expectedString);
	}

	BOOST_AUTO_TEST_CASE(cant_have_a_negative_radius)
	{
		BOOST_REQUIRE_THROW(CCone(1, 0, 13), std::invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(cant_have_a_negative_density)
	{
		BOOST_REQUIRE_THROW(CCone(2, 14, 0), std::invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(cant_have_a_negative_height)
	{
		BOOST_REQUIRE_THROW(CCone(0, 14, 13), std::invalid_argument);
	}


BOOST_AUTO_TEST_SUITE_END()

