#include <cstdio>
#include <string>

using namespace std;

string urlify(string url)
{
	int last = 0, spaces = 0;
	for (int i = 0; i < url.size() ; ++i)
		url[i] == ' ' ? ++spaces : last = i;
	string urlf = "";
	for (int j = 0; j < last+1; ++j) 
	{
		if (url[j] == ' ' and spaces > 0) 
		{
			urlf += "%20";
			--spaces;
		}
		else 
		{
			urlf += url[j];
		}
	}
	return urlf;
}

int main()
{
	string url = "abc de fghi j lm.       ";
	string ans = urlify(url);
	printf("%s\n", ans.c_str());
	return 0;
}