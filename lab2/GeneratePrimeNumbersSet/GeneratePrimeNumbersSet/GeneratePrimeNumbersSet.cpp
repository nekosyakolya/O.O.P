#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
const static unsigned MIN_PRIME_NUMBER = 2;

void ScreenNumbers(unsigned upperLimitNumbers, vector<bool> &isPrimeNumbers)
{
	isPrimeNumbers[0] = false;
	if (upperLimitNumbers != 0)
	{
		isPrimeNumbers[1] = false;
	}

	for (unsigned i = MIN_PRIME_NUMBER; i <= sqrt(upperLimitNumbers);
		        i == MIN_PRIME_NUMBER ? ++i : i += MIN_PRIME_NUMBER)
	{
		if (isPrimeNumbers[i])
		{
			for (unsigned j = i * i; j <= upperLimitNumbers;
				i == MIN_PRIME_NUMBER ? (j += i) : (j = j + MIN_PRIME_NUMBER * i))
			{
				isPrimeNumbers[j] = false;
			}
		}
	}
}

set<unsigned> AddPrimeNumbers(unsigned upperLimitNumbers, const vector<bool> &isPrimeNumbers)
{
	set<unsigned>PrimeNumbersSet;
	for (unsigned i = MIN_PRIME_NUMBER; i <= upperLimitNumbers; ++i)
	{
		if (isPrimeNumbers[i])
		{
			PrimeNumbersSet.insert(i);
		}
	}
	return PrimeNumbersSet;
}


set<unsigned> GeneratePrimeNumbersSet(unsigned upperLimitNumbers)
{

	vector<bool> isPrimeNumbers(upperLimitNumbers + 1, true);
	ScreenNumbers(upperLimitNumbers, isPrimeNumbers);

	set<unsigned>PrimeNumbersSet;

	return PrimeNumbersSet = AddPrimeNumbers(upperLimitNumbers, isPrimeNumbers);
}

bool IsCorrectNumber(unsigned upperLimitNumbers)
{
	return (upperLimitNumbers <= 100000000);
}

int main()
{
	unsigned upperLimitNumbers;
	cin >> upperLimitNumbers;
	if (!IsCorrectNumber(upperLimitNumbers))
	{
		cout << "incorrect number\n";
		return EXIT_FAILURE;
	}

	set<unsigned>PrimeNumbersSet = GeneratePrimeNumbersSet(upperLimitNumbers);

	copy(PrimeNumbersSet.begin(), PrimeNumbersSet.end(), ostream_iterator<double>(cout, " "));

	return EXIT_SUCCESS;
}

