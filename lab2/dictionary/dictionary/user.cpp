#include "stdafx.h"
#include "communicationWithUser.h"
#include "dictionary.h"

using namespace std;

void ProcessExit(Dictionary & dictionary, const std::string &nameFile)
{
	cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
	cout << "> ";
	string value = "";
	getline(cin, value);
	if (value == "Y" || value == "y")
	{
		StorageChanges(dictionary, nameFile);
		cout << "Изменения сохранены.До свидания." << endl;
	}
}

void AskedToSave(Dictionary &dictionary, bool & wasNewWord, const string & key)
{
	string value = "";
	cout << "> ";
	getline(cin, value);
	if (value.empty())
	{
		cout << "Слово \"" << key << "\" проигнорировано." << endl;
	}
	else
	{
		cout << "Слово \"" << key << "\" сохранено в словаре как \"" << value << "\"." << endl;
		dictionary.emplace(key, value);
        
		AddNewWord(dictionary, value, key);
		wasNewWord = true;
	}
}