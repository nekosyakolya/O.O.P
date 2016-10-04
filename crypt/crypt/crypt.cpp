#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const int MAX_NUM_OF_ARGUMENTS = 5;
static const string OPERATION_CRYPT = "crypt";
static const string OPERATION_DECRYPT = "decrypt";

void Crypt(ifstream &, ofstream &, int);
void Decrypt(ifstream &, ofstream &, int);
bool IsValidNumArguments(int);
bool IsValidOperation(const string &);
bool IsValidKey(int);
bool AreValidInputAndOutputFiles(char * [], ifstream &, ofstream &);
char MixBitsForCrypt(const char &);
char MixBitsForDecrypt(const char &);
bool FailedToSaveData(ofstream &);

int main(int argc, char * argv[])
{
	if (!IsValidNumArguments(argc))
	{
		return EXIT_FAILURE;
	}

	string operation = argv[1];
	if (!IsValidOperation(operation))
	{
		return EXIT_FAILURE;
	}

	ifstream input(argv[2], ios::binary | ios::in);
	ofstream output(argv[3], ios::binary | ios::out);

	if (!AreValidInputAndOutputFiles(argv, input, output))
	{
		return EXIT_FAILURE;
	}

	int key = atoi(argv[4]);
	if (!IsValidKey(key))
	{
		return EXIT_FAILURE;
	}

	(operation == OPERATION_CRYPT) ? Crypt(input, output, key) : Decrypt(input, output, key);

	if (FailedToSaveData(output))
	{
		return EXIT_FAILURE;
	}

	input.close();
	output.close();

    return EXIT_SUCCESS;
}


bool FailedToSaveData(ofstream &output)
{
	bool error = false;
	if (!output.flush())
	{
		cout << "Failed to save data on disk\n";
		error = true;
	}
	return error;
}

bool IsValidNumArguments(int argc)
{
	bool success = true;
	if (argc != MAX_NUM_OF_ARGUMENTS)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: crypt.exe (crypt/decrypt) <input file> <output file> <key> \n";
		success = false;
	}
	return success;
}

bool IsValidOperation(const string &operation)
{
	bool success = true;
	if ((operation != OPERATION_CRYPT) && (operation != OPERATION_DECRYPT))
	{
		cout << "Invalid operation\n";
		success = false;
	}
	return success;
}

bool AreValidInputAndOutputFiles(char * argv[], ifstream &input, ofstream &output)
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

bool IsValidKey(int key)
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

char MixBitsForCrypt(const char &value)
{
	char newValue = '\0';
	int currentRank = 0x80;

	newValue += ((value & (currentRank)) >> 2);

	newValue += ((value & (currentRank >>= 1)) >> 5);

	newValue += ((value & (currentRank >>= 1)) >> 5);

	newValue += ((value & (currentRank >>= 1)) << 3);

	newValue += ((value & (currentRank >>= 1)) << 3);

	newValue += ((value & (currentRank >>= 1)) << 2);

	newValue += ((value & (currentRank >>= 1)) << 2);

	newValue += ((value & (currentRank >>= 1)) << 2);
	return newValue;
}

void Crypt(ifstream &input, ofstream &output, int key)
{
	char value;
	while (input.read(&value, sizeof value))
	{
		value ^= key;
		value = MixBitsForCrypt(value);
		output << value;
	}
}


char MixBitsForDecrypt(const char &value)
{
	char newValue = '\0';
	int currentRank = 0x01;

	newValue += ((value & (currentRank)) << 5);

	newValue += ((value & (currentRank <<= 1)) << 5);

	newValue += ((value & (currentRank <<= 1)) >> 2);

	newValue += ((value & (currentRank <<= 1)) >> 2);

	newValue += ((value & (currentRank <<= 1)) >> 2);

	newValue += ((value & (currentRank <<= 1)) << 2);

	newValue += ((value & (currentRank <<= 1)) >> 3);

	newValue += ((value & (currentRank <<= 1)) >> 3);
	return newValue;
}

void Decrypt(ifstream &input, ofstream &output, int key)
{
	char value;
	while (input.read(&value, sizeof value))
	{
		value = MixBitsForDecrypt(value);
		value ^= key;
		output << value;
	}
}