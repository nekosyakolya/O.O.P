#include "stdafx.h"
#include "vector.h"

using namespace std;

void ReadDigits(vector<double> &digits)
{
    double value;

    while (cin >> value)
    {
        digits.insert(digits.end(), value);
    }
}

void ChangeDigits(vector<double> &digits)
{
	if (digits.size() != 0)
	{
		double min = *min_element(digits.begin(), digits.end());
		double max = *max_element(digits.begin(), digits.end());

		double index;

		(min != 0) ? index = max / min : index = 0;

		for (unsigned i = 0; i < digits.size(); ++i)
		{
			digits[i] *= index;
		}

		sort(digits.begin(), digits.end());
	}
}

void OutDigits(vector<double> &digits)
{
    copy(digits.begin(), digits.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
}