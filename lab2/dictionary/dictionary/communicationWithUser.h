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

/*
Разбить на два логических модуля:
* Словарь - предоставляет бизнес-логику (сохранение, загрузка, добавление/получение перевода)
* Контроллер - общение с пользователем, управление словарем
*/


using  Dictionary = std::map<std::string, std::string>;

void ProcessExit(Dictionary & dictionary, const std::string &nameFile);

void AskedToSave(Dictionary &dictionary, bool & wasNewWord, const std::string & key);