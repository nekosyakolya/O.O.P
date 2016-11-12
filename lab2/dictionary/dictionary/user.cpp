#include "stdafx.h"
#include "communicationWithUser.h"
#include "dictionary.h"

using namespace std;

void ProcessExit(Dictionary & dictionary, const std::string &nameFile)
{
	wcout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
	wcout << L"> ";
	wstring value = L"";
	getline(wcin, value);
	if (value == L"Y" || value == L"y")
	{
		StorageChanges(dictionary, nameFile);
		wcout << "��������� ���������.�� ��������.\n";
	}
}

void AskedToSave(Dictionary &dictionary, bool & wasNewWord, const wstring & key)
{
	wstring value = L"";
	wcout << L"> ";
	getline(wcin, value);
	if (value.empty())
	{
		wcout << "����� \"" << key << "\" ���������������.\n";
	}
	else
	{
		wcout << "����� \"" << key << "\" ��������� � ������� ��� \"" << value << "\".\n";
		dictionary.emplace(key, value);
        
		AddNewWord(dictionary, value, key);
		wasNewWord = true;
	}
}


void ProcessTranslation(const std::string &nameFile, Dictionary &dictionary)
{
	bool wasNewWord = false;
	wstring  key = OUT_OF_DIALOGUE;

	do
	{
		wcout << L"> ";
		getline(wcin, key);

		if (key == OUT_OF_DIALOGUE)
		{
			break;
		}
		GetTranslation(dictionary, wasNewWord, key);

	} while (true);

	if (wasNewWord)
	{

		ProcessExit(dictionary, nameFile);

	}
}