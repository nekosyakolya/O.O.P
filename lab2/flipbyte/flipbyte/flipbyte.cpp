#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
static const int ARGUMENTS_COUNT = 3;
static const int SHIFT_VALUE = 4;

bool IsValidNumOfArguments(int);
bool IsValidValue(int);
int ReverseBits(int);
bool IsValidOutputFile(char *[], ofstream &);

int main(int argc, char * argv[])
{
	if (!IsValidNumOfArguments(argc))
	{
		return EXIT_FAILURE;
	}
	int value = atoi(argv[1]);

	if (!IsValidValue(value) && argv[1] != "0")
	{
		return EXIT_FAILURE;
	}	

	ofstream output(argv[2]);
	if (!IsValidOutputFile(argv, output))
	{
		return EXIT_FAILURE;
	}

	int currentRank = 0x0F;
	int firstPartOfNumber = ReverseBits(value & currentRank) << SHIFT_VALUE;
	int secondPartOfNumber = ReverseBits((value & (~currentRank)) >> SHIFT_VALUE);
	value = (firstPartOfNumber | secondPartOfNumber);
	output << value << endl;
    return EXIT_SUCCESS;
}

int ReverseBits(int value)
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

bool IsValidNumOfArguments(int argc)
{
	bool success = true;
	if (argc != ARGUMENTS_COUNT)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: flipbyte.exe <input bit> <output file>\n";
		success = false;
	}
	return success;
}


bool IsValidValue(int key)
{
	static const int MAX_KEY = 255;
	static const int MIN_KEY = 0;
	bool success = true;
	if ((key < MIN_KEY) || (key > MAX_KEY))
	{
		cout << "Failed key: " << key << "\n";
		success = false;
	}
	if (key == 0)
	{
		cout << "Incorrect value" << endl;
		success = false;
	}
	return success;
}

bool IsValidOutputFile(char * argv[], ofstream &output)
{
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing" << "\n";
		return false;
	}
	return true;
}