#include "stdafx.h"
#include "dictionary.h"

#include "communicationWithUser.h"

using namespace std;

Dictionary GetDictionaryFromFile(std::wifstream &dictionaryFile)
{
	wstring word;
	Dictionary dictionary = {};
	while (getline(dictionaryFile, word))
	{
		vector<wstring> translationWord;
		boost::split(translationWord, word, boost::is_any_of(SEPARATE));
		if (translationWord.size() != 0)
		{
			transform(translationWord[0].begin(), translationWord[0].end(), translationWord[0].begin(), tolower);
			dictionary.emplace(translationWord[0], translationWord[1]);
		}
	}
	dictionaryFile.close();
	return dictionary;
}

void StorageChanges(Dictionary & dictionary, const std::string &nameFile)
{
	wofstream dictionaryFileOutput(nameFile);

	for (auto it : dictionary)
	{
		dictionaryFileOutput << it.first << SEPARATE << it.second << "\n";
	}
	dictionaryFileOutput.close();
}


bool FoundTransfer(Dictionary & dictionary, const wstring &key)
{
	bool isFound = false;
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		transform(it->second.begin(), it->second.end(), it->second.begin(), tolower);
		if (it->second == key)
		{
			wcout << it->first << "\n";
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
		wcout << L"Invalid arguments count\n"
			<< L"Usage: dictionary.exe <dictionary file>\n";
		success = false;
	}
	return success;
}

void AddNewWord(Dictionary &dictionary, const wstring & value, const wstring & key)
{
	dictionary.emplace(key, value);
}


bool FoundWord(Dictionary &dictionary, wstring & key)
{
	transform(key.begin(), key.end(), key.begin(), tolower);
	auto it = dictionary.find(key);
	bool isFound = false;
	if (it != dictionary.end())
	{
		wcout << it->second << "\n";
		isFound = true;
	}
	return isFound;
}

void  GetTranslation(Dictionary &dictionary, bool & wasNewWord, wstring & key)
{
	if (!FoundWord(dictionary, key))
	{
		if (!FoundTransfer(dictionary, key))
		{
			wcout << "Неизвестное слово \"" << key << "\". Введите перевод или пустую строку для отказа.\n";
			AskedToSave(dictionary, wasNewWord, key);
		}
	}
}
