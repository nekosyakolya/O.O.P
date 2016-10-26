#include "stdafx.h"
#include "vector.h"

using namespace std;

void ReadNumbers(vector<double> &numbers)
{
    double value;

    while (cin >> value)
    {
        numbers.insert(numbers.end(), value);
    }
}

void ChangeNumbers(vector<double> &numbers)
{
	if (numbers.size() != 0)
	{
		double min = *min_element(numbers.begin(), numbers.end());
		double max = *max_element(numbers.begin(), numbers.end());

		double k = (min != 0) ? max / min : 0;

		std::transform(numbers.begin(), numbers.end(), numbers.begin(), [k](double val){
			return val * k;
		});
	}
}

void OutputNumbers(const vector<double> &numbers)
{
    copy(numbers.cbegin(), numbers.cend(), ostream_iterator<double>(cout, " "));
    cout << endl;
}