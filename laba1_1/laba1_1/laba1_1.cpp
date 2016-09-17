#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	ofstream output(argv[2]);
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	string strInFile, searchStr = argv[3], replaceStr = argv[4];
	if ((searchStr.empty()) ||(replaceStr.empty()))
	{
		cout << "Empty line \n";
		return 1;
	}
	while (getline(input, strInFile))
	{
		size_t pos = strInFile.find(searchStr);
		while (pos != string::npos)
		{
			strInFile.replace(pos, searchStr.length(), replaceStr);
			pos = strInFile.find(searchStr, pos + replaceStr.length());
		}
		output << strInFile << "\n";
	}
	if (!output.flush()) 
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}
	input.close();
	output.close();

    return 0;
}

