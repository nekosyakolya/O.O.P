#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void ScreenNumbers(unsigned n, vector<bool> &prime)
{
	prime[0] = false;
	prime[1] = false;

	for (unsigned i = 2; i <= sqrt(n); ++i)
	{
		if (prime[i])
		{
			for (unsigned j = i * i; j <= n; i == 2 ? (j += i) : (j = j + 2 * i))
			{
				prime[j] = false;
			}
		}
	}
}

set<unsigned> AddPrimeNumbers(unsigned n, const vector<bool> &prime)
{
	set<unsigned>PrimeNumbersSet;
	for (unsigned i = 2; i <= n; ++i)
	{
		if (prime[i])
		{
			PrimeNumbersSet.insert(i);
		}
	}
	return PrimeNumbersSet;
}


set<unsigned> GeneratePrimeNumbersSet(unsigned n)
{

	vector<bool> prime(n + 1, true);
	ScreenNumbers(n, prime);

	set<unsigned>PrimeNumbersSet;

	return PrimeNumbersSet = AddPrimeNumbers(n, prime);
}

int main()
{
	unsigned n;
	cin >> n;

	set<unsigned>PrimeNumbersSet = GeneratePrimeNumbersSet(n);

	copy(PrimeNumbersSet.begin(), PrimeNumbersSet.end(), ostream_iterator<double>(cout, " "));


	//cout << PrimeNumbersSet.size() << endl;
	return EXIT_SUCCESS;
}

