#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string ReplaceString(string &strInFile, const string &searchStr, const string &replaceStr);
void ProcessFile(ifstream &input, ofstream &output, const string &searchStr, const string &replaceStr);


string ReplaceString(string &strInFile, const string &searchStr, const string &replaceStr)
{
	string newStr = "";
	size_t positionOfBeginString = 0;
	size_t positionOfMatchedString = strInFile.find(searchStr);

	while ((positionOfMatchedString != string::npos) && !(searchStr == replaceStr))
	{
		newStr += strInFile.substr(positionOfBeginString, positionOfMatchedString - positionOfBeginString);
		newStr += replaceStr;
		positionOfBeginString = positionOfMatchedString + searchStr.length();
		positionOfMatchedString = strInFile.find(searchStr, positionOfMatchedString + searchStr.length());
	}

	return newStr += strInFile.substr(positionOfBeginString);
}

void ProcessFile(ifstream &input, ofstream &output, const string &searchStr, const string &replaceStr)
{
	string strInFile;

	while (getline(input, strInFile))
	{
		if (!strInFile.empty())
		{
			strInFile = ReplaceString(strInFile, searchStr, replaceStr);
			output << strInFile;
		}
		output << "\n";
	}
}

int main(int argc, char * argv[])
{
	static const int maxNumberOfArgument = 5;

	if (argc != maxNumberOfArgument)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return EXIT_FAILURE;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return EXIT_FAILURE;
	}

	if (input.eof())
	{
		cout << "EMPTY FILE \n";
		return EXIT_FAILURE;
	}

	ofstream output(argv[2]);

	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return EXIT_FAILURE;
	}

	string searchStr = argv[3];
	string replaceStr = argv[4];

	if ((searchStr.empty()))
	{
		cout << "Empty line \n";
		return EXIT_FAILURE;
	}

	ProcessFile(input, output, searchStr, replaceStr);

	if (!output.flush())
	{
		cout << "Failed to save data on disk\n";
		return EXIT_FAILURE;
	}

	input.close();
	output.close();

	return EXIT_SUCCESS;
}



