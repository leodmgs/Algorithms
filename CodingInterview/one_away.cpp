#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

// Solution using a hash map.
// bool one_away(string s1, string s2)
// {
// 	int s = s1.size() - s2.size();
// 	if ( abs(s) > 1 )
// 		return false;
// 	unordered_map<char,int> ms1;
// 	for (char &c: s1)
// 		ms1.find(c) == ms1.end() ? ms1[c] = 1 : ++ms1[c];

// 	for (char &c: s2)
// 		ms1.find(c) == ms1.end() ? ms1[c] = 1 : --ms1[c];
	
// 	int d = 0;
// 	for (auto &it: ms1)
// 		d += it.second;
// 	return d > 2 ? false : true;
// }

// Solution in a single pass.
bool one_away(string s1, string s2)
{
	int s = s1.size() - s2.size();
	if ( abs(s) > 1 )
		return false;

	int i = 0, j = 0, d = 0;
	while (i < s1.size())
	{
		if (s1[i] != s2[j])
		{
			++d;
			if ( d > 1) return false;
			if (s1[i+1] == s2[j]) { ++i; }
			else if (s1[i] == s2[j+1]) { ++j; }
			else if (s1[i+1] == s2[j+1]) { ++i; ++j; }
			else {  return false; }
		}
		else
		{
			++i;
			++j;
		}
	}
	return true;
}

int main()
{
	string str1 = "pale";
	string str2 = "ple";
	bool ans = one_away(str1, str2);
	printf(ans ? "True\n" : "False\n");
	return 0;
}