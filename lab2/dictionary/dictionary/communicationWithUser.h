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
#include <locale>
#include <functional>
#include "const.h"



using  Dictionary = std::map<std::wstring, std::wstring>;

void ProcessExit(Dictionary & , const std::string &);

void AskedToSave(Dictionary &, bool & , const std::wstring & );

void ProcessTranslation(const std::string &, Dictionary &);