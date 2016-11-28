#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int whole = m_numerator / m_denominator;
	int residue = m_numerator % m_denominator;
	if (residue < 0)
	{
		residue *= -1;
	}
	return std::make_pair(whole, CRational(residue, m_denominator));
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////
const CRational CRational::operator+() const
{
	return *this;
}

const CRational CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////
CRational const operator+(const CRational & firstSummand, const CRational & secondSummand)
{
	int numerator = firstSummand.GetNumerator() * secondSummand.GetDenominator() + firstSummand.GetDenominator() * secondSummand.GetNumerator();
	int denominator = firstSummand.GetDenominator() * secondSummand.GetDenominator();
	return CRational(numerator, denominator);
}




//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
CRational const operator-(const CRational & minuend, const CRational & subtrahend)
{
	int numerator = minuend.GetNumerator() * subtrahend.GetDenominator() - minuend.GetDenominator() * subtrahend.GetNumerator();
	int denominator = minuend.GetDenominator() * subtrahend.GetDenominator();
	return CRational(numerator, denominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator+=(const CRational & summand)
{
	*this = *this + summand;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator-=(const CRational & subtrahend)
{
	*this = *this - subtrahend;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////
CRational const operator*(const CRational & firstFactor, const CRational & secondFactor)
{
	int numerator = firstFactor.GetNumerator() * secondFactor.GetNumerator();
	int denominator = firstFactor.GetDenominator() * secondFactor.GetDenominator();
	return CRational(numerator, denominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////
CRational const operator/(const CRational & dividend, const CRational & divider)
{
	int numerator = dividend.GetNumerator() * divider.GetDenominator();
	int denominator = dividend.GetDenominator() * divider.GetNumerator();
	return CRational(numerator, denominator);
}




//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator*=(const CRational & factor)
{
	*this = *this * factor;
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////
const CRational & CRational::operator/=(const CRational & divider)
{
	*this = *this / divider;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////
bool const operator==(const CRational & firstRational, const CRational & secondRational)
{
	return (firstRational.GetDenominator() == secondRational.GetDenominator()) && (firstRational.GetNumerator() == secondRational.GetNumerator());
}

bool const operator!=(const CRational & firstRational, const CRational & secondRational)
{
	return (firstRational.GetDenominator() != secondRational.GetDenominator()) || (firstRational.GetNumerator() != secondRational.GetNumerator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const operator<(const CRational & firstRational, const CRational & secondRational)
{
	return (firstRational.GetNumerator() * secondRational.GetDenominator() < firstRational.GetDenominator() * secondRational.GetNumerator());
}


bool const operator>(const CRational & firstRational, const CRational & secondRational)
{
	return (firstRational.GetNumerator() * secondRational.GetDenominator() > firstRational.GetDenominator() * secondRational.GetNumerator());
}

bool const operator<=(const CRational & firstRational, const CRational & secondRational)
{
	return (firstRational.GetNumerator() * secondRational.GetDenominator() <= firstRational.GetDenominator() * secondRational.GetNumerator());
}


bool const operator>=(const CRational & firstRational, const CRational & secondRational)
{
	return (firstRational.GetNumerator() * secondRational.GetDenominator() >= firstRational.GetDenominator() * secondRational.GetNumerator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////

std::ostream & operator << (std::ostream & output, const CRational & rational)
{
	output << std::to_string(rational.GetNumerator()) << "/" << std::to_string(rational.GetDenominator());
	return output;
}




//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////
std::istream & operator >> (std::istream & input, CRational & rational)
{
	int denominator = 1;
	int numerator = 0;
	if ((input >> numerator) &&
		(input.get() == '/') &&
		(input >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		input.setstate(std::ios_base::failbit);
	}
	return input;
}


