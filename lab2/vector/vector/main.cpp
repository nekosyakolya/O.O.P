#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void ReadArray(vector<float> &array)
{
	float value;

	while (cin >> value)
	{
		array.insert(array.end(), value);
	}
}

void ChangeArray(vector<float> &array)
{
	float min = *min_element(array.begin(), array.end());
	float max = *max_element(array.begin(), array.end());

	for (unsigned int i = 0; i < array.size(); ++i)
	{
		array[i] = (array[i] * min) / max;
	}

	sort(array.begin(), array.end());
}

void OutArray(vector<float> &array)
{
	copy(array.begin(), array.end(), ostream_iterator<float>(cout, " "));
	cout << endl;
}

int main()
{
	vector<float> array;

	ReadArray(array);
	
	ChangeArray(array);

	OutArray(array);
	
	return EXIT_SUCCESS;
}