#include <cstdio>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
	if (s.size() == 0) return true;
	stack<char> b;
	b.push(s[0]);
	for (int i=1; i<s.size(); ++i)
	{
		if (b.empty()) {
			b.push(s[i]);
			continue;
		}
		if (b.top() == '{' && s[i] == '}')
			b.pop();
		else if (b.top() == '(' && s[i] == ')')
			b.pop();
		else if (b.top() == '[' && s[i] == ']')
			b.pop();
		else
			b.push(s[i]);
	}
	return b.empty() ? true : false;
}

int main()
{
	string input_str = "{[({[({[({[(])})]})]})]}";
	bool ans = isValid(input_str);
	ans ? printf("true\n") : printf("false\n");
	return 0;
}