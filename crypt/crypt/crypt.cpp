#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Crypt(ifstream &, ofstream &, const int &);
//void Decrypt(ifstream &, ofstream &, const int &);


void Crypt(ifstream &input, ofstream &output, const int &key)
{
	char value;
	while (input.read(&value, sizeof value))
	{
		value ^= key;
		output << value;
	}
	input.close();
	output.close();
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
	ofstream output(argv[3]);

	if (!output.is_open())
	{
		cout << "Failed to open " << argv[3] << " for writing\n";
		return EXIT_FAILURE;
	}

	int key = atoi(argv[4]);


	//(operation == operationCrypt) ? 
	Crypt(input, output, key);// : Decrypt(input, output, key);

    return EXIT_SUCCESS;
}

