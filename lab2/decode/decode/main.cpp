#include "decode.h"

using namespace std;

int main()
{
	string htmlString;
	while (getline(cin, htmlString))
	{
		htmlString = HtmlDecode(htmlString);
		cout << htmlString << endl;
	}
	return EXIT_SUCCESS;
}
