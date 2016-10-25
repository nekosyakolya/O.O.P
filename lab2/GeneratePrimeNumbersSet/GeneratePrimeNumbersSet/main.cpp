#include "stdafx.h"
#include "prime.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguents count\n"
			<< "Usage: GeneratePrimeNumbersSet.exe <upperBound>";
		return 1;
	}
	unsigned upperLimitNumbers = atoi(argv[1]);
	if (!IsCorrectNumber(upperLimitNumbers) || upperLimitNumbers == 0 && *argv[1] != '0')
	{
		cout << "incorrect number\n";
		return EXIT_FAILURE;
	}

	set<unsigned>PrimeNumbersSet = GeneratePrimeNumbersSet(upperLimitNumbers);

	copy(PrimeNumbersSet.begin(), PrimeNumbersSet.end(), ostream_iterator<double>(cout, " "));

	return EXIT_SUCCESS;
}