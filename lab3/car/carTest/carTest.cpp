// carTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../car/car.h"


struct CarSetFixture
{
	CCar car;
};


BOOST_FIXTURE_TEST_SUITE(CarSet, CarSetFixture)
	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!car.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(can_turned_on_car)
	{
		BOOST_CHECK(!car.IsTurnedOn());
		BOOST_CHECK(car.TurnOnEngine());
	}
BOOST_AUTO_TEST_SUITE_END()
