// FindMaxEx.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>


template <typename T>
bool Less(const T &a, const T &b)
{
	return a < b;
}

template <typename T, typename Less = std::less<T>>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less = Less())
{

	if (arr.empty())
	{
		return false;
	}

	auto result = arr.begin();
	for (auto it = result + 1; it < arr.end(); ++it)
	{
		if (less(*result, *it))
		{
			result = it;
		}
	}

	maxValue = *result;
	return true;
}

int main()
{
	int maxValue = 0;
	std::vector<int> arr = { 1 };
	FindMax(arr, maxValue);
	std::cout << maxValue << std::endl;

	std::string value = "";
	std::vector<std::string> arrS = { "olga", "sveta" , "nina" };
	FindMax(arrS, value);
	std::cout << value << std::endl;

	std::vector<int> ex = {};
	FindMax(ex, maxValue);
	std::cout << maxValue << std::endl;

	return 0;
}

