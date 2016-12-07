#pragma once

class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;

	int GetDenominator() const;
	std::pair<int, CRational> ToCompoundFraction()const;

	double ToDouble() const;


	const CRational operator+() const;
	const CRational operator-() const;

	CRational & operator+=(const CRational &);
	CRational & operator-=(const CRational &);
	CRational & operator*=(const CRational &);
	CRational & operator/=(const CRational &);
private:
	int m_numerator;
	int m_denominator;
	void Normalize();
};

unsigned GCD(unsigned a, unsigned b);

const CRational operator*(const CRational &, const CRational &);
const CRational operator/(const CRational &, const CRational &);
const CRational operator+(const CRational &, const CRational &);
const CRational operator-(const CRational &, const CRational &);
const bool operator==(const CRational &, const CRational &);
const bool operator!=(const CRational &, const CRational &);
const bool operator<(const CRational &, const CRational &);
const bool operator>(const CRational &, const CRational &);
const bool operator<=(const CRational &, const CRational &);
const bool operator>=(const CRational &, const CRational &);
std::ostream & operator<<(std::ostream &, const CRational &);
std::istream & operator>>(std::istream &, CRational &);

