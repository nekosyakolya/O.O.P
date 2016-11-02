#include "stdafx.h"
#include "dictionary.h"

using namespace std;

int main(int argc, char * argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: dictionary.exe <dictionary file>\n";
		return EXIT_FAILURE;
	}
	ifstream dictionary(argv[1]);

	map <string, string> myFirstMap;

	ReadDictionary(dictionary, myFirstMap);
	return EXIT_SUCCESS;
}

