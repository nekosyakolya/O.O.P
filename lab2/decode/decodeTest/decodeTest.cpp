#include "stdafx.h"

#include "../decode/decode.h"

using namespace std;

bool StringsAreEqual(string const& x, string const& y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(ProcessDecodeTest)
	BOOST_AUTO_TEST_CASE(string_no_change)
	{
	    string str = "Cat";
		str = HtmlDecode(str);
		BOOST_CHECK(StringsAreEqual(str, "Cat"));
	}

	BOOST_AUTO_TEST_CASE(string_with_all_symbols)
	{
		string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
		str = HtmlDecode(str);
		BOOST_CHECK(StringsAreEqual(str, "Cat <says> \"Meow\". M&M's"));
	}

	BOOST_AUTO_TEST_CASE(string_empty)
	{
		string str = "";
		str = HtmlDecode(str);
		BOOST_CHECK(StringsAreEqual(str, ""));
	}

	BOOST_AUTO_TEST_CASE(string_repeated_symbol)
	{
		string str = "atom &lt;&lt; human";
		str = HtmlDecode(str);
		BOOST_CHECK(StringsAreEqual(str, "atom << human"));
	}
BOOST_AUTO_TEST_SUITE_END()
