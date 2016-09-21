#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string ReplaceString(string &strInFile, const string &searchStr, const string &replaceStr);
void ProcessFile(ifstream &input, ofstream &output, const string &searchStr, const string &replaceStr);


string ReplaceString(string &strInFile, const string &searchStr, const string &replaceStr)
{
	size_t positionOfMatchedString = strInFile.find(searchStr);
	while ((positionOfMatchedString != string::npos) && !(searchStr == replaceStr))
	{
		strInFile.replace(positionOfMatchedString, searchStr.length(), replaceStr);
		positionOfMatchedString = strInFile.find(searchStr, positionOfMatchedString + replaceStr.length());
	}
	return strInFile;
}

void ProcessFile(ifstream &input, ofstream &output, const string &searchStr, const string &replaceStr)
{
	string strInFile;
	bool emptyFile = true;
	while (getline(input, strInFile))
	{
		emptyFile = false;
		if (!strInFile.empty())
		{
			strInFile = ReplaceString(strInFile, searchStr, replaceStr);
			output << strInFile;
		}
		output << "\n";
	}
	if (emptyFile)
	{
		cout << "EMPTY FILE \n";
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



