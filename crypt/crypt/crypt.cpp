#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Crypt(ifstream &, ofstream &, const int &);
void Decrypt(ifstream &, ofstream &, const int &);


void Crypt(ifstream &input, ofstream &output, const int &key)
{
	char value;
	while (input.read(&value, sizeof value))
	{
		value ^= key;
		char temp = '\0';
		char newValue = '\0';
		newValue += temp | ((value & 0x80) >> 2);

		newValue += temp | ((value & 0x40) >> 5);

		newValue += temp | ((value & 0x20) >> 5);

		newValue += temp | ((value & 0x10) << 3);


		newValue += temp | ((value & 0x08) << 3);

		newValue += temp | ((value & 0x04) << 2);

		newValue += temp | ((value & 0x02) << 2);

		newValue += temp | ((value & 0x01) << 2);

		value = newValue;

		output << value;
	}
}

void Decrypt(ifstream &input, ofstream &output, const int &key)
{
	char value;
	while (input.read(&value, sizeof value))
	{
		char temp = '\0';
		char newValue = '\0';
		newValue += temp | ((value & 0x01) << 5);

		newValue += temp | ((value & 0x02) << 5);

		newValue += temp | ((value & 0x04) >> 2);

		newValue += temp | ((value & 0x08) >> 2);

		newValue += temp | ((value & 0x10) >> 2);

		newValue += temp | ((value & 0x20) << 2);

		newValue += temp | ((value & 0x40) >> 3);

		newValue += temp | ((value & 0x80) >> 3);

		value = newValue;
		value ^= key;

		output << value;
	}
}

int main(int argc, char * argv[])
{

	static const int maxNumberOfArgument = 5;
	static const string operationCrypt = "crypt";
	static const string operationDecrypt = "decrypt";


	if (argc != maxNumberOfArgument)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: crypt.exe crypt <input file> <output file> <key> \n";
		return EXIT_FAILURE;
	}

	string operation = argv[1];

	if ((operation != operationCrypt) && (operation != operationDecrypt))
	{
		cout << "Invalid operation\n";
		return EXIT_FAILURE;
	}

	ifstream input(argv[2], ios::binary | ios::in);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return EXIT_FAILURE;
	}
	ofstream output(argv[3], ios::binary | ios::out);

	if (!output.is_open())
	{
		cout << "Failed to open " << argv[3] << " for writing\n";
		return EXIT_FAILURE;
	}

	int key = atoi(argv[4]);

	if ((key < 0) || (key > 255))
	{
		cout << "Failed key\n";
		return EXIT_FAILURE;
	}
	(operation == operationCrypt) ? Crypt(input, output, key) : Decrypt(input, output, key);

	input.close();
	output.close();

    return EXIT_SUCCESS;
}

