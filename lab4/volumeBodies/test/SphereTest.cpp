// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../volumeBodies/sphere.h"
#define _USE_MATH_DEFINES
#include <math.h>


struct Sphere_
{
	const double expectedRadius = 42.8;
	const double expectedDensity = 8.8;
	const double expectedVolume = (pow(expectedRadius, 3) * M_PI) * 4 / 3;
	const CSphere sphere;
	Sphere_()
		: sphere(expectedRadius, expectedDensity)
	{}
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Sphere, Sphere_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&sphere));
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		BOOST_CHECK_EQUAL(sphere.GetRadius(), expectedRadius);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(sphere).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(sphere).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// имеет строковое представление
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(sphere:
	density = 8.8
	volume = 328412.6796
	mass = 2890031.581
	radius = 42.8
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).ToString(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()
