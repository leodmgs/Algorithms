#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

bool palindrome_permutation(string str)
{
	unordered_map<char,int> m;
	for (char &c: str)
		if (c != ' ')
			m.find(tolower(c)) == m.end() ? m[tolower(c)] = 1 : ++m[tolower(c)];
	
	bool has_midd = false;
	for (auto &it: m)
	{
		if (it.second % 2 != 0)
		{
			if (!has_midd and it.second == 1)
				has_midd = true;
			else
				return false;
		}
	}
	return true;
}

int main()
{
	string url = "Asdf Ddsafd Kgk!!";
	bool ans = palindrome_permutation(url);
	printf(ans ? "True\n" : "False\n");
	return 0;
}