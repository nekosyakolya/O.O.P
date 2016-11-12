#pragma once
#include <boost/algorithm/string.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string> 
#include <Windows.h>
#include "const.h"
#include <locale>
#include <functional>

using  Dictionary = std::map<std::wstring, std::wstring>;

Dictionary GetDictionaryFromFile(std::wifstream &);

bool FoundTransfer(Dictionary &, const std::wstring &);

bool IsValidNumArguments(int argc);

void StorageChanges(Dictionary &, const std::string &);
bool FoundWord(Dictionary &, std::wstring &);

void AddNewWord(Dictionary &, const std::wstring &, const std::wstring &);
void  GetTranslation(Dictionary &, bool & , std::wstring &);