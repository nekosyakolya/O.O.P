#include "decode.h"
#include "stdafx.h"

using namespace std;

string ReplaceString(string const& strInFile, const string &searchStr, const string &replaceStr)
{
	string newStr = "";
	size_t beginPosition = 0;
	size_t matchEndPosition = strInFile.find(searchStr);

	while (matchEndPosition != string::npos)
	{
		newStr += strInFile.substr(beginPosition, matchEndPosition - beginPosition);
		newStr += replaceStr;
		beginPosition = matchEndPosition + searchStr.length();
		matchEndPosition = strInFile.find(searchStr, matchEndPosition + searchStr.length());
	}

	return newStr += strInFile.substr(beginPosition);
}


// const& arg
string HtmlDecode(string & htmlString)
{
	map <string, string> decodeMap = { { "&quot;", "\"" },
	{ "&apos;", "'" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" } };

	for (auto i = decodeMap.begin(); i != decodeMap.end(); ++i)
	{
		htmlString = ReplaceString(htmlString, i->first, i->second);
	}
	return htmlString;
}