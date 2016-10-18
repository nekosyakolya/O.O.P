#include "decode.h"
#include "stdafx.h"

using namespace std;

string ReplaceString(string &strInFile, const string &searchStr, const string &replaceStr)
{
	string newStr = "";
	size_t positionOfBeginString = 0;
	size_t positionOfMatchedString = strInFile.find(searchStr);

	while ((positionOfMatchedString != string::npos) && !(searchStr == replaceStr))
	{
		newStr += strInFile.substr(positionOfBeginString, positionOfMatchedString - positionOfBeginString);
		newStr += replaceStr;
		positionOfBeginString = positionOfMatchedString + searchStr.length();
		positionOfMatchedString = strInFile.find(searchStr, positionOfMatchedString + searchStr.length());
	}

	return newStr += strInFile.substr(positionOfBeginString);
}


string HtmlDecode(string & htmlString)
{
	map <string, string> mapDecode = { { "&quot;", "\"" },
	{ "&apos;", "'" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" } };

	for (auto i = mapDecode.begin(); i != mapDecode.end(); ++i)
	{
		htmlString = ReplaceString(htmlString, i->first, i->second);
	}
	return htmlString;
}