#include <cstdio>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

char to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

bool isPalindrome(string s)
{	
	string alpha;
	for (char c: s) {
		c = to_lowercase(c);
		if ((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
			alpha += c;
	}
	int n = alpha.size();
	if (n < 2)
		return true;
	int i = 0;
	int j = n-1;
	while (i < j)
	{
		if (alpha[i] != alpha[j])
			return false;
		++i;
		--j;
	}
	return true;
}

int main()
{
	vector<string> tests;
	tests.push_back("A man, a plan, a canal: Panama");
	tests.push_back("Eva, can I see bees in a cave?");
	tests.push_back("No lemon, no melon");
	tests.push_back("Was it a cat I saw?");
	tests.push_back("Red rum, sir, is murder");
	tests.push_back("Step on no pets");
	tests.push_back("0011221100");
	bool ans = false;
	for (string &str: tests) {
		ans = isPalindrome(str);
		printf(ans ? "true\n" : "false\n");
	}
	return 0;
}
