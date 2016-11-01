#include "stdafx.h"
#include <boost/algorithm/string.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
static const string delim = "=";

void ReadDictionary(ifstream &dictionary, map<string, string> & myFirstMap)
{
	string word;
	while (getline(dictionary, word))
	{
		vector<string> translation;
		boost::split(translation, word, boost::is_any_of(delim));
		myFirstMap.emplace(word, word);
	}
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: miniDictionary.exe <dictionary file>\n";
		return EXIT_FAILURE;
	}
	ifstream dictionary(argv[1]);

	map <string, string> myFirstMap;

	ReadDictionary(dictionary, myFirstMap);


	return EXIT_SUCCESS;
}

