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

	BOOST_AUTO_TEST_CASE(string_change)
	{
		string str = "Cat &lt;says&gt; M&amp;M&apos;s";
		str = HtmlDecode(str);
		BOOST_CHECK(StringsAreEqual(str, "Cat <says> M&M's"));
	}
BOOST_AUTO_TEST_SUITE_END()
