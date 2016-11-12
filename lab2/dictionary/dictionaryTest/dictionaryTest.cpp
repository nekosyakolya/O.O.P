#include "stdafx.h"
#include "../dictionary/dictionary.h"
#include "../dictionary/const.h"
#include "../dictionary/communicationWithUser.h"

using namespace std;
 
BOOST_AUTO_TEST_SUITE(ProcessDictionaryTest)
	BOOST_AUTO_TEST_CASE(search_russian_word)
	{
	    Dictionary dictionary =
		{ 
			{L"cat", L"кошка"}, 
			{L"dog", L"собака"}, 
			{L"summer", L"лето"} 
		};
		wstring key = L"кошка";
		BOOST_CHECK(FoundTransfer(dictionary, key));
	}
	BOOST_AUTO_TEST_CASE(search_english_word)
	{
		Dictionary dictionary =
		{
			{ L"cat", L"кошка" },
			{ L"dog", L"собака" },
			{ L"summer", L"лето" }
		};
		wstring key = L"CaT";
		BOOST_CHECK(FoundWord(dictionary, key));
	}

	
	BOOST_AUTO_TEST_CASE(get_dictionary_from_empty_file)
	{
		wifstream dictionaryFile("empty.txt");
		Dictionary dictionary = {};
		Dictionary receivedDictionary = GetDictionaryFromFile(dictionaryFile);
		BOOST_CHECK(dictionary == receivedDictionary);
	}

	BOOST_AUTO_TEST_CASE(get_dictionary_from_file)
	{
		wifstream dictionaryFile("dictionary.txt");
		Dictionary dictionary =
		{
			{ boost::lexical_cast<std::wstring>("cat"), boost::lexical_cast<std::wstring>("кошка") }
		};
		Dictionary receivedDictionary = GetDictionaryFromFile(dictionaryFile);
		BOOST_CHECK(dictionary == receivedDictionary);
	}

BOOST_AUTO_TEST_SUITE_END()