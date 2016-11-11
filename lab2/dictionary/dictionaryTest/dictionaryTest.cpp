#include "stdafx.h"
#include "../dictionary/dictionary.h"


using namespace std;
 
BOOST_AUTO_TEST_SUITE(ProcessDictionaryTest)
	BOOST_AUTO_TEST_CASE(search_russian_word)
	{
	    Dictionary dictionary =
		{ 
			{"cat", "кошка"}, 
			{"dog", "собака"}, 
			{"summer", "лето"} 
		};
		string key = "кошка";
		BOOST_CHECK(FoundTransfer(dictionary, key));
	}
	BOOST_AUTO_TEST_CASE(search_english_word)
	{
		Dictionary dictionary =
		{
			{ "cat", "кошка" },
			{ "dog", "собака" },
			{ "summer", "лето" }
		};
		string key = "CaT";
		BOOST_CHECK(FoundWord(dictionary, key));
	}

	BOOST_AUTO_TEST_CASE(get_dictionary_from_file)
	{
		ifstream dictionaryFile("dictionary.txt");
		Dictionary dictionary =
		{
			{ "cat", "кошка" },
			{ "the red square", "Красная площадь" }
		};
		Dictionary receivedDictionary = GetDictionaryFromFile(dictionaryFile);
		BOOST_CHECK(dictionary == receivedDictionary);
	}

	BOOST_AUTO_TEST_CASE(get_dictionary_from_empty_file)
	{
		ifstream dictionaryFile("empty.txt");
		Dictionary dictionary = {};
		Dictionary receivedDictionary = GetDictionaryFromFile(dictionaryFile);
		BOOST_CHECK(dictionary == receivedDictionary);
	}

BOOST_AUTO_TEST_SUITE_END()