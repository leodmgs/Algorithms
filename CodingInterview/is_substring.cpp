#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

// Solution: O(n^2)
// bool is_substring(string &s1, string &s2)
// {
// 	if (s1.size() != s2.size()) return false;
// 	if (s1 == s2) return true;

// 	int i = 0, n = s1.size();
// 	char c;
// 	while (i < s1.size())
// 	{
// 		if (s1 == s2)
// 			return true;
// 		c = s2[0];
// 		s2.erase(0,1);
// 		s2 += c;
// 	}
// 	return false;
// }


bool is_substring(string &A, string &B)
{
	if (A.size() != B.size()) return false;
	if (A == B) return true;	
	A += A;
	int n = A.size();
	int i = 0, j = 0;
	bool found = false;
	while (i < n)
	{
		j = 0;
		found = true;
		while (j < B.size())
		{
			if (A[i+j] != B[j])
			{
				found = false;
				break;
			}
			++j;
		}
		if (found) return true;
		++i;
	}
	return false;
}


int main()
{
	// string s1 = "aabbaabbaa";
	// string s2 = "abbaaaabba";

	string s1 = "abcde";
	string s2 = "abcdea";
	
	bool ans = is_substring(s1, s2);
	printf(ans ? "True\n" : "False\n");
	return 0;
}