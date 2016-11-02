#pragma once
#include <boost/algorithm/string.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <Windows.h>

static const std::string delim = "=";

void ReadDictionary(std::ifstream &dictionary, std::map<std::string, std::string> & myFirstMap);