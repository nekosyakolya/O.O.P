#include "stdafx.h"
#include "vector.h"

using namespace std;

int main()
{
	vector<double> numbers;
	ReadNumbers(numbers);
	
	ChangeNumbers(numbers);

	sort(numbers.begin(), numbers.end());

	OutputNumbers(numbers);

	return EXIT_SUCCESS;
}
