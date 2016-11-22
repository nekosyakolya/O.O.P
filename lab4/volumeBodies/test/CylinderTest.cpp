// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../volumeBodies/Cylinder.h"



struct Cylinder_
{
	const double expectedDensity = 2.8;
	const double expectedBaseRadius = 8.8;
	const double expectedHeight = 8.4;
	const double expectedVolume = (pow(expectedBaseRadius, 2) * M_PI) * expectedHeight;
	const CCylinder cylinder;
	Cylinder_()
		: cylinder(expectedHeight, expectedBaseRadius, expectedDensity)
	{}
};
// Цилиндер
BOOST_FIXTURE_TEST_SUITE(Cylinder, Cylinder_)
// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cylinder));
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		BOOST_CHECK_EQUAL(cylinder.GetBaseRadius(), expectedBaseRadius);
	}
	// имеет высоту
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cylinder.GetHeight(), expectedHeight);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// имеет строковое представление
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(cylinder:
	density = 2.8
	volume = 2043.593455
	mass = 5722.061673
	height = 8.4
	radius = 8.8
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).ToString(), expectedString);
	}


BOOST_AUTO_TEST_SUITE_END()

