#include "stdafx.h"
#include "communicationWithUser.h"
#include "dictionary.h"

using namespace std;

void ProcessExit(Dictionary & dictionary, const std::string &nameFile)
{
	cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������." << endl;
	cout << "> ";
	string value = "";
	getline(cin, value);
	if (value == "Y" || value == "y")
	{
		StorageChanges(dictionary, nameFile);
		cout << "��������� ���������.�� ��������." << endl;
	}
}

void AskedToSave(Dictionary &dictionary, bool & wasNewWord, const string & key)
{
	string value = "";
	cout << "> ";
	getline(cin, value);
	if (value.empty())
	{
		cout << "����� \"" << key << "\" ���������������." << endl;
	}
	else
	{
		cout << "����� \"" << key << "\" ��������� � ������� ��� \"" << value << "\"." << endl;
		dictionary.emplace(key, value);
        
		AddNewWord(dictionary, value, key);
		wasNewWord = true;
	}
}