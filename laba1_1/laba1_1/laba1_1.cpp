#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: laba1_1.exe <input file> <text to search>\n";
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	string strInFile, searchStr = argv[2];
	if (searchStr.empty())
	{
		cout << "Empty line \n";
		return 1;
	}
	int i = 1;
	while (getline(input, strInFile))
	{
		size_t pos = strInFile.find(searchStr);
		if (pos != -1)
		{
			cout << i << "\n";
		}
		i++;
	}
	input.close();

    return 0;
}

