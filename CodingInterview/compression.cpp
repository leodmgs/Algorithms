#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Solution: O(n + k^2)
// string compress(string str)
// {
// 	string strc = "";
// 	char ch = str[0];
// 	int ct = 1, i = 1, n = str.size();
// 	while (i <= n)
// 	{
// 		if (str[i] == ch) 
// 			++ct;
// 		else
// 		{
// 			strc += ch + to_string(ct);
// 			ch = str[i];
// 			ct = 1;
// 		}
// 		++i;
// 	}
// 	return strc.size() < n ? strc : str;
// }

// Solution: O(n/2 + k^2)
// string compress(string str)
// {
// 	int n = str.size();
// 	int i = 1, j = n-2;
// 	char ci = str[0], cj = str[n-1];
// 	int sqi = 1, sqj = 1;
// 	string sti = "", stj = "";
// 	while (i <= j)
// 	{
// 		if (str[i] != ci)
// 		{
// 			sti += ci + to_string(sqi);
// 			ci = str[i];
// 			sqi = 1;
// 		}
// 		else
// 			++sqi;

// 		if (str[j] != cj)
// 		{
// 			stj = cj + to_string(sqj) + stj;
// 			cj = str[j];
// 			sqj = 1;
// 		}
// 		else
// 			++sqj;
// 		++i;
// 		--j;
// 	}
// 	if (ci == cj)
// 		sti += ci + to_string(sqi + sqj - 1);

// 	sti += stj;
// 	return sti.size() < n ? sti : str;
// }

// Solution: O(n)
string compress(string str)
{
	stringstream ss;
	char ch = str[0];
	int ct = 1, i = 1, n = str.size();
	while (i <= n)
	{
		if (str[i] == ch) 
			++ct;
		else
		{
			ss << ch << to_string(ct);
			ch = str[i];
			ct = 1;
		}
		++i;
	}
	return ss.str().size() < n ? ss.str() : str;
}

int main()
{
	// string s = "aaabbeedd"; // a3b2e2d2
	string s = "aaabccc"; // a3b1c3
	string ans = compress(s);
	printf("%s\n", ans.c_str());
	return 0;
}