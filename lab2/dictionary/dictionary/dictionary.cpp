#include "stdafx.h"
#include "dictionary.h"

#include "communicationWithUser.h"

using namespace std;

Dictionary GetDictionaryFromFile(std::ifstream &dictionaryFile)
{
	string word;
	Dictionary dictionary = {};
	while (getline(dictionaryFile, word))
	{
		vector<string> translationWord;
		boost::split(translationWord, word, boost::is_any_of(SEPARATE));
		if (translationWord.size() != 0)
		{
			boost::algorithm::to_lower(translationWord[0]);
			dictionary.emplace(translationWord[0], translationWord[1]);
		}
	}
	dictionaryFile.close();
	return dictionary;
}

void StorageChanges(Dictionary & dictionary, const std::string &nameFile)
{
	ofstream dictionaryFileOutput(nameFile);

	for (auto it : dictionary)
	{
		dictionaryFileOutput << it.first << SEPARATE << it.second << endl;
	}
	dictionaryFileOutput.close();
}


bool FoundTransfer(Dictionary & dictionary, const string &key)
{
	bool isFound = false;
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		boost::algorithm::to_lower(it->second);
		if (it->second == key)
		{
			cout << it->first << endl;
			isFound = true;
		}
	}
	return isFound;
}

bool IsValidNumArguments(int argc)
{
	bool success = true;
	if (argc != ARGUMENTS_COUNT)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: dictionary.exe <dictionary file>\n";
		success = false;
	}
	return success;
}

void AddNewWord(Dictionary &dictionary, const string & value, const string & key)
{
	dictionary.emplace(key, value);
}


bool FoundWord(Dictionary &dictionary, string & key)
{
	boost::algorithm::to_lower(key);
	auto it = dictionary.find(key);
	bool isFound = false;
	if (it != dictionary.end())
	{
		cout << it->second << endl;
		isFound = true;
	}
	return isFound;
}

void  GetTranslation(Dictionary &dictionary, bool & wasNewWord, string & key)
{
	if (!FoundWord(dictionary, key))
	{
		if (!FoundTransfer(dictionary, key))
		{
			cout << "Неизвестное слово \"" << key << "\". Введите перевод или пустую строку для отказа." << endl;
			AskedToSave(dictionary, wasNewWord, key);
		}
	}
}

void ProcessTranslation(const std::string &nameFile, Dictionary &dictionary)
{
	bool wasNewWord = false;
	string  key = OUT_OF_DIALOGUE;

	do
	{
		cout << "> ";
		getline(cin, key);
		
		if (key == OUT_OF_DIALOGUE)
		{
			break;
		}
		GetTranslation(dictionary, wasNewWord, key);
		
	} 
	while (true);

	if (wasNewWord)
	{

		ProcessExit(dictionary, nameFile);

	}
}