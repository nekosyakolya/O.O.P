#include "stdafx.h"
#include "vector.h"

using namespace std;

int main()
{
	vector<double> digits;
	ReadDigits(digits);
	
	ChangeDigits(digits);

	OutDigits(digits);

	return EXIT_SUCCESS;
}
