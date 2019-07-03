#include <vector>
#include <string>
#include <stack>

using namespace std;

int calPoints(vector<string>& ops)
{
	stack<int> rounds;
	for (int i=0; i<ops.size(); ++i)
	{
		if (ops[i] == "C")
		{
			rounds.pop();
		}
		else if (ops[i] == "D")
		{
			int aux = rounds.top();
			rounds.push(2*aux);
		}
		else if (ops[i] == "+")
		{
			int aux1 = rounds.top();
			rounds.pop();
			int aux2 = rounds.top();
			rounds.pop();
			rounds.push(aux2);
			rounds.push(aux1);
			rounds.push(aux2 + aux1);
		}
		else 
		{
			rounds.push(stoi(ops[i]));
		}
	}
	int score = 0;
	while (!rounds.empty())
	{
		score += rounds.top();
		rounds.pop();
	}
	return score;
}

int main()
{
	// string sv [] = {"5","2","C","D","+"}; // 30
	// string sv [] = {"5","-2","4","C","D","9","+","+"}; // 27
	string sv [] = {"36","28","70","65","C","+","33","-46","84","C"}; // 219
	// string sv [] = {"1","2","3","4"};
	vector<string> v(sv, sv + sizeof(sv)/sizeof(sv[0]));
	int ans = calPoints(v);
	printf("%d\n", ans);
	return 0;
}
