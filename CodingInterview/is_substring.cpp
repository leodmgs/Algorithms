#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

bool is_substring(string &s1, string &s2)
{
	if (s1.size() != s2.size())
		return false;

	int i = 0, n = s1.size();
	char c;
	while (i < s1.size())
	{
		if (s1 == s2)
			return true;
		c = s2[0];
		s2.erase(0,1);
		s2 += c;
	}
	return false;
}

int main()
{
	string s1 = "aabbaabbaa";
	string s2 = "abbaaaabba";
	
	bool ans = is_substring(s1, s2);
	printf(ans ? "True\n" : "False\n");
	return 0;
}