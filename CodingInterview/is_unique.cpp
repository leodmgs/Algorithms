#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// Naive solution: O(n^2)
// bool isUnique(string& s)
// {
// 	int n = s.size();
// 	for (int i = 0; i < n; ++i)
// 		for (int j = i+1; j < n; ++j)
// 			if (s[i] == s[j])
// 				return false;
// 	return true;
// }

// Linear solution: O(n)
bool isUnique(string& s)
{
	/* 
		All characters in ASCII table is from 0 to 127 (n = 128).
		In this case, if any position of the vector has more than
		1, it means the string isn't unique, otherwise, if it only
		has 0 or 1 in any position it is unique.
	*/
	int n = 128;
	vector<int> ascii(n, 0);
	for (int i = 0; i < s.size(); ++i)
	{
		int p = s[i];
		if (p > 0 and p < n)
		{
			if (ascii[p] == 0)
				++ascii[p];
			else
				return false;
		}
	}
	return true;
}

int main()
{
	string str = "abcd123%ˆ&zx";
	bool ans = isUnique(str);
	printf(ans ? "True\n" : "False\n");
	return 0;
}