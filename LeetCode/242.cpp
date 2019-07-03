#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) 
{
	if (s.size() != t.size()) 
		return false;
	unordered_map<char,int> anagram_map;
	for (int i=0; i<s.size(); ++i)
		if (anagram_map.find(s[i]) == anagram_map.end())
			anagram_map[s[i]] = 1;
		else
			++anagram_map[s[i]];
	for (int j=0; j<t.size(); ++j)
		if (anagram_map.find(t[j]) == anagram_map.end())
			return false;
		else
			--anagram_map[t[j]];
	for (auto it=anagram_map.begin(); it!=anagram_map.end(); ++it) 
		if (it->second > 0)
			return false;
	return true;
}

int main()
{
	string s = "anagram";
	string t = "armgarn";
	bool ans = isAnagram(s, t);
	printf(ans ? "true\n" : "false\n");
	return 0;
}