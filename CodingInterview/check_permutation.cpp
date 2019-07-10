#include <cstdio>
#include <unordered_map>
#include <string>

using namespace std;

/*
	The algorith below is divided in 3 steps:
	1. Loop through the first string and store each one into the map,
		incresing the value number if it's necessary.
	2. Loop through the second string and check if the map has it. If
		it doesn't exist, just return false, decrease the value otherwise.
	3. Loop the map. If any position isn't equal to 0 (zero), return false.
 */
bool check_permutation(string& s1, string& s2)
{
	unordered_map<char,int> char_map;
	for (char& c: s1)
	{
		if (char_map.find(c) == char_map.end()) 
			char_map[c] = 1;
		else
			++char_map[c];
	}
	for (char& c: s2)
	{
		if (char_map.find(c) == char_map.end())
			return false;
		else
			--char_map[c];
	}
	for (auto it: char_map)
		if (it.second != 0)
			return false;
	return true;
}

int main()
{
	string s1 = "456.abcdef";
	string s2 = "edf456cba.";
	bool ans = check_permutation(s1, s2);
	printf(ans ? "True\n" : "False\n");
	return 0;
}