#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
static const int MAX_NUM_OF_ARGUMENTS = 2;
static const int SHIFT_VALUE = 4;

bool IsValidNumOfArguments(const int &);
bool IsValidValue(const int &);
int ReversBits(int);

int main(int argc, char * argv[])
{
	if (!IsValidNumOfArguments(argc))
	{
		return EXIT_FAILURE;
	}
	int value = atoi(argv[1]);
	if (!IsValidValue(value))
	{
		return EXIT_FAILURE;
	}	

	int currentRank = 0x0F;
	int firstPartOfNumber = ReversBits(value & currentRank) << SHIFT_VALUE;
	int secondPartOfNumber = ReversBits((value & (~currentRank)) >> SHIFT_VALUE);
	value = (firstPartOfNumber | secondPartOfNumber);
	cout << value << endl;
    return EXIT_SUCCESS;
}

int ReversBits(int value)
{
	int base = SHIFT_VALUE * SHIFT_VALUE;
	int newValue = 0;
	while (value != 0)
	{
		newValue += (value & 1) * (base >>= 1);
		value >>= 1;
	}
	return newValue;
}

bool IsValidNumOfArguments(const int &argc)
{
	if (argc != MAX_NUM_OF_ARGUMENTS)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <входной байт> \n";
	}
	return (argc == MAX_NUM_OF_ARGUMENTS);
}


bool IsValidValue(const int &key)
{
	static const int MAX_KEY = 255;
	static const int MIN_KEY = 0;
	if ((key < MIN_KEY) || (key > MAX_KEY))
	{
		cout << "Failed key: " << key << "\n";
	}
	return ((key >= MIN_KEY) && (key <= MAX_KEY));
}