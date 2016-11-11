#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const int ARGUMENTS_COUNT = 5;

string ReplaceString(string &, const string &, const string &);
void ProcessFile(ifstream &, ofstream &, const string &, const string &);
bool IsValidNumOfArguments(int);
bool AreValidInputAndOutputFiles(char *[], ifstream &, ofstream &);
bool FailedToSaveData(ofstream &);

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

bool AreValidInputAndOutputFiles(char * argv[], ifstream &input, ofstream &output)
{
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return  false;
	}
	if (input.peek() == ifstream::traits_type::eof())
	{
		cout << "Empty file " << argv[1] << "\n";
		return false;
	}
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing" << "\n";
		return false;
	}
	return true;
}

bool IsValidNumOfArguments(int argc)
{
	bool success = true;
	if (argc != ARGUMENTS_COUNT)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string> \n";
		success = false;
	}
	return success;
}

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

	if (!IsValidNumOfArguments(argc))
	{
		return EXIT_FAILURE;
	}

	ifstream input(argv[1]);
	ofstream output(argv[2]);
	if (!AreValidInputAndOutputFiles(argv, input, output))
	{
		return EXIT_FAILURE;
	}
	string searchStr = argv[3];
	string replaceStr = argv[4];

	if (searchStr.size() == 0)
	{
		cout << "Empty line \n";
		return EXIT_FAILURE;
	}

	ProcessFile(input, output, searchStr, replaceStr);

	if (FailedToSaveData(output))
	{
		return EXIT_FAILURE;
	}

	input.close();
	output.close();

	return EXIT_SUCCESS;
}



