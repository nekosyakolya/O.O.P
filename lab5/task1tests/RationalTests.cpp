// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}



/*
Рациональное число:
равно нулю по умолчанию (0/1)
может быть созданно из целого в формате (n / 1)
может быть задано с указанием числителя и знаменателя
хранится в нормализованном виде
*/

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
	{
		VerifyRational(CRational(10), 10, 1);
		VerifyRational(CRational(-10), -10, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerifyRational(CRational(5, 2), 5, 2);
		VerifyRational(CRational(-5, 2), -5, 2);
		VerifyRational(CRational(5, -2), -5, 2);
		VerifyRational(CRational(-5, -2), 5, 2);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerifyRational(CRational(6, 8), 3, 4);
		VerifyRational(CRational(6, -8), -3, 4);
		VerifyRational(CRational(-6, 8), -3, 4);
		VerifyRational(CRational(-6, -8), 3, 4);
		VerifyRational(CRational(-10, 20), -1, 2);
	}
	BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
	{
		BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
	}




//////////////////////////////////////////////////////////////////////////
//TODO: 1. Реализовать метод ToDouble() согласно заданию
//Возвращает отношение числителя и знаменателя в виде числа double
//Пример использования:
//CRational r(3, 5)
//cout << r.ToDouble(); // Должно вывести 0.6
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(can_be_converted_to_double)
	{
		BOOST_CHECK_CLOSE_FRACTION(CRational(7, 8).ToDouble(), 0.875, 0.00001);
		BOOST_CHECK_CLOSE_FRACTION(CRational(8, 5).ToDouble(), 1.6, 0.00001);
		BOOST_CHECK_CLOSE_FRACTION(CRational(0).ToDouble(), 0, 0.00001);
	}



//////////////////////////////////////////////////////////////////////////
//TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_unary_plus_that_returns_itself_without_changes)
	{
		VerifyRational(CRational(1, 2), 1, 2);
		VerifyRational(CRational(4, 3), 4, 3);
		VerifyRational(CRational(0), 0, 1);
	}

	BOOST_AUTO_TEST_SUITE(has_unary_minus)
		BOOST_AUTO_TEST_CASE(that_returns_itself_with_inverted_sign)
		{
			VerifyRational(-CRational(7, 8), -7, 8);
			VerifyRational(-CRational(-7, 8), 7, 8);
			VerifyRational(-CRational(7, -8), 7, 8);
			VerifyRational(-CRational(-7, -8), -7, 8);
		}
		BOOST_AUTO_TEST_CASE(that_correctly_handles_0)
		{
			VerifyRational(-CRational(0), +0, 1);
			VerifyRational(-CRational(0), -0, 1);
		}
	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
//TODO: 3. Реализовать бинарный +
//Возвращает результат сложения двух рациональных чисел, 
//рационального числа с целым, целого числа с рациональным.
//(1/2) + (1/6) = (2/3)
//(1/2) + 1     = (3/2)
//1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operator_of_addition)

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyRational(CRational(0) + CRational(1, 3), 1, 3);
			VerifyRational(CRational(1, 3) + CRational(0), 1, 3);
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			VerifyRational(CRational(1, 2) + CRational(1, 2), 1, 1);
			VerifyRational(CRational(1, 1) + CRational(-1, 1), 0, 1);

		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1, 3) + 1, 4, 3);
			VerifyRational(1 + CRational(1, 3), 4, 3);
		}

	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
//TODO: 4. Реализовать бинарный -
//Возвращает разность двух рациональных чисел, 
//рационального числа и целого, либо целого числа и рационального:
//(1/2) - (1/6) = (1/3)
//(1/2) - 1     = (-1/2)
//1 - (1/2)     = (1/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operator_of_subtraction)

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyRational(CRational(0) - CRational(0), 0, 1);
			VerifyRational(CRational(1, 3) - CRational(0), 1, 3);
			VerifyRational(CRational(0) - CRational(1, 3), -1, 3);
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			VerifyRational(CRational(1, 2) - CRational(1, 2), 0, 1);
			VerifyRational(CRational(1, 2) - CRational(1, 6), 1, 3);
			VerifyRational(CRational(1, 6) - CRational(1, 2), -1, 3);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1, 3) - 1, -2, 3);
			VerifyRational(1 - CRational(1, 3), 2, 3);
		}

	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
//TODO: 5. Реализовать оператор +=
//Выполняет увеличение рационального числа на величину второго рационального,
//либо целого числа:
//(1/2) += (1/6)  → (2/3)
//(1/2) += 1      → (3/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operator_of_addition_with_assignment)

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyRational(CRational(2, 13) += 0, 2, 13);
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			CRational rational(2, 13);
			VerifyRational(rational += rational, 4, 13);
			VerifyRational(rational += CRational(-4, 13), 0, 1);
			VerifyRational(CRational(1, 2) += CRational(1, 6), 2, 3);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1, 2) += 1, 3, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
//TODO: 6. Реализовать оператор -=
//Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
//(1/2) -= (1/6)  → (1/3)
//(1/2) -= 1      → (-1/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operator_of_subtraction_with_assignment)

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyRational(CRational (2, 13) -= 0, 2, 13);
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			CRational rational(1, 2);
			VerifyRational(rational -= CRational(1, 6), 1, 3);
			VerifyRational(rational -= rational, 0, 1);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1, 2) -= 1, -1, 2);
		}

	BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
//TODO: 7. Реализовать оператор *
//Возвращает результат произведения рациональных чисел, 
//рационального и целого, либо целого и рационального :
//(1/2) * (2/3) = (1/3)
//(1/2) * (-3)  = (-3/2)
//7 * (2/3)     = (14/3)
////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_SUITE(has_operator_of_multiplication)

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyRational(CRational(1, 3) * 0, 0, 1);
			VerifyRational(0 * CRational(1, 3), 0, 1);
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			VerifyRational(CRational(3, 6) * CRational(3, 5), 3, 10);
			VerifyRational(CRational(-3, 6) * CRational(3, 5), -3, 10);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1, 6) * 2, 1, 3);
			VerifyRational(2 * CRational(1, 6), 1, 3);

			VerifyRational(CRational(1, 6) * -2, -1, 3);
			VerifyRational(-2 * CRational(1, 6), -1, 3);
		}

	BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
//TODO: 8. Реализовать оператор /
//Возвращает частное двух рациональных чисел, 
//рационального и целого, целого и рационального :
//(1/2) ⁄ (2/3) = (3/4)
//(1/2) ⁄ 5     = (1/10)
//7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_SUITE(has_operator_of_division)
		BOOST_AUTO_TEST_CASE(with_0)
		{
			BOOST_REQUIRE_THROW(CRational(1, 1) / 0, std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			VerifyRational(CRational(3, 6) / CRational(3, 5), 5, 6);
			VerifyRational(CRational(3, 6) / CRational(-3, 5), -5, 6);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1, 6) / 2, 1, 12);
			VerifyRational(2 / CRational(1, 6), 12, 1);

			VerifyRational(CRational(1, 6) / -2, -1, 12);
			VerifyRational(-2 / CRational(1, 6), -12, 1);
		}

	BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
//TODO: 9. Реализовать оператор *=
//Умножает значение первого рационального числа на другое рациональное, 
//либо целое:
//(1/2) *= (2/3) → (1/3)
//(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operator_of_multiplication_with_assignment)

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyRational(CRational(2, 13) *= 0, 0, 1);
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			VerifyRational(CRational(1, 2) *= CRational(2, 3), 1, 3);
			VerifyRational(CRational(1, 2) *= CRational(-2, 3), -1, 3);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyRational(CRational(1, 2) *= 3, 3, 2);
			VerifyRational(CRational(1, 2) *= -3, -3, 2);
		}

	BOOST_AUTO_TEST_SUITE_END()





//////////////////////////////////////////////////////////////////////////
//TODO: 10. Реализовать оператор /=
//Делит первое рациональное число на другое рациональное, 
//либо целое:
//(1/2) /= (2/3) → (3/4)
//(3/4) /= (3/8) → (2/1)
//(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_SUITE(has_operator_of_division_with_assignment)
		BOOST_AUTO_TEST_CASE(cant_divided_to_0)
		{
			BOOST_REQUIRE_THROW(CRational(1, 1) /= 0, std::invalid_argument);
		}

		BOOST_AUTO_TEST_SUITE(with_positive_argument)

			BOOST_AUTO_TEST_CASE(which_is_rational_number)
			{
				CRational rational(1, 2);
				VerifyRational(rational /= CRational(2, 3), 3, 4);
				VerifyRational(rational /= CRational(3, 8), 2, 1);
			}

			BOOST_AUTO_TEST_CASE(which_is_integer_number)
			{
				VerifyRational(CRational(1, 2) /= 3, 1, 6);
			}

		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(with_negative_argument)

			BOOST_AUTO_TEST_CASE(which_is_rational_number)
			{
				CRational rational(-1, 2);
				VerifyRational(rational /= CRational(-2, 3), 3, 4);
				VerifyRational(rational /= CRational(-3, 8), -2, 1);
			}

			BOOST_AUTO_TEST_CASE(which_is_integer_number)
			{
				VerifyRational(CRational(1, 2) /= -3, -1, 6);
			}

		BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
//TODO: 11. Реализовать операторы == и !=
//Проверяют равенство (и неравенство) двух рациональных чисел, 
//целого и рационального, рационального и целого:
//(1/2) == (1/2) → true
//(4/1) == 4     → true
//3 == (3/1)     → true
//(1/2) != (2/3) → true
//(1/2) != 7     → true
//3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(has_operator_of_equivalence)
	{
		BOOST_CHECK(CRational(-2, 3) == CRational(-2, 3));
		BOOST_CHECK(CRational(4, 1) == 4);
		BOOST_CHECK(-3 == CRational(-3, 1));

		BOOST_CHECK(CRational(-2, 3) != CRational(2, 3));
		BOOST_CHECK(CRational(4, 2) != 4);
		BOOST_CHECK(-3 != CRational(-3, 7));
	}



//////////////////////////////////////////////////////////////////////////
//TODO: 12. Реализовать операторы <, >, <=, >=
//Сравнивают два рациональных числа, рациональное с целым, 
//целое с рациональным:
//(1/2) >= (1/3) → true
//(1/2) <= (1/3) → false
//(3/1) > 2      → true
//(1/2) < 7      → true
//3 <= (7/2)     → true
//3 >= (8/2)     → false
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_SUITE(has_operator_of_comparison)
		BOOST_AUTO_TEST_CASE(with_integer)
		{

			BOOST_CHECK(!(CRational(9, 1) < 7));
			BOOST_CHECK(-4 <= CRational(-3, 1));
			BOOST_CHECK(CRational(3, 1) > 2);
			BOOST_CHECK(!(3 >= CRational(7, 2)));
		}

		BOOST_AUTO_TEST_CASE(with_rational)
		{
			BOOST_CHECK(CRational(4, 3) <= CRational(8, 6));
			BOOST_CHECK(CRational(4, 3) >= CRational(4, 3));
			BOOST_CHECK(CRational(4, 3) > CRational(-3, 1));
			BOOST_CHECK(!(CRational(4, 3) < CRational(-3, 1)));
		}

	BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
//TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//std::ostream в формате <числитель>/<знаменатель>, 
//например: 7/15
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(can_be_recorded_to_ostream)
	{
		{
			std::ostringstream output;
			output << CRational(-8);
			BOOST_CHECK_EQUAL(output.str(), "-8/1");
		}

		{
			std::ostringstream output;
			output << CRational(7, 15);
			BOOST_CHECK_EQUAL(output.str(), "7/15");
		}
	}





//////////////////////////////////////////////////////////////////////////
//TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//std::istream в формате <числитель>/<знаменатель>, 
//например: 7/15
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(can_be_introduced_from_istream)
	{
		{
			CRational rational;

			std::istringstream input("0");
			input >> rational;
			VerifyRational(rational, 0, 1);
		}
		{
			CRational rational;

			std::istringstream input("7/15");
			input >> rational;
			VerifyRational(rational, 7, 15);
		}
		{
			CRational rational;

			std::istringstream input("-4/3");
			input >> rational;
			VerifyRational(rational, -4, 3);
		}
		{
			CRational rational;

			std::istringstream input("no numbers");
			input >> rational;
			BOOST_CHECK(input.fail());
		}
	}

	BOOST_AUTO_TEST_SUITE(can_be_converted_to_compound_fraction)
		BOOST_AUTO_TEST_CASE(if_it_is_positive_number)
		{
			CRational rational(9, 2);
			std::pair <int, CRational> receivedResult = rational.ToCompoundFraction();

			std::pair <int, CRational> result = std::make_pair(4, CRational(1, 2));
			BOOST_CHECK(result == receivedResult);
		}

		BOOST_AUTO_TEST_CASE(if_it_is_negative_number)
		{
			CRational rational(-9, 2);
			std::pair <int, CRational> receivedResult = rational.ToCompoundFraction();

			std::pair <int, CRational> result = std::make_pair(-4, CRational(1, 2));
			BOOST_CHECK(result == receivedResult);
		}

		BOOST_AUTO_TEST_CASE(if_it_is_0)
		{
			CRational rational(0, 1);
			std::pair <int, CRational> receivedResult = rational.ToCompoundFraction();

			std::pair <int, CRational> result = std::make_pair(0, CRational(0, 1));
			BOOST_CHECK(result == receivedResult);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
