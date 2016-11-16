
#include "stdafx.h"
#include "../car/car.h"


struct CarSetFixture
{
    CCar car;
};


BOOST_FIXTURE_TEST_SUITE(CarTest, CarSetFixture)

    BOOST_AUTO_TEST_SUITE(when_turned_off)
        BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
        {
            BOOST_CHECK(!car.IsTurnedOn());
        }
        BOOST_AUTO_TEST_CASE(can_be_turned_on)
        {
            BOOST_CHECK(car.TurnOnEngine());
        }
        BOOST_AUTO_TEST_CASE(cant_be_turned_off)
        {
            BOOST_CHECK(!car.TurnOffEngine());
        }

        BOOST_AUTO_TEST_CASE(speed_is_0_by_default)
        {
            BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
        }

        BOOST_AUTO_TEST_CASE(direction_is_stay_by_default)
        {
            BOOST_CHECK_EQUAL(static_cast<int>(car.GetDirection()), 0);
        }

        BOOST_AUTO_TEST_CASE(gear_is_neutral_by_default)
        {
            BOOST_CHECK_EQUAL(car.GetGear(), 0);
        }
        BOOST_AUTO_TEST_CASE(cant_put_the_first_gear)
        {
            BOOST_CHECK(!car.SetGear(1));
        }
        BOOST_AUTO_TEST_CASE(cant_change_speed)
        {
            BOOST_CHECK(!car.SetSpeed(10));
        }
    BOOST_AUTO_TEST_SUITE_END()

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
        BOOST_AUTO_TEST_CASE(cant_be_turned_on)
        {
            BOOST_CHECK(!car.TurnOnEngine());
        }

        BOOST_AUTO_TEST_SUITE(set_gear_test)
            BOOST_AUTO_TEST_CASE(can_turn_neutral_gear)
            {
                BOOST_CHECK(car.SetGear(0));
            }

            BOOST_AUTO_TEST_CASE(cant_turn_the_gear_if_speed_is_out_of_gear_speed_range)
            {
                BOOST_CHECK(!car.SetGear(5));
                car.SetGear(1);
                car.SetSpeed(13);
                BOOST_CHECK(!car.SetGear(3));
            }
            BOOST_AUTO_TEST_CASE(cant_turn_the_incorrect_gear)
            {
                BOOST_CHECK(!car.SetGear(15));
            }

            BOOST_AUTO_TEST_CASE(cant_turn_reverse_gear_if_speed_is_not_equal_to_zero)
            {
                car.SetGear(1);
                car.SetSpeed(25);
                BOOST_CHECK(!car.SetGear(-1));
            }
            BOOST_AUTO_TEST_CASE(cant_turn_first_gear_after_reverse_gear_if_speed_is_not_equal_to_zero)
            {
                car.SetGear(-1);
                car.SetSpeed(13);
                BOOST_CHECK(!car.SetGear(1));
            }

        BOOST_AUTO_TEST_SUITE_END()

        BOOST_AUTO_TEST_SUITE(set_speed_test)
            BOOST_AUTO_TEST_CASE(cant_turn_speed_is_out_of_speed_range)
            {
                car.SetGear(1);
                BOOST_CHECK(!car.SetSpeed(40));
            }

            BOOST_AUTO_TEST_CASE(cant_accelerate_at_neutral_gear)
            {
                car.SetGear(1);
                car.SetSpeed(30);
                car.SetGear(0);
                BOOST_CHECK(!car.SetSpeed(40));
            }

            BOOST_AUTO_TEST_CASE(can_reduce_speed_at_neutral_gear)
            {
                car.SetGear(1);
                car.SetSpeed(30);
                car.SetGear(0);
                BOOST_CHECK(car.SetSpeed(10));
            }

        BOOST_AUTO_TEST_SUITE_END()

        BOOST_AUTO_TEST_SUITE(set_direction_test)
          
            BOOST_AUTO_TEST_CASE(direction_isnt_stay)
            {
                car.SetGear(1);
                car.SetSpeed(13);
                car.SetGear(0);
                BOOST_CHECK(static_cast<int>(car.GetDirection()) != 0);
            }

            BOOST_AUTO_TEST_CASE(direction_is_backward)
            {
                car.SetGear(-1);
                car.SetSpeed(13);
                BOOST_CHECK_EQUAL(static_cast<int>(car.GetDirection()), -1);
            }

          
        BOOST_AUTO_TEST_SUITE_END()
        

        BOOST_AUTO_TEST_SUITE(turn_off_test)

            BOOST_AUTO_TEST_CASE(engine_can_be_turned_off_at_neutral_gear_and_with_speed_is_equal_to_zero)
            {
                BOOST_CHECK(car.TurnOffEngine());
            }

            BOOST_AUTO_TEST_CASE(engine_cant_be_turned_off_at_non_neutral_gear)
            {
                car.SetGear(-1);
                BOOST_CHECK(!car.TurnOffEngine());
            }
            BOOST_AUTO_TEST_CASE(engine_cant_be_turned_off_at_neutral_gear_and_with_speed_is_not_equal_to_zero)
            {
                car.SetGear(1);
                car.SetSpeed(13);
                car.SetGear(0);
                BOOST_CHECK(!car.TurnOffEngine());
            }


        BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
