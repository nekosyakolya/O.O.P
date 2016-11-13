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
	BOOST_AUTO_TEST_CASE(can_be_turned_on)
	{
		BOOST_CHECK(car.TurnOnEngine());
		BOOST_CHECK(car.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(speed_is_0_by_default)
	{
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	}
	struct when_turned_on_ : CarSetFixture
	{
		when_turned_on_()
		{
			car.TurnOnEngine();
		}
	};
	BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)

		BOOST_AUTO_TEST_CASE(can_be_turned_off)
		{
			BOOST_CHECK(car.TurnOffEngine());
		}

		BOOST_AUTO_TEST_CASE(can_be_turned_revers)
		{
			car.SetGear(-1);
			BOOST_CHECK(car.SetGear(1));
		}

		BOOST_AUTO_TEST_CASE(can_be_turned_neitral)
		{
			BOOST_CHECK(car.SetGear(0));
		}

		BOOST_AUTO_TEST_CASE(cant_be_turned_5)
		{
			BOOST_CHECK(!car.SetGear(5));
		}

		BOOST_AUTO_TEST_CASE(cant_be_turned_4)
		{
			car.SetGear(-1);
			BOOST_CHECK(!car.SetGear(4));
		}

		BOOST_AUTO_TEST_CASE(cant_set_gear_out_of_range)
		{
			BOOST_CHECK(!car.SetGear(10));
		}

		BOOST_AUTO_TEST_CASE(cant_set_rear_gear_from_other_gears)
		{
			car.SetGear(1);
			car.SetSpeed(30);
			car.SetGear(2);
			BOOST_CHECK(!car.SetGear(-1));
		}
		BOOST_AUTO_TEST_CASE(cant_set_speed_out_of_gear_speed_range)
		{
			car.SetGear(1);
			BOOST_CHECK(!car.SetSpeed(150));
		}
		BOOST_AUTO_TEST_CASE(cant_set_first_gear_after_rear_gear_and_non_zero_speed)
		{
			car.SetGear(-1);
			car.SetSpeed(10);
			BOOST_CHECK(!car.SetGear(1));
		}

		BOOST_AUTO_TEST_CASE(cant_accelerate_at_neutral_gear)
		{
			car.SetGear(1);
			car.SetSpeed(10);
			car.SetGear(0);
			BOOST_CHECK(!car.SetSpeed(15));
		}

		BOOST_AUTO_TEST_CASE(forward_direction)
		{
			car.SetGear(1);
			car.SetSpeed(10);
			car.SetGear(0);
			BOOST_CHECK(car.GetDirection() == 1);
		}

		BOOST_AUTO_TEST_CASE(backward_direction)
		{
			car.SetGear(-1);
			car.SetSpeed(10);
			BOOST_CHECK(car.GetDirection() == -1);
		}

		BOOST_AUTO_TEST_CASE(direction_isnt_stay)
		{
			car.SetGear(1);
			car.SetSpeed(10);
			car.SetGear(0);
			BOOST_CHECK(!car.GetDirection() == 0);
		}

		BOOST_AUTO_TEST_SUITE(Turn_off_function)

			BOOST_AUTO_TEST_CASE(engine_can_be_turned_off_at_neutral_gear_and_with_zero_speed)
			{
				BOOST_CHECK(car.TurnOffEngine());
			}

			BOOST_AUTO_TEST_CASE(engine_cant_be_turned_off_at_neutral_gear_and_with_non_zero_speed)
			{
				car.SetGear(1);
				car.SetSpeed(20);
				car.SetGear(0);
				BOOST_CHECK(!car.TurnOffEngine());
			}

			BOOST_AUTO_TEST_CASE(engine_cant_be_turned_off_at_non_neutral_gear)
			{
				car.SetGear(1);
				BOOST_CHECK(!car.TurnOffEngine());
			}

		BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
