#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void ReadArray(vector<double> &array)
{
	float value;

	while (cin >> value)
	{
		array.insert(array.end(), value);
	}
}

void ChangeArray(vector<double> &array)
{
	float min = *min_element(array.begin(), array.end());
	float max = *max_element(array.begin(), array.end());

	for (unsigned int i = 0; i < array.size(); ++i)
	{
		array[i] = (array[i] * min) / max;
	}

	sort(array.begin(), array.end());
}

void OutArray(vector<double> &array)
{
	copy(array.begin(), array.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
}

int main()
{
	vector<double> array;

	ReadArray(array);
	
	ChangeArray(array);

	OutArray(array);
	
	return EXIT_SUCCESS;
}