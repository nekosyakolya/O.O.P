#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const int MAX_NUM_OF_ARGUMENTS = 5;
static const int MAX_KEY = 255;
static const int MIN_KEY = 0;
static const string OPERATION_CRYPT = "crypt";
static const string OPERATION_DECRYPT = "decrypt";

void Crypt(ifstream &, ofstream &, const int &);
void Decrypt(ifstream &, ofstream &, const int &);
bool IsValidNumOfArguments(const int &);
bool AreValidOperations(const string &);
bool IsValidKey(const int &);
bool AreValidInputOutputFiles(char * [], ifstream &, ofstream &);

bool IsValidNumOfArguments(const int &argc)
{
	if (argc != MAX_NUM_OF_ARGUMENTS)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: crypt.exe (crypt/decrypt) <input file> <output file> <key> \n";
	}
	return (argc == MAX_NUM_OF_ARGUMENTS);
}

bool AreValidOperations(const string &operation)
{
	if ((operation != OPERATION_CRYPT) && (operation != OPERATION_DECRYPT))
	{
		cout << "Invalid operation\n";
	}
	return (operation == OPERATION_CRYPT) || (operation == OPERATION_DECRYPT);
}

bool AreValidInputOutputFiles(char * argv[], ifstream &input, ofstream &output)
{
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return  false;
	}
	if (input.peek() == ifstream::traits_type::eof())
	{
		cout << "File " << argv[2] << " is empty" << "\n";
		return  false;
	}
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[3] << " for writing" << "\n";
		return false;
	}
	return true;
}

bool IsValidKey(const int &key)
{
	if ((key < MIN_KEY) || (key > MAX_KEY))
	{
		cout << "Failed key: " << key << "\n";
	}
	return ((key >= MIN_KEY) && (key <= MAX_KEY));
}

void Crypt(ifstream &input, ofstream &output, const int &key)
{
	char value;
	while (input.read(&value, sizeof value))
	{
		value ^= key;
		char newValue = '\0';
		int temp = 0x80;
		newValue += ((value & (temp)) >> 2);

		newValue += ((value & (temp >>= 1)) >> 5);

		newValue += ((value & (temp >>= 1)) >> 5);

		newValue += ((value & (temp >>= 1)) << 3);

		newValue += ((value & (temp >>= 1)) << 3);

		newValue += ((value & (temp >>= 1)) << 2);

		newValue += ((value & (temp >>= 1)) << 2);

		newValue += ((value & (temp >>= 1)) << 2);

		value = newValue;

		output << value;
	}
}

void Decrypt(ifstream &input, ofstream &output, const int &key)
{
	char value;
	while (input.read(&value, sizeof value))
	{
		char newValue = '\0';
		int temp = 0x01;
		newValue += ((value & (temp)) << 5);

		newValue += ((value & (temp <<= 1)) << 5);

		newValue += ((value & (temp <<= 1)) >> 2);

		newValue += ((value & (temp <<= 1)) >> 2);

		newValue += ((value & (temp <<= 1)) >> 2);

		newValue += ((value & (temp <<= 1)) << 2);

		newValue += ((value & (temp <<= 1)) >> 3);

		newValue += ((value & (temp <<= 1)) >> 3);

		value = newValue;
		value ^= key;

		output << value;
	}
}

int main(int argc, char * argv[])
{
	if (!IsValidNumOfArguments(argc))
	{
		return EXIT_FAILURE;
	}

	string operation = argv[1];
	if (!AreValidOperations(operation))
	{
		return EXIT_FAILURE;
	}

	ifstream input(argv[2], ios::binary | ios::in);
	ofstream output(argv[3], ios::binary | ios::out);

	if (!AreValidInputOutputFiles(argv, input, output))
	{
		return EXIT_FAILURE;
	}

	int key = atoi(argv[4]);
	if (!IsValidKey(key))
	{
		return EXIT_FAILURE;
	}

	(operation == OPERATION_CRYPT) ? Crypt(input, output, key) : Decrypt(input, output, key);

	input.close();
	output.close();

    return EXIT_SUCCESS;
}

