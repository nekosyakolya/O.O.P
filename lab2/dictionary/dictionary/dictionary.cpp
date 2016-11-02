#include "stdafx.h"
#include "dictionary.h"


using namespace std;

void ReadDictionary(ifstream &dictionary, map<string, string> & myFirstMap)
{

	string word;
	while (getline(dictionary, word))
	{
		vector<string> translationWord;
		boost::split(translationWord, word, boost::is_any_of(delim));
		if (translationWord.size() != 0)
		{
			boost::algorithm::to_lower(translationWord[0]);
			myFirstMap.emplace(translationWord[0], translationWord[1]);
		}
	}
}

